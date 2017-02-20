#ifndef _REG_H_
#define _REG_H_
/*****************************************************************************
	File:
		reg.h
	Description:
		rk register class
	Author:
		Jian Huan
		2010-12-8 16:43:41
******************************************************************************/
#include "vpu_macro.h"
#include "include/vpu_type.h"

typedef enum {
/* include script-generated part */
	HWIF_DEC_PIC_INF,
	HWIF_DEC_TIMEOUT,
	HWIF_DEC_SLICE_INT,
	HWIF_DEC_ERROR_INT,
	HWIF_DEC_ASO_INT,
	HWIF_DEC_BUFFER_INT,
	HWIF_DEC_BUS_INT,
	HWIF_DEC_RDY_INT,
	HWIF_DEC_IRQ,
	HWIF_DEC_IRQ_DIS,
	HWIF_DEC_E,
	HWIF_DEC_AXI_RD_ID,
	HWIF_DEC_TIMEOUT_E,
	HWIF_DEC_STRSWAP32_E,
	HWIF_DEC_STRENDIAN_E,
	HWIF_DEC_INSWAP32_E,
	HWIF_DEC_OUTSWAP32_E,
	HWIF_DEC_DATA_DISC_E,
	HWIF_TILED_MODE_MSB,
	HWIF_DEC_OUT_TILED_E,
	HWIF_DEC_LATENCY,
	HWIF_DEC_CLK_GATE_E,
	HWIF_DEC_IN_ENDIAN,
	HWIF_DEC_OUT_ENDIAN,
	HWIF_PRIORITY_MODE,
	HWIF_TILED_MODE_LSB,
	HWIF_DEC_ADV_PRE_DIS,
	HWIF_DEC_SCMD_DIS,
	HWIF_DEC_MAX_BURST,
	HWIF_DEC_MODE,
	HWIF_RLC_MODE_E,
	HWIF_SKIP_MODE,
	HWIF_PJPEG_E,
	HWIF_PIC_INTERLACE_E,
	HWIF_PIC_FIELDMODE_E,
	HWIF_PIC_B_E,
	HWIF_PIC_INTER_E,
	HWIF_PIC_TOPFIELD_E,
	HWIF_FWD_INTERLACE_E,
	HWIF_RESERVED0_E,
	HWIF_REF_TOPFIELD_E,
	HWIF_DEC_OUT_DIS,
	HWIF_FILTERING_DIS,
	HWIF_WEBP_E,
	HWIF_MVC_E,
	HWIF_PIC_FIXED_QUANT,
	HWIF_WRITE_MVS_E,
	HWIF_REFTOPFIRST_E,
	HWIF_SEQ_MBAFF_E,
	HWIF_PICORD_COUNT_E,
	HWIF_DEC_AHB_HLOCK_E,
	HWIF_DEC_AXI_WR_ID,
	HWIF_PIC_MB_WIDTH,
	HWIF_MB_WIDTH_OFF,
	HWIF_PIC_MB_HEIGHT_P,
	HWIF_MB_HEIGHT_OFF,
	HWIF_ALT_SCAN_E,
	HWIF_TOPFIELDFIRST_E,
	HWIF_REF_FRAMES,
	HWIF_PIC_MB_W_EXT,
	HWIF_PIC_MB_H_EXT,
	HWIF_PIC_REFER_FLAG,
	HWIF_STRM_START_BIT,
	HWIF_SYNC_MARKER_E,
	HWIF_TYPE1_QUANT_E,
	HWIF_CH_QP_OFFSET,
	HWIF_CH_QP_OFFSET2,
	HWIF_FIELDPIC_FLAG_E,
	HWIF_INTRADC_VLC_THR,
	HWIF_VOP_TIME_INCR,
	HWIF_DQ_PROFILE,
	HWIF_DQBI_LEVEL,
	HWIF_RANGE_RED_FRM_E,
	HWIF_FAST_UVMC_E,
	HWIF_TRANSDCTAB,
	HWIF_TRANSACFRM,
	HWIF_TRANSACFRM2,
	HWIF_MB_MODE_TAB,
	HWIF_MVTAB,
	HWIF_CBPTAB,
	HWIF_2MV_BLK_PAT_TAB,
	HWIF_4MV_BLK_PAT_TAB,
	HWIF_QSCALE_TYPE,
	HWIF_CON_MV_E,
	HWIF_INTRA_DC_PREC,
	HWIF_INTRA_VLC_TAB,
	HWIF_FRAME_PRED_DCT,
	HWIF_JPEG_QTABLES,
	HWIF_JPEG_MODE,
	HWIF_JPEG_FILRIGHT_E,
	HWIF_JPEG_STREAM_ALL,
	HWIF_CR_AC_VLCTABLE,
	HWIF_CB_AC_VLCTABLE,
	HWIF_CR_DC_VLCTABLE,
	HWIF_CB_DC_VLCTABLE,
	HWIF_CR_DC_VLCTABLE3,
	HWIF_CB_DC_VLCTABLE3,
	HWIF_STRM1_START_BIT,
	HWIF_HUFFMAN_E,
	HWIF_MULTISTREAM_E,
	HWIF_BOOLEAN_VALUE,
	HWIF_BOOLEAN_RANGE,
	HWIF_ALPHA_OFFSET,
	HWIF_BETA_OFFSET,
	HWIF_START_CODE_E,
	HWIF_INIT_QP,
	HWIF_CH_8PIX_ILEAV_E,
	HWIF_STREAM_LEN_EXT,
	HWIF_STREAM_LEN,
	HWIF_CABAC_E,
	HWIF_BLACKWHITE_E,
	HWIF_DIR_8X8_INFER_E,
	HWIF_WEIGHT_PRED_E,
	HWIF_WEIGHT_BIPR_IDC,
	HWIF_H264_H_EXT,
	HWIF_FRAMENUM_LEN,
	HWIF_FRAMENUM,
	HWIF_BITPLANE0_E,
	HWIF_BITPLANE1_E,
	HWIF_BITPLANE2_E,
	HWIF_ALT_PQUANT,
	HWIF_DQ_EDGES,
	HWIF_TTMBF,
	HWIF_PQINDEX,
	HWIF_HEIGHT_EXT,
	HWIF_BILIN_MC_E,
	HWIF_UNIQP_E,
	HWIF_HALFQP_E,
	HWIF_TTFRM,
	HWIF_2ND_BYTE_EMUL_E,
	HWIF_DQUANT_E,
	HWIF_ADV_E,
	HWIF_PJPEG_FILDOWN_E,
	HWIF_PJPEG_WDIV8,
	HWIF_PJPEG_HDIV8,
	HWIF_PJPEG_AH,
	HWIF_PJPEG_AL,
	HWIF_PJPEG_SS,
	HWIF_PJPEG_SE,
	HWIF_DCT1_START_BIT,
	HWIF_DCT2_START_BIT,
	HWIF_CH_MV_RES,
	HWIF_INIT_DC_MATCH0,
	HWIF_INIT_DC_MATCH1,
	HWIF_VP7_VERSION,
	HWIF_CONST_INTRA_E,
	HWIF_FILT_CTRL_PRES,
	HWIF_RDPIC_CNT_PRES,
	HWIF_8X8TRANS_FLAG_E,
	HWIF_REFPIC_MK_LEN,
	HWIF_IDR_PIC_E,
	HWIF_IDR_PIC_ID,
	HWIF_MV_SCALEFACTOR,
	HWIF_REF_DIST_FWD,
	HWIF_REF_DIST_BWD,
	HWIF_LOOP_FILT_LIMIT,
	HWIF_VARIANCE_TEST_E,
	HWIF_MV_THRESHOLD,
	HWIF_VAR_THRESHOLD,
	HWIF_PJPEG_REST_FREQ,
	HWIF_INIT_DC_COMP0,
	HWIF_INIT_DC_COMP1,
	HWIF_PPS_ID,
	HWIF_REFIDX1_ACTIVE,
	HWIF_REFIDX0_ACTIVE,
	HWIF_POC_LENGTH,
	HWIF_ICOMP0_E,
	HWIF_ISCALE0,
	HWIF_ISHIFT0,
	HWIF_STREAM1_LEN,
	HWIF_MB_CTRL_BASE,
	HWIF_PIC_SLICE_AM,
	HWIF_COEFFS_PART_AM,
	HWIF_DIFF_MV_BASE,
	HWIF_PINIT_RLIST_F9,
	HWIF_PINIT_RLIST_F8,
	HWIF_PINIT_RLIST_F7,
	HWIF_PINIT_RLIST_F6,
	HWIF_PINIT_RLIST_F5,
	HWIF_PINIT_RLIST_F4,
	HWIF_ICOMP1_E,
	HWIF_ISCALE1,
	HWIF_ISHIFT1,
	HWIF_SEGMENT_BASE,
	HWIF_SEGMENT_UPD_E,
	HWIF_SEGMENT_E,
	HWIF_I4X4_OR_DC_BASE,
	HWIF_PINIT_RLIST_F15,
	HWIF_PINIT_RLIST_F14,
	HWIF_PINIT_RLIST_F13,
	HWIF_PINIT_RLIST_F12,
	HWIF_PINIT_RLIST_F11,
	HWIF_PINIT_RLIST_F10,
	HWIF_ICOMP2_E,
	HWIF_ISCALE2,
	HWIF_ISHIFT2,
	HWIF_DCT3_START_BIT,
	HWIF_DCT4_START_BIT,
	HWIF_DCT5_START_BIT,
	HWIF_DCT6_START_BIT,
	HWIF_DCT7_START_BIT,
	HWIF_RLC_VLC_BASE,
	HWIF_DEC_OUT_BASE,
	HWIF_REFER0_BASE,
	HWIF_REFER0_FIELD_E,
	HWIF_REFER0_TOPC_E,
	HWIF_JPG_CH_OUT_BASE,
	HWIF_REFER1_BASE,
	HWIF_REFER1_FIELD_E,
	HWIF_REFER1_TOPC_E,
	HWIF_JPEG_SLICE_H,
	HWIF_REFER2_BASE,
	HWIF_REFER2_FIELD_E,
	HWIF_REFER2_TOPC_E,
	HWIF_AC1_CODE6_CNT,
	HWIF_AC1_CODE5_CNT,
	HWIF_AC1_CODE4_CNT,
	HWIF_AC1_CODE3_CNT,
	HWIF_AC1_CODE2_CNT,
	HWIF_AC1_CODE1_CNT,
	HWIF_REFER3_BASE,
	HWIF_REFER3_FIELD_E,
	HWIF_REFER3_TOPC_E,
	HWIF_AC1_CODE10_CNT,
	HWIF_AC1_CODE9_CNT,
	HWIF_AC1_CODE8_CNT,
	HWIF_AC1_CODE7_CNT,
	HWIF_REFER4_BASE,
	HWIF_REFER4_FIELD_E,
	HWIF_REFER4_TOPC_E,
	HWIF_PIC_HEADER_LEN,
	HWIF_PIC_4MV_E,
	HWIF_RANGE_RED_REF_E,
	HWIF_DIFMV_RANGE,
	HWIF_MV_RANGE,
	HWIF_OVERLAP_E,
	HWIF_OVERLAP_METHOD,
	HWIF_ALT_SCAN_FLAG_E,
	HWIF_FCODE_FWD_HOR,
	HWIF_FCODE_FWD_VER,
	HWIF_FCODE_BWD_HOR,
	HWIF_FCODE_BWD_VER,
	HWIF_MV_ACCURACY_FWD,
	HWIF_MV_ACCURACY_BWD,
	HWIF_MPEG4_RC,
	HWIF_PREV_ANC_TYPE,
	HWIF_AC1_CODE14_CNT,
	HWIF_AC1_CODE13_CNT,
	HWIF_AC1_CODE12_CNT,
	HWIF_AC1_CODE11_CNT,
	HWIF_GREF_SIGN_BIAS,
	HWIF_REFER5_BASE,
	HWIF_REFER5_FIELD_E,
	HWIF_REFER5_TOPC_E,
	HWIF_TRB_PER_TRD_D0,
	HWIF_ICOMP3_E,
	HWIF_ISCALE3,
	HWIF_ISHIFT3,
	HWIF_AC2_CODE4_CNT,
	HWIF_AC2_CODE3_CNT,
	HWIF_AC2_CODE2_CNT,
	HWIF_AC2_CODE1_CNT,
	HWIF_AC1_CODE16_CNT,
	HWIF_AC1_CODE15_CNT,
	HWIF_SCAN_MAP_1,
	HWIF_SCAN_MAP_2,
	HWIF_SCAN_MAP_3,
	HWIF_SCAN_MAP_4,
	HWIF_SCAN_MAP_5,
	HWIF_AREF_SIGN_BIAS,
	HWIF_REFER6_BASE,
	HWIF_REFER6_FIELD_E,
	HWIF_REFER6_TOPC_E,
	HWIF_TRB_PER_TRD_DM1,
	HWIF_ICOMP4_E,
	HWIF_ISCALE4,
	HWIF_ISHIFT4,
	HWIF_AC2_CODE8_CNT,
	HWIF_AC2_CODE7_CNT,
	HWIF_AC2_CODE6_CNT,
	HWIF_AC2_CODE5_CNT,
	HWIF_SCAN_MAP_6,
	HWIF_SCAN_MAP_7,
	HWIF_SCAN_MAP_8,
	HWIF_SCAN_MAP_9,
	HWIF_SCAN_MAP_10,
	HWIF_REFER7_BASE,
	HWIF_REFER7_FIELD_E,
	HWIF_REFER7_TOPC_E,
	HWIF_TRB_PER_TRD_D1,
	HWIF_AC2_CODE12_CNT,
	HWIF_AC2_CODE11_CNT,
	HWIF_AC2_CODE10_CNT,
	HWIF_AC2_CODE9_CNT,
	HWIF_SCAN_MAP_11,
	HWIF_SCAN_MAP_12,
	HWIF_SCAN_MAP_13,
	HWIF_SCAN_MAP_14,
	HWIF_SCAN_MAP_15,
	HWIF_REFER8_BASE,
	HWIF_DCT_STRM1_BASE,
	HWIF_REFER8_FIELD_E,
	HWIF_REFER8_TOPC_E,
	HWIF_AC2_CODE16_CNT,
	HWIF_AC2_CODE15_CNT,
	HWIF_AC2_CODE14_CNT,
	HWIF_AC2_CODE13_CNT,
	HWIF_SCAN_MAP_16,
	HWIF_SCAN_MAP_17,
	HWIF_SCAN_MAP_18,
	HWIF_SCAN_MAP_19,
	HWIF_SCAN_MAP_20,
	HWIF_REFER9_BASE,
	HWIF_DCT_STRM2_BASE,
	HWIF_REFER9_FIELD_E,
	HWIF_REFER9_TOPC_E,
	HWIF_DC1_CODE8_CNT,
	HWIF_DC1_CODE7_CNT,
	HWIF_DC1_CODE6_CNT,
	HWIF_DC1_CODE5_CNT,
	HWIF_DC1_CODE4_CNT,
	HWIF_DC1_CODE3_CNT,
	HWIF_DC1_CODE2_CNT,
	HWIF_DC1_CODE1_CNT,
	HWIF_SCAN_MAP_21,
	HWIF_SCAN_MAP_22,
	HWIF_SCAN_MAP_23,
	HWIF_SCAN_MAP_24,
	HWIF_SCAN_MAP_25,
	HWIF_REFER10_BASE,
	HWIF_DCT_STRM3_BASE,
	HWIF_REFER10_FIELD_E,
	HWIF_REFER10_TOPC_E,
	HWIF_DC1_CODE16_CNT,
	HWIF_DC1_CODE15_CNT,
	HWIF_DC1_CODE14_CNT,
	HWIF_DC1_CODE13_CNT,
	HWIF_DC1_CODE12_CNT,
	HWIF_DC1_CODE11_CNT,
	HWIF_DC1_CODE10_CNT,
	HWIF_DC1_CODE9_CNT,
	HWIF_SCAN_MAP_26,
	HWIF_SCAN_MAP_27,
	HWIF_SCAN_MAP_28,
	HWIF_SCAN_MAP_29,
	HWIF_SCAN_MAP_30,
	HWIF_REFER11_BASE,
	HWIF_DCT_STRM4_BASE,
	HWIF_REFER11_FIELD_E,
	HWIF_REFER11_TOPC_E,
	HWIF_DC2_CODE8_CNT,
	HWIF_DC2_CODE7_CNT,
	HWIF_DC2_CODE6_CNT,
	HWIF_DC2_CODE5_CNT,
	HWIF_DC2_CODE4_CNT,
	HWIF_DC2_CODE3_CNT,
	HWIF_DC2_CODE2_CNT,
	HWIF_DC2_CODE1_CNT,
	HWIF_SCAN_MAP_31,
	HWIF_SCAN_MAP_32,
	HWIF_SCAN_MAP_33,
	HWIF_SCAN_MAP_34,
	HWIF_SCAN_MAP_35,
	HWIF_REFER12_BASE,
	HWIF_DCT_STRM5_BASE,
	HWIF_REFER12_FIELD_E,
	HWIF_REFER12_TOPC_E,
	HWIF_DC2_CODE16_CNT,
	HWIF_DC2_CODE15_CNT,
	HWIF_DC2_CODE14_CNT,
	HWIF_DC2_CODE13_CNT,
	HWIF_DC2_CODE12_CNT,
	HWIF_DC2_CODE11_CNT,
	HWIF_DC2_CODE10_CNT,
	HWIF_DC2_CODE9_CNT,
	HWIF_SCAN_MAP_36,
	HWIF_SCAN_MAP_37,
	HWIF_SCAN_MAP_38,
	HWIF_SCAN_MAP_39,
	HWIF_SCAN_MAP_40,
	HWIF_REFER13_BASE,
	HWIF_REFER13_FIELD_E,
	HWIF_REFER13_TOPC_E,
	HWIF_DC3_CODE8_CNT,
	HWIF_DC3_CODE7_CNT,
	HWIF_DC3_CODE6_CNT,
	HWIF_DC3_CODE5_CNT,
	HWIF_DC3_CODE4_CNT,
	HWIF_DC3_CODE3_CNT,
	HWIF_DC3_CODE2_CNT,
	HWIF_DC3_CODE1_CNT,
	HWIF_BITPL_CTRL_BASE,
	HWIF_REFER14_BASE,
	HWIF_DCT_STRM6_BASE,
	HWIF_REFER14_FIELD_E,
	HWIF_REFER14_TOPC_E,
	HWIF_REF_INVD_CUR_1,
	HWIF_REF_INVD_CUR_0,
	HWIF_DC3_CODE16_CNT,
	HWIF_DC3_CODE15_CNT,
	HWIF_DC3_CODE14_CNT,
	HWIF_DC3_CODE13_CNT,
	HWIF_DC3_CODE12_CNT,
	HWIF_DC3_CODE11_CNT,
	HWIF_DC3_CODE10_CNT,
	HWIF_DC3_CODE9_CNT,
	HWIF_SCAN_MAP_41,
	HWIF_SCAN_MAP_42,
	HWIF_SCAN_MAP_43,
	HWIF_SCAN_MAP_44,
	HWIF_SCAN_MAP_45,
	HWIF_REFER15_BASE,
	HWIF_DCT_STRM7_BASE,
	HWIF_REFER15_FIELD_E,
	HWIF_REFER15_TOPC_E,
	HWIF_REF_INVD_CUR_3,
	HWIF_REF_INVD_CUR_2,
	HWIF_SCAN_MAP_46,
	HWIF_SCAN_MAP_47,
	HWIF_SCAN_MAP_48,
	HWIF_SCAN_MAP_49,
	HWIF_SCAN_MAP_50,
	HWIF_REFER1_NBR,
	HWIF_REFER0_NBR,
	HWIF_REF_DIST_CUR_1,
	HWIF_REF_DIST_CUR_0,
	HWIF_FILT_TYPE,
	HWIF_FILT_SHARPNESS,
	HWIF_FILT_MB_ADJ_0,
	HWIF_FILT_MB_ADJ_1,
	HWIF_FILT_MB_ADJ_2,
	HWIF_FILT_MB_ADJ_3,
	HWIF_REFER3_NBR,
	HWIF_REFER2_NBR,
	HWIF_SCAN_MAP_51,
	HWIF_SCAN_MAP_52,
	HWIF_SCAN_MAP_53,
	HWIF_SCAN_MAP_54,
	HWIF_SCAN_MAP_55,
	HWIF_REF_DIST_CUR_3,
	HWIF_REF_DIST_CUR_2,
	HWIF_FILT_REF_ADJ_0,
	HWIF_FILT_REF_ADJ_1,
	HWIF_FILT_REF_ADJ_2,
	HWIF_FILT_REF_ADJ_3,
	HWIF_REFER5_NBR,
	HWIF_REFER4_NBR,
	HWIF_SCAN_MAP_56,
	HWIF_SCAN_MAP_57,
	HWIF_SCAN_MAP_58,
	HWIF_SCAN_MAP_59,
	HWIF_SCAN_MAP_60,
	HWIF_REF_INVD_COL_1,
	HWIF_REF_INVD_COL_0,
	HWIF_FILT_LEVEL_0,
	HWIF_FILT_LEVEL_1,
	HWIF_FILT_LEVEL_2,
	HWIF_FILT_LEVEL_3,
	HWIF_REFER7_NBR,
	HWIF_REFER6_NBR,
	HWIF_SCAN_MAP_61,
	HWIF_SCAN_MAP_62,
	HWIF_SCAN_MAP_63,
	HWIF_REF_INVD_COL_3,
	HWIF_REF_INVD_COL_2,
	HWIF_QUANT_DELTA_0,
	HWIF_QUANT_DELTA_1,
	HWIF_QUANT_0,
	HWIF_QUANT_1,
	HWIF_REFER9_NBR,
	HWIF_REFER8_NBR,
	HWIF_PRED_BC_TAP_0_3,
	HWIF_PRED_BC_TAP_1_0,
	HWIF_PRED_BC_TAP_1_1,
	HWIF_REFER11_NBR,
	HWIF_REFER10_NBR,
	HWIF_PRED_BC_TAP_1_2,
	HWIF_PRED_BC_TAP_1_3,
	HWIF_PRED_BC_TAP_2_0,
	HWIF_REFER13_NBR,
	HWIF_REFER12_NBR,
	HWIF_PRED_BC_TAP_2_1,
	HWIF_PRED_BC_TAP_2_2,
	HWIF_PRED_BC_TAP_2_3,
	HWIF_REFER15_NBR,
	HWIF_REFER14_NBR,
	HWIF_PRED_BC_TAP_3_0,
	HWIF_PRED_BC_TAP_3_1,
	HWIF_PRED_BC_TAP_3_2,
	HWIF_REFER_LTERM_E,
	HWIF_PRED_BC_TAP_3_3,
	HWIF_PRED_BC_TAP_4_0,
	HWIF_PRED_BC_TAP_4_1,
	HWIF_REFER_VALID_E,
	HWIF_PRED_BC_TAP_4_2,
	HWIF_PRED_BC_TAP_4_3,
	HWIF_PRED_BC_TAP_5_0,
	HWIF_QTABLE_BASE,
	HWIF_DIR_MV_BASE,
	HWIF_BINIT_RLIST_B2,
	HWIF_BINIT_RLIST_F2,
	HWIF_BINIT_RLIST_B1,
	HWIF_BINIT_RLIST_F1,
	HWIF_BINIT_RLIST_B0,
	HWIF_BINIT_RLIST_F0,
	HWIF_PRED_BC_TAP_5_1,
	HWIF_PRED_BC_TAP_5_2,
	HWIF_PRED_BC_TAP_5_3,
	HWIF_PJPEG_DCCB_BASE,
	HWIF_BINIT_RLIST_B5,
	HWIF_BINIT_RLIST_F5,
	HWIF_BINIT_RLIST_B4,
	HWIF_BINIT_RLIST_F4,
	HWIF_BINIT_RLIST_B3,
	HWIF_BINIT_RLIST_F3,
	HWIF_PRED_BC_TAP_6_0,
	HWIF_PRED_BC_TAP_6_1,
	HWIF_PRED_BC_TAP_6_2,
	HWIF_PJPEG_DCCR_BASE,
	HWIF_BINIT_RLIST_B8,
	HWIF_BINIT_RLIST_F8,
	HWIF_BINIT_RLIST_B7,
	HWIF_BINIT_RLIST_F7,
	HWIF_BINIT_RLIST_B6,
	HWIF_BINIT_RLIST_F6,
	HWIF_PRED_BC_TAP_6_3,
	HWIF_PRED_BC_TAP_7_0,
	HWIF_PRED_BC_TAP_7_1,
	HWIF_BINIT_RLIST_B11,
	HWIF_BINIT_RLIST_F11,
	HWIF_BINIT_RLIST_B10,
	HWIF_BINIT_RLIST_F10,
	HWIF_BINIT_RLIST_B9,
	HWIF_BINIT_RLIST_F9,
	HWIF_PRED_BC_TAP_7_2,
	HWIF_PRED_BC_TAP_7_3,
	HWIF_PRED_TAP_2_M1,
	HWIF_PRED_TAP_2_4,
	HWIF_PRED_TAP_4_M1,
	HWIF_PRED_TAP_4_4,
	HWIF_PRED_TAP_6_M1,
	HWIF_PRED_TAP_6_4,
	HWIF_BINIT_RLIST_B14,
	HWIF_BINIT_RLIST_F14,
	HWIF_BINIT_RLIST_B13,
	HWIF_BINIT_RLIST_F13,
	HWIF_BINIT_RLIST_B12,
	HWIF_BINIT_RLIST_F12,
	HWIF_QUANT_DELTA_2,
	HWIF_QUANT_DELTA_3,
	HWIF_QUANT_2,
	HWIF_QUANT_3,
	HWIF_PINIT_RLIST_F3,
	HWIF_PINIT_RLIST_F2,
	HWIF_PINIT_RLIST_F1,
	HWIF_PINIT_RLIST_F0,
	HWIF_BINIT_RLIST_B15,
	HWIF_BINIT_RLIST_F15,
	HWIF_QUANT_DELTA_4,
	HWIF_QUANT_4,
	HWIF_QUANT_5,
	HWIF_STARTMB_X,
	HWIF_STARTMB_Y,
	HWIF_PRED_BC_TAP_0_0,
	HWIF_PRED_BC_TAP_0_1,
	HWIF_PRED_BC_TAP_0_2,
	HWIF_REFBU_E,
	HWIF_REFBU_THR,
	HWIF_REFBU_PICID,
	HWIF_REFBU_EVAL_E,
	HWIF_REFBU_FPARMOD_E,
	HWIF_REFBU_Y_OFFSET,
	HWIF_REFBU_HIT_SUM,
	HWIF_REFBU_INTRA_SUM,
	HWIF_REFBU_Y_MV_SUM,
	HWIF_REFBU2_BUF_E,
	HWIF_REFBU2_THR,
	HWIF_REFBU2_PICID,
	HWIF_APF_THRESHOLD,
	HWIF_REFBU_TOP_SUM,
	HWIF_REFBU_BOT_SUM,
	HWIF_DEC_CH8PIX_BASE,
	HWIF_PP_BUS_INT,
	HWIF_PP_RDY_INT,
	HWIF_PP_IRQ,
	HWIF_PP_IRQ_DIS,
	HWIF_PP_PIPELINE_E,
	HWIF_PP_E,
	HWIF_PP_AXI_RD_ID,
	HWIF_PP_AXI_WR_ID,
	HWIF_PP_AHB_HLOCK_E,
	HWIF_PP_SCMD_DIS,
	HWIF_PP_IN_A2_ENDSEL,
	HWIF_PP_IN_A1_SWAP32,
	HWIF_PP_IN_A1_ENDIAN,
	HWIF_PP_IN_SWAP32_E,
	HWIF_PP_DATA_DISC_E,
	HWIF_PP_CLK_GATE_E,
	HWIF_PP_IN_ENDIAN,
	HWIF_PP_OUT_ENDIAN,
	HWIF_PP_OUT_SWAP32_E,
	HWIF_PP_MAX_BURST,
	HWIF_DEINT_E,
	HWIF_DEINT_THRESHOLD,
	HWIF_DEINT_BLEND_E,
	HWIF_DEINT_EDGE_DET,
	HWIF_PP_IN_LU_BASE,
	HWIF_PP_IN_CB_BASE,
	HWIF_PP_IN_CR_BASE,
	HWIF_PP_OUT_LU_BASE,
	HWIF_PP_OUT_CH_BASE,
	HWIF_CONTRAST_THR1,
	HWIF_CONTRAST_OFF2,
	HWIF_CONTRAST_OFF1,
	HWIF_PP_IN_START_CH,
	HWIF_PP_IN_CR_FIRST,
	HWIF_PP_OUT_START_CH,
	HWIF_PP_OUT_CR_FIRST,
	HWIF_COLOR_COEFFA2,
	HWIF_COLOR_COEFFA1,
	HWIF_CONTRAST_THR2,
	HWIF_PP_OUT_H_EXT,
	HWIF_COLOR_COEFFD,
	HWIF_COLOR_COEFFC,
	HWIF_COLOR_COEFFB,
	HWIF_PP_OUT_W_EXT,
	HWIF_CROP_STARTX,
	HWIF_ROTATION_MODE,
	HWIF_COLOR_COEFFF,
	HWIF_COLOR_COEFFE,
	HWIF_CROP_STARTY,
	HWIF_RANGEMAP_COEF_Y,
	HWIF_PP_IN_HEIGHT,
	HWIF_PP_IN_WIDTH,
	HWIF_PP_BOT_YIN_BASE,
	HWIF_PP_BOT_CIN_BASE,
	HWIF_RANGEMAP_Y_E,
	HWIF_RANGEMAP_C_E,
	HWIF_YCBCR_RANGE,
	HWIF_RGB_PIX_IN32,
	HWIF_RGB_R_PADD,
	HWIF_RGB_G_PADD,
	HWIF_SCALE_WRATIO,
	HWIF_PP_FAST_SCALE_E,
	HWIF_PP_IN_STRUCT,
	HWIF_HOR_SCALE_MODE,
	HWIF_VER_SCALE_MODE,
	HWIF_RGB_B_PADD,
	HWIF_SCALE_HRATIO,
	HWIF_WSCALE_INVRA,
	HWIF_HSCALE_INVRA,
	HWIF_R_MASK,
	HWIF_G_MASK,
	HWIF_B_MASK,
	HWIF_PP_IN_FORMAT,
	HWIF_PP_OUT_FORMAT,
	HWIF_PP_OUT_HEIGHT,
	HWIF_PP_OUT_WIDTH,
	HWIF_PP_OUT_TILED_E,
	HWIF_PP_OUT_SWAP16_E,
	HWIF_PP_CROP8_R_E,
	HWIF_PP_CROP8_D_E,
	HWIF_PP_IN_FORMAT_ES,
	HWIF_RANGEMAP_COEF_C,
	HWIF_MASK1_ABLEND_E,
	HWIF_MASK1_STARTY,
	HWIF_MASK1_STARTX,
	HWIF_MASK1_STARTX_EXT,
	HWIF_MASK1_STARTY_EXT,
	HWIF_MASK2_STARTX_EXT,
	HWIF_MASK2_STARTY_EXT,
	HWIF_MASK2_ABLEND_E,
	HWIF_MASK2_STARTY,
	HWIF_MASK2_STARTX,
	HWIF_EXT_ORIG_WIDTH,
	HWIF_MASK1_E,
	HWIF_MASK1_ENDY,
	HWIF_MASK1_ENDX,
	HWIF_MASK1_ENDX_EXT,
	HWIF_MASK1_ENDY_EXT,
	HWIF_MASK2_ENDX_EXT,
	HWIF_MASK2_ENDY_EXT,
	HWIF_MASK2_E,
	HWIF_MASK2_ENDY,
	HWIF_MASK2_ENDX,
	HWIF_RIGHT_CROSS_E,
	HWIF_LEFT_CROSS_E,
	HWIF_UP_CROSS_E,
	HWIF_DOWN_CROSS_E,
	HWIF_UP_CROSS,
	HWIF_DOWN_CROSS_EXT,
	HWIF_DOWN_CROSS,
	HWIF_DITHER_SELECT_R,
	HWIF_DITHER_SELECT_G,
	HWIF_DITHER_SELECT_B,
	HWIF_PP_TILED_MODE,
	HWIF_RIGHT_CROSS,
	HWIF_LEFT_CROSS,
	HWIF_PP_IN_H_EXT,
	HWIF_PP_IN_W_EXT,
	HWIF_CROP_STARTY_EXT,
	HWIF_CROP_STARTX_EXT,
	HWIF_RIGHT_CROSS_EXT,
	HWIF_LEFT_CROSS_EXT,
	HWIF_UP_CROSS_EXT,
	HWIF_DISPLAY_WIDTH,
	HWIF_ABLEND1_BASE,
	HWIF_ABLEND2_BASE,
	HWIF_ABLEND2_SCANL,
	HWIF_ABLEND1_SCANL,

	HWIF_DEC_IRQ_STAT,
	HWIF_PP_IRQ_STAT,
	HWIF_LAST_REG,

	/* aliases */
	HWIF_MPEG4_DC_BASE = HWIF_I4X4_OR_DC_BASE,
	HWIF_INTRA_4X4_BASE = HWIF_I4X4_OR_DC_BASE,
	/* VP8 */
    HWIF_VP8HWGOLDEN_BASE = HWIF_REFER4_BASE,
    HWIF_VP8HWPART1_BASE = HWIF_REFER13_BASE,
	HWIF_VP8HWPART2_BASE = HWIF_RLC_VLC_BASE,
	HWIF_VP8HWPROBTBL_BASE = HWIF_QTABLE_BASE,
	/* progressive JPEG */
	HWIF_PJPEG_COEFF_BUF = HWIF_DIR_MV_BASE,

	/* MVC */
	HWIF_INTER_VIEW_BASE = HWIF_REFER15_BASE,

} HWIF_VDPU_E;

class RkVdpuRegs {
public:
    RkVdpuRegs();
    ~RkVdpuRegs();

    RK_U32* base();
    RK_U32  size();         // byte unit

    RK_S32  write(HWIF_VDPU_E index, RK_U32 val);
    RK_U32  read(HWIF_VDPU_E index);

    // debug
    void    dump(RK_U32 *addr, RK_S32 len);
    void    setLog(RK_U32 on);

private:
    RK_U32*     regs_base;
    RK_S32      regs_size;
    RK_U32      regs_log;
};

#endif
