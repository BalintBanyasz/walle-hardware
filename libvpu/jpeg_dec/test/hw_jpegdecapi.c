#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "log.h"
#include <sys/timeb.h>

#include "jpegdecapi.h"
#include "dwl.h"
#include "jpegdeccontainer.h"

#include "deccfg.h"
#include "regdrv.h"

#include "hw_jpegdecapi.h"

#define DEFAULT -1
#define JPEG_INPUT_BUFFER 0x5120

#define PP_IN_FORMAT_YUV422INTERLAVE            0
#define PP_IN_FORMAT_YUV420SEMI                 1
#define PP_IN_FORMAT_YUV420PLANAR               2
#define PP_IN_FORMAT_YUV400                     3
#define PP_IN_FORMAT_YUV422SEMI                 4
#define PP_IN_FORMAT_YUV420SEMITIELED           5
#define PP_IN_FORMAT_YUV440SEMI                 6
#define PP_IN_FORMAT_YUV444_SEMI                7
#define PP_IN_FORMAT_YUV411_SEMI                8

#define PP_OUT_FORMAT_RGB565                    0
#define PP_OUT_FORMAT_ARGB                      1
#define PP_OUT_FORMAT_YUV422INTERLAVE           3   
#define PP_OUT_FORMAT_YUV420INTERLAVE           5
#ifdef AVS40
#undef ALOGV
#define ALOGV LOGV

#undef ALOGD
#define ALOGD LOGD

#undef ALOGI
#define ALOGI LOGI

#undef ALOGW
#define ALOGW LOGW

#undef ALOGE
#define ALOGE LOGE

#endif



/* stream start address */
RK_U8 *byteStrmStart;

/* user allocated output */
VPUMemLinear_t userAllocLuma;
VPUMemLinear_t userAllocChroma;
VPUMemLinear_t userAllocCr;

/* progressive parameters */
static RK_U32 scanCounter = 0;
static RK_U32 progressive = 0;
static RK_U32 scanReady = 0;
static RK_U32 is8170HW = 0;


RK_U32 planarOutput = 0;
RK_U32 bFrames = 0;

static RK_U32 gHwVer;


static RK_U32 crop = 0;

#define LocalPrint ALOGI
//#define LocalPrint(...)

unsigned int LocalGetSystemTime(void)
{
  	struct timeb timeVal;
 	ftime( &timeVal );
 	return timeVal.time*1000 + timeVal.millitm;
}
/*-----------------------------------------------------------------------------

Print JPEG api return value

-----------------------------------------------------------------------------*/
void PrintRet(JpegDecRet * pJpegRet)
{

    assert(pJpegRet);

    switch (*pJpegRet)
    {
    case JPEGDEC_FRAME_READY:
        //LocalPrint(("TB: jpeg API returned : JPEGDEC_FRAME_READY\n"));
        break;
    case JPEGDEC_OK:
        LocalPrint(("TB: jpeg API returned : JPEGDEC_OK\n"));
        break;
    case JPEGDEC_ERROR:
        LocalPrint(("TB: jpeg API returned : JPEGDEC_ERROR\n"));
        break;
    case JPEGDEC_DWL_HW_TIMEOUT:
        LocalPrint(( "TB: jpeg API returned : JPEGDEC_HW_TIMEOUT\n"));
        break;
    case JPEGDEC_UNSUPPORTED:
        LocalPrint(("TB: jpeg API returned : JPEGDEC_UNSUPPORTED\n"));
        break;
    case JPEGDEC_PARAM_ERROR:
        LocalPrint(("TB: jpeg API returned : JPEGDEC_PARAM_ERROR\n"));
        break;
    case JPEGDEC_MEMFAIL:
        LocalPrint(( "TB: jpeg API returned : JPEGDEC_MEMFAIL\n"));
        break;
    case JPEGDEC_INITFAIL:
        LocalPrint(( "TB: jpeg API returned : JPEGDEC_INITFAIL\n"));
        break;
    case JPEGDEC_HW_BUS_ERROR:
        LocalPrint(("TB: jpeg API returned : JPEGDEC_HW_BUS_ERROR\n"));
        break;
    case JPEGDEC_SYSTEM_ERROR:
        LocalPrint(("TB: jpeg API returned : JPEGDEC_SYSTEM_ERROR\n"));
        break;
    case JPEGDEC_DWL_ERROR:
        LocalPrint(( "TB: jpeg API returned : JPEGDEC_DWL_ERROR\n"));
        break;
    case JPEGDEC_INVALID_STREAM_LENGTH:
        LocalPrint((
                "TB: jpeg API returned : JPEGDEC_INVALID_STREAM_LENGTH\n"));
        break;
    case JPEGDEC_STRM_ERROR:
        LocalPrint(( "TB: jpeg API returned : JPEGDEC_STRM_ERROR\n"));
        break;
    case JPEGDEC_INVALID_INPUT_BUFFER_SIZE:
        LocalPrint((
                "TB: jpeg API returned : JPEGDEC_INVALID_INPUT_BUFFER_SIZE\n"));
        break;
    case JPEGDEC_INCREASE_INPUT_BUFFER:
        LocalPrint((
                "TB: jpeg API returned : JPEGDEC_INCREASE_INPUT_BUFFER\n"));
        break;
    case JPEGDEC_SLICE_MODE_UNSUPPORTED:
        LocalPrint((
                "TB: jpeg API returned : JPEGDEC_SLICE_MODE_UNSUPPORTED\n"));
        break;
    default:
        LocalPrint(( "TB: jpeg API returned unknown status\n"));
        break;
    }
}

RK_U32 FindImageInfoEnd(RK_U8 * pStream, RK_U32 streamLength, RK_U32 * pOffset)
{
    RK_U32 i;

    for(i = 0; i < streamLength; ++i)
    {
        if(0xFF == pStream[i])
        {
            if(((i + 32) < streamLength) && 0xDA == pStream[i + 1])
            {
                *pOffset = i;
                return 0;
            }
        }
    }
    return 1;
}

int hw_jpeg_release(void *decInst)
{
	JpegDecContainer *jpegC;
	/* Release JPEG Decoder , Auto Release pp output memory,too*/
	if(!decInst)
		return 0;
	jpegC = (JpegDecContainer*)decInst;
	
	/*if(jpegC->ppOutMem.vir_addr)
	{
		//LocalPrint(("ppOutMem Free.\n"));
		VPUFreeLinear(&(jpegC->ppOutMem));
	}*/
	JpegDecRelease((JpegDecInst)decInst);
	return 0;
}


