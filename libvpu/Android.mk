LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

BUILD_INCLUDE_RMVB := false
LOCAL_SRC_FILES:=                         \
        vpu_api/src/vpu_api.cpp \
        vpu_api/src/vpu_api_private.cpp \
        
LOCAL_PRELINK_MODULE := false
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE:= librk_on2

LOCAL_C_INCLUDES := \
	$(LOCAL_PATH)/common \
 	$(LOCAL_PATH)/common/include \
	$(LOCAL_PATH)/vpu_api/include \
	$(TOP)/frameworks/av/media/libstagefright/include \
	$(LOCAL_PATH)/post_process/deinterlace/include \
	$(TOP)/frameworks/native/include/media/openmax \
        $(TOP)/hardware/rk29/libon2 \

ifeq ($(PLATFORM_VERSION),4.0.4)
	LOCAL_CFLAGS := -DAVS40
endif
ifeq ($(BUILD_INCLUDE_RMVB),true)
    LOCAL_CFLAGS += \
			 -DHAVE_RMVB
endif

LOCAL_SHARED_LIBRARIES := \
	libvpu \
	libcutils \
	libdl	\
	liblog    \
 	
LOCAL_STATIC_LIBRARIES := \
        libvpu_avcdec \
        libvpu_avcenc \
        libvpu_m4vdec \
        libon2mjpeghwdec  \
        libvpu_vp8dec \
	    libvpu_vp8enc \
	    libvpu_mjpegenc \
	    libpost_deinterlace
        
include $(BUILD_SHARED_LIBRARY)

include $(call all-makefiles-under,$(LOCAL_PATH))
