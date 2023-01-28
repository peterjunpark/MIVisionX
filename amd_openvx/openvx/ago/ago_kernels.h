/* 
Copyright (c) 2015 - 2023 Advanced Micro Devices, Inc. All rights reserved.
 
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
 
The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.
 
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/


#ifndef __ago_kernel_h__
#define __ago_kernel_h__

#include <VX/vx.h>

#ifdef  __cplusplus
extern "C" {
#endif

enum vx_kernel_amd_e {
	VX_KERNEL_AMD_INVALID = VX_KERNEL_BASE(VX_ID_AMD, VX_LIBRARY_KHR_BASE) + 0x0,

	// kernel enumeration naming:
	//    VX_KERNEL_AMD_<name>_<destination-spec>_<source-spec>_<options>

	// Element-wise 1-channel: U8 = const (2)
	VX_KERNEL_AMD_SET_00_U8,
	VX_KERNEL_AMD_SET_FF_U8,

	// Element-wise 1-channel: U8 = op U8 (6)
	VX_KERNEL_AMD_NOT_U8_U8,
	VX_KERNEL_AMD_LUT_U8_U8,
	VX_KERNEL_AMD_THRESHOLD_U8_U8_BINARY,
	VX_KERNEL_AMD_THRESHOLD_U8_U8_RANGE,
	VX_KERNEL_AMD_THRESHOLD_NOT_U8_U8_BINARY,
	VX_KERNEL_AMD_THRESHOLD_NOT_U8_U8_RANGE,

	// Element-wise 1-channel: S16 = op S16 
	VX_KERNEL_AMD_LUT_S16_S16,

	// Element-wise 1-channel: U8 = op U1 (1)
	VX_KERNEL_AMD_NOT_U8_U1,

	// Element-wise 1-channel: U1 = op U8 (5)
	VX_KERNEL_AMD_THRESHOLD_U1_U8_BINARY,
	VX_KERNEL_AMD_THRESHOLD_U1_U8_RANGE,
	VX_KERNEL_AMD_THRESHOLD_NOT_U1_U8_BINARY,
	VX_KERNEL_AMD_THRESHOLD_NOT_U1_U8_RANGE,
	VX_KERNEL_AMD_NOT_U1_U8,

	// Element-wise 1-channel: U1 = op U1 (1)
	VX_KERNEL_AMD_NOT_U1_U1,

	// Element-wise 1-channel: U8 = op S16 (2)
	VX_KERNEL_AMD_COLOR_DEPTH_U8_S16_WRAP,
	VX_KERNEL_AMD_COLOR_DEPTH_U8_S16_SAT,
	VX_KERNEL_AMD_THRESHOLD_U8_S16_BINARY,
	VX_KERNEL_AMD_THRESHOLD_U8_S16_RANGE,
	VX_KERNEL_AMD_THRESHOLD_NOT_U8_S16_BINARY,
	VX_KERNEL_AMD_THRESHOLD_NOT_U8_S16_RANGE,

	// Element-wise 1-channel: S16 = op U8 (3)
	VX_KERNEL_AMD_COLOR_DEPTH_S16_U8,
	VX_KERNEL_AMD_SOBEL_S16_U8_3x3_GX,
	VX_KERNEL_AMD_SOBEL_S16_U8_3x3_GY,

	// Element-wise 1-channel: U8 = U8 op U8 (16)
	VX_KERNEL_AMD_ADD_U8_U8U8_WRAP,
	VX_KERNEL_AMD_ADD_U8_U8U8_SAT,
	VX_KERNEL_AMD_SUB_U8_U8U8_WRAP,
	VX_KERNEL_AMD_SUB_U8_U8U8_SAT,
	VX_KERNEL_AMD_MUL_U8_U8U8_WRAP_TRUNC,
	VX_KERNEL_AMD_MUL_U8_U8U8_WRAP_ROUND,
	VX_KERNEL_AMD_MUL_U8_U8U8_SAT_TRUNC,
	VX_KERNEL_AMD_MUL_U8_U8U8_SAT_ROUND,
	VX_KERNEL_AMD_AND_U8_U8U8,
	VX_KERNEL_AMD_OR_U8_U8U8,
	VX_KERNEL_AMD_XOR_U8_U8U8,
	VX_KERNEL_AMD_NAND_U8_U8U8,
	VX_KERNEL_AMD_NOR_U8_U8U8,
	VX_KERNEL_AMD_XNOR_U8_U8U8,
	VX_KERNEL_AMD_ABS_DIFF_U8_U8U8,
	VX_KERNEL_AMD_ACCUMULATE_WEIGHTED_U8_U8U8,

	// Element-wise 1-channel: U8 = U8 op U1 (6)
	VX_KERNEL_AMD_AND_U8_U8U1,
	VX_KERNEL_AMD_OR_U8_U8U1,
	VX_KERNEL_AMD_XOR_U8_U8U1,
	VX_KERNEL_AMD_NAND_U8_U8U1,
	VX_KERNEL_AMD_NOR_U8_U8U1,
	VX_KERNEL_AMD_XNOR_U8_U8U1,

	// Element-wise 1-channel: U8 = U1 op U8 (6)
	VX_KERNEL_AMD_AND_U8_U1U8,
	VX_KERNEL_AMD_OR_U8_U1U8,
	VX_KERNEL_AMD_XOR_U8_U1U8,
	VX_KERNEL_AMD_NAND_U8_U1U8,
	VX_KERNEL_AMD_NOR_U8_U1U8,
	VX_KERNEL_AMD_XNOR_U8_U1U8,

	// Element-wise 1-channel: U8 = U1 op U1 (6)
	VX_KERNEL_AMD_AND_U8_U1U1,
	VX_KERNEL_AMD_OR_U8_U1U1,
	VX_KERNEL_AMD_XOR_U8_U1U1,
	VX_KERNEL_AMD_NAND_U8_U1U1,
	VX_KERNEL_AMD_NOR_U8_U1U1,
	VX_KERNEL_AMD_XNOR_U8_U1U1,

	// Element-wise 1-channel: U1 = U8 op U8 (6)
	VX_KERNEL_AMD_AND_U1_U8U8,
	VX_KERNEL_AMD_OR_U1_U8U8,
	VX_KERNEL_AMD_XOR_U1_U8U8,
	VX_KERNEL_AMD_NAND_U1_U8U8,
	VX_KERNEL_AMD_NOR_U1_U8U8,
	VX_KERNEL_AMD_XNOR_U1_U8U8,

	// Element-wise 1-channel: U1 = U8 op U1 (6)
	VX_KERNEL_AMD_AND_U1_U8U1,
	VX_KERNEL_AMD_OR_U1_U8U1,
	VX_KERNEL_AMD_XOR_U1_U8U1,
	VX_KERNEL_AMD_NAND_U1_U8U1,
	VX_KERNEL_AMD_NOR_U1_U8U1,
	VX_KERNEL_AMD_XNOR_U1_U8U1,

	// Element-wise 1-channel: U1 = U1 op U8 (6)
	VX_KERNEL_AMD_AND_U1_U1U8,
	VX_KERNEL_AMD_OR_U1_U1U8,
	VX_KERNEL_AMD_XOR_U1_U1U8,
	VX_KERNEL_AMD_NAND_U1_U1U8,
	VX_KERNEL_AMD_NOR_U1_U1U8,
	VX_KERNEL_AMD_XNOR_U1_U1U8,

	// Element-wise 1-channel: U1 = U1 op U1 (6)
	VX_KERNEL_AMD_AND_U1_U1U1,
	VX_KERNEL_AMD_OR_U1_U1U1,
	VX_KERNEL_AMD_XOR_U1_U1U1,
	VX_KERNEL_AMD_NAND_U1_U1U1,
	VX_KERNEL_AMD_NOR_U1_U1U1,
	VX_KERNEL_AMD_XNOR_U1_U1U1,

	// Element-wise 1-channel: S16 = U8 op U8 (6)
	VX_KERNEL_AMD_ADD_S16_U8U8,
	VX_KERNEL_AMD_SUB_S16_U8U8,
	VX_KERNEL_AMD_MUL_S16_U8U8_WRAP_TRUNC,
	VX_KERNEL_AMD_MUL_S16_U8U8_WRAP_ROUND,
	VX_KERNEL_AMD_MUL_S16_U8U8_SAT_TRUNC,
	VX_KERNEL_AMD_MUL_S16_U8U8_SAT_ROUND,

	// Element-wise 1-channel: S16 = U8 op S16 (2)
	VX_KERNEL_AMD_SUB_S16_U8S16_WRAP,
	VX_KERNEL_AMD_SUB_S16_U8S16_SAT,

	// Element-wise 1-channel: S16 = S16 op U8 (10)
	VX_KERNEL_AMD_ADD_S16_S16U8_WRAP,
	VX_KERNEL_AMD_ADD_S16_S16U8_SAT,
	VX_KERNEL_AMD_ACCUMULATE_S16_S16U8_SAT,
	VX_KERNEL_AMD_SUB_S16_S16U8_WRAP,
	VX_KERNEL_AMD_SUB_S16_S16U8_SAT,
	VX_KERNEL_AMD_MUL_S16_S16U8_WRAP_TRUNC,
	VX_KERNEL_AMD_MUL_S16_S16U8_WRAP_ROUND,
	VX_KERNEL_AMD_MUL_S16_S16U8_SAT_TRUNC,
	VX_KERNEL_AMD_MUL_S16_S16U8_SAT_ROUND,
	VX_KERNEL_AMD_ACCUMULATE_SQUARED_S16_S16U8_SAT,

	// Element-wise 1-channel: S16 = S16 op S16 (10)
	VX_KERNEL_AMD_ABS_DIFF_S16_S16S16_SAT,
	VX_KERNEL_AMD_ADD_S16_S16S16_WRAP,
	VX_KERNEL_AMD_ADD_S16_S16S16_SAT,
	VX_KERNEL_AMD_SUB_S16_S16S16_WRAP,
	VX_KERNEL_AMD_SUB_S16_S16S16_SAT,
	VX_KERNEL_AMD_MUL_S16_S16S16_WRAP_TRUNC,
	VX_KERNEL_AMD_MUL_S16_S16S16_WRAP_ROUND,
	VX_KERNEL_AMD_MUL_S16_S16S16_SAT_TRUNC,
	VX_KERNEL_AMD_MUL_S16_S16S16_SAT_ROUND,
	VX_KERNEL_AMD_MAGNITUDE_S16_S16S16,

	// Element-wise 1-channel: U8 = S16 op S16 (1)
	VX_KERNEL_AMD_PHASE_U8_S16S16,

	// Element-wise n-channel: U8 = op U8 (1)
	VX_KERNEL_AMD_CHANNEL_COPY_U8_U8,

	// Element-wise n-channel: U8 = op U1 (1)
	VX_KERNEL_AMD_CHANNEL_COPY_U8_U1,

	// Element-wise n-channel: U1 = op U8 (1)
	VX_KERNEL_AMD_CHANNEL_COPY_U1_U8,

	// Element-wise n-channel: U1 = op U1 (1)
	VX_KERNEL_AMD_CHANNEL_COPY_U1_U1,

	// Element-wise n-channel: U8 = op U16 (2)
	VX_KERNEL_AMD_CHANNEL_EXTRACT_U8_U16_POS0,
	VX_KERNEL_AMD_CHANNEL_EXTRACT_U8_U16_POS1,

	// Element-wise n-channel: U8 = op U24 (4)
	VX_KERNEL_AMD_CHANNEL_EXTRACT_U8_U24_POS0,
	VX_KERNEL_AMD_CHANNEL_EXTRACT_U8_U24_POS1,
	VX_KERNEL_AMD_CHANNEL_EXTRACT_U8_U24_POS2,
	VX_KERNEL_AMD_CHANNEL_EXTRACT_U8U8U8_U24,

	// Element-wise n-channel: U8 = op U32 (6)
	VX_KERNEL_AMD_CHANNEL_EXTRACT_U8_U32_POS0,
	VX_KERNEL_AMD_CHANNEL_EXTRACT_U8_U32_POS1,
	VX_KERNEL_AMD_CHANNEL_EXTRACT_U8_U32_POS2,
	VX_KERNEL_AMD_CHANNEL_EXTRACT_U8_U32_POS3,
	VX_KERNEL_AMD_CHANNEL_EXTRACT_U8U8U8_U32,
	VX_KERNEL_AMD_CHANNEL_EXTRACT_U8U8U8U8_U32,

	// Element-wise n-channel: U16 = U8 op U8 (1)
	VX_KERNEL_AMD_CHANNEL_COMBINE_U16_U8U8,

	// Element-wise n-channel: U24 = U8 op U8 op U8 (1)
	VX_KERNEL_AMD_CHANNEL_COMBINE_U24_U8U8U8_RGB,

	// Element-wise n-channel: U32 = U8 op U8 op U8 (2)
	VX_KERNEL_AMD_CHANNEL_COMBINE_U32_U8U8U8_UYVY,
	VX_KERNEL_AMD_CHANNEL_COMBINE_U32_U8U8U8_YUYV,

	// Element-wise n-channel: U32 = U8 op U8 op U8 op U8 (1)
	VX_KERNEL_AMD_CHANNEL_COMBINE_U32_U8U8U8U8_RGBX,

	// Element-wise n-channel: U24/U32 = U24/U32 op U8 (2)
	VX_KERNEL_AMD_MUL_U24_U24U8_SAT_ROUND,
	VX_KERNEL_AMD_MUL_U32_U32U8_SAT_ROUND,

	// Element-wise n-channel: arbitrary (40)
	VX_KERNEL_AMD_COLOR_CONVERT_RGB_RGBX,
	VX_KERNEL_AMD_COLOR_CONVERT_RGB_UYVY,
	VX_KERNEL_AMD_COLOR_CONVERT_RGB_YUYV,
	VX_KERNEL_AMD_COLOR_CONVERT_RGB_IYUV,
	VX_KERNEL_AMD_COLOR_CONVERT_RGB_NV12,
	VX_KERNEL_AMD_COLOR_CONVERT_RGB_NV21,
	VX_KERNEL_AMD_COLOR_CONVERT_RGBX_RGB,
	VX_KERNEL_AMD_COLOR_CONVERT_RGBX_UYVY,
	VX_KERNEL_AMD_COLOR_CONVERT_RGBX_YUYV,
	VX_KERNEL_AMD_COLOR_CONVERT_RGBX_IYUV,
	VX_KERNEL_AMD_COLOR_CONVERT_RGBX_NV12,
	VX_KERNEL_AMD_COLOR_CONVERT_RGBX_NV21,
	VX_KERNEL_AMD_COLOR_CONVERT_YUV4_RGB,
	VX_KERNEL_AMD_COLOR_CONVERT_YUV4_RGBX,
	VX_KERNEL_AMD_SCALE_UP_2x2_U8_U8,       // IUV 4:2:0 to 4:4:4 format conversion
	VX_KERNEL_AMD_FORMAT_CONVERT_UV_UV12,   // UV12 4:2:0 to 4:4:4 format conversion
	VX_KERNEL_AMD_COLOR_CONVERT_IYUV_RGB,
	VX_KERNEL_AMD_COLOR_CONVERT_IYUV_RGBX,
	VX_KERNEL_AMD_FORMAT_CONVERT_IYUV_UYVY,
	VX_KERNEL_AMD_FORMAT_CONVERT_IYUV_YUYV,
	VX_KERNEL_AMD_FORMAT_CONVERT_IUV_UV12,  // UV 4:2:0 from IYUV to NV12
	VX_KERNEL_AMD_COLOR_CONVERT_NV12_RGB,
	VX_KERNEL_AMD_COLOR_CONVERT_NV12_RGBX,
	VX_KERNEL_AMD_FORMAT_CONVERT_NV12_UYVY,
	VX_KERNEL_AMD_FORMAT_CONVERT_NV12_YUYV,
	VX_KERNEL_AMD_FORMAT_CONVERT_UV12_IUV,  // UV 4:2:0 from NV12 to IYUV
	VX_KERNEL_AMD_COLOR_CONVERT_Y_RGB,     // Y plane
	VX_KERNEL_AMD_COLOR_CONVERT_Y_RGBX,    // Y plane
	VX_KERNEL_AMD_COLOR_CONVERT_U_RGB,     // U plane
	VX_KERNEL_AMD_COLOR_CONVERT_U_RGBX,    // U plane
	VX_KERNEL_AMD_COLOR_CONVERT_V_RGB,     // V plane
	VX_KERNEL_AMD_COLOR_CONVERT_V_RGBX,    // V plane
	VX_KERNEL_AMD_COLOR_CONVERT_IU_RGB,    // U plane in IYUV 4:2:0
	VX_KERNEL_AMD_COLOR_CONVERT_IU_RGBX,   // U plane in IYUV 4:2:0
	VX_KERNEL_AMD_COLOR_CONVERT_IV_RGB,    // V plane in IYUV 4:2:0
	VX_KERNEL_AMD_COLOR_CONVERT_IV_RGBX,   // V plane in IYUV 4:2:0
	VX_KERNEL_AMD_COLOR_CONVERT_IUV_RGB,   // U & V planes in IYUV 4:2:0
	VX_KERNEL_AMD_COLOR_CONVERT_IUV_RGBX,  // U & V planes in IYUV 4:2:0
	VX_KERNEL_AMD_COLOR_CONVERT_UV12_RGB,  // UV plane in NV12 4:2:0
	VX_KERNEL_AMD_COLOR_CONVERT_UV12_RGBX, // UV plane in NV12 4:2:0

	// Fixed Neighbors: U8 = op U8 (16)
	VX_KERNEL_AMD_BOX_U8_U8_3x3,
	VX_KERNEL_AMD_DILATE_U8_U8_3x3,
	VX_KERNEL_AMD_ERODE_U8_U8_3x3,
	VX_KERNEL_AMD_MEDIAN_U8_U8_3x3,
	VX_KERNEL_AMD_GAUSSIAN_U8_U8_3x3,
	VX_KERNEL_AMD_SCALE_GAUSSIAN_HALF_U8_U8_3x3,
	VX_KERNEL_AMD_SCALE_GAUSSIAN_HALF_U8_U8_5x5,
	VX_KERNEL_AMD_SCALE_GAUSSIAN_ORB_U8_U8_5x5,
	VX_KERNEL_AMD_SOBEL_PHASE_U8_U8_3x3,
	VX_KERNEL_AMD_CANNY_SOBEL_SUPP_THRESHOLD_U8_U8_3x3_L1NORM,
	VX_KERNEL_AMD_CANNY_SOBEL_SUPP_THRESHOLD_U8_U8_3x3_L2NORM,
	VX_KERNEL_AMD_CANNY_SOBEL_SUPP_THRESHOLD_U8_U8_5x5_L1NORM,
	VX_KERNEL_AMD_CANNY_SOBEL_SUPP_THRESHOLD_U8_U8_5x5_L2NORM,
	VX_KERNEL_AMD_CANNY_SOBEL_SUPP_THRESHOLD_U8_U8_7x7_L1NORM,
	VX_KERNEL_AMD_CANNY_SOBEL_SUPP_THRESHOLD_U8_U8_7x7_L2NORM,
	VX_KERNEL_AMD_CONVOLVE_U8_U8,

	// Fixed Neighbors: S16 = op U8 (2)
	VX_KERNEL_AMD_CONVOLVE_S16_U8,
	VX_KERNEL_AMD_SOBEL_MAGNITUDE_S16_U8_3x3,

	// Fixed Neighbors: S16U8 = op U8 (1)
	VX_KERNEL_AMD_SOBEL_MAGNITUDE_PHASE_S16U8_U8_3x3,

	// Fixed Neighbors: S16S16 = op U8 (1)
	VX_KERNEL_AMD_SOBEL_S16S16_U8_3x3_GXY,

	// Fixed Neighbors: F32/S16/U8 = op F32/S16/U8 (1)
	VX_KERNEL_AMD_LINEAR_FILTER_ANY_ANY,

	// Fixed Neighbors: F32/S16/U8 = op U8 (1)
	VX_KERNEL_AMD_LINEAR_FILTER_ANYx2_ANY,

	// Fixed Neighbors: U1 = op U8 (2)
	VX_KERNEL_AMD_DILATE_U1_U8_3x3,
	VX_KERNEL_AMD_ERODE_U1_U8_3x3,

	// Fixed Neighbors: U1 = op U1 (2)
	VX_KERNEL_AMD_DILATE_U1_U1_3x3,
	VX_KERNEL_AMD_ERODE_U1_U1_3x3,

	// Fixed Neighbors: U8 = op U1 (2)
	VX_KERNEL_AMD_DILATE_U8_U1_3x3,
	VX_KERNEL_AMD_ERODE_U8_U1_3x3,

	// Fixed Neighbors: XY = op U8 (2)
	VX_KERNEL_AMD_FAST_CORNERS_XY_U8_SUPRESSION,
	VX_KERNEL_AMD_FAST_CORNERS_XY_U8_NOSUPRESSION,

	// Fixed Neighbors: HG3 = op U8 (3)
	VX_KERNEL_AMD_HARRIS_SOBEL_HG3_U8_3x3,
	VX_KERNEL_AMD_HARRIS_SOBEL_HG3_U8_5x5,
	VX_KERNEL_AMD_HARRIS_SOBEL_HG3_U8_7x7,

	// Fixed Neighbors: Fxy = op HG3 (3)
	VX_KERNEL_AMD_HARRIS_SCORE_HVC_HG3_3x3,
	VX_KERNEL_AMD_HARRIS_SCORE_HVC_HG3_5x5,
	VX_KERNEL_AMD_HARRIS_SCORE_HVC_HG3_7x7,

	// Fixed Neighbors: U8xy = op U8 (6)
	VX_KERNEL_AMD_CANNY_SOBEL_SUPP_THRESHOLD_U8XY_U8_3x3_L1NORM,
	VX_KERNEL_AMD_CANNY_SOBEL_SUPP_THRESHOLD_U8XY_U8_3x3_L2NORM,
	VX_KERNEL_AMD_CANNY_SOBEL_SUPP_THRESHOLD_U8XY_U8_5x5_L1NORM,
	VX_KERNEL_AMD_CANNY_SOBEL_SUPP_THRESHOLD_U8XY_U8_5x5_L2NORM,
	VX_KERNEL_AMD_CANNY_SOBEL_SUPP_THRESHOLD_U8XY_U8_7x7_L1NORM,
	VX_KERNEL_AMD_CANNY_SOBEL_SUPP_THRESHOLD_U8XY_U8_7x7_L2NORM,

	// Fixed Neighbors: U16(mag,phase) = op U8 (6)
	VX_KERNEL_AMD_CANNY_SOBEL_U16_U8_3x3_L1NORM,
	VX_KERNEL_AMD_CANNY_SOBEL_U16_U8_3x3_L2NORM,
	VX_KERNEL_AMD_CANNY_SOBEL_U16_U8_5x5_L1NORM,
	VX_KERNEL_AMD_CANNY_SOBEL_U16_U8_5x5_L2NORM,
	VX_KERNEL_AMD_CANNY_SOBEL_U16_U8_7x7_L1NORM,
	VX_KERNEL_AMD_CANNY_SOBEL_U16_U8_7x7_L2NORM,

	// Fixed Neighbors: U8 = U16(mag,phase) (1)
	VX_KERNEL_AMD_CANNY_SUPP_THRESHOLD_U8_U16_3x3,

	// Fixed Neighbors: U8xy = U16(mag,phase) (1)
	VX_KERNEL_AMD_CANNY_SUPP_THRESHOLD_U8XY_U16_3x3,
	VX_KERNEL_AMD_CANNY_SUPP_THRESHOLD_U8XY_U16_7x7,
	// Fixed Neighbors: xy = ANY (1)
	VX_KERNEL_AMD_NON_MAX_SUPP_XY_ANY_3x3,

	// Arbitrary Neighbors: U8 = op U8 (20)
	VX_KERNEL_AMD_REMAP_U8_U8_NEAREST,
	VX_KERNEL_AMD_REMAP_U8_U8_NEAREST_CONSTANT,
	VX_KERNEL_AMD_REMAP_U8_U8_BILINEAR,
	VX_KERNEL_AMD_REMAP_U8_U8_BILINEAR_CONSTANT,
	VX_KERNEL_AMD_WARP_AFFINE_U8_U8_NEAREST,
	VX_KERNEL_AMD_WARP_AFFINE_U8_U8_NEAREST_CONSTANT,
	VX_KERNEL_AMD_WARP_AFFINE_U8_U8_BILINEAR,
	VX_KERNEL_AMD_WARP_AFFINE_U8_U8_BILINEAR_CONSTANT,
	VX_KERNEL_AMD_WARP_PERSPECTIVE_U8_U8_NEAREST,
	VX_KERNEL_AMD_WARP_PERSPECTIVE_U8_U8_NEAREST_CONSTANT,
	VX_KERNEL_AMD_WARP_PERSPECTIVE_U8_U8_BILINEAR,
	VX_KERNEL_AMD_WARP_PERSPECTIVE_U8_U8_BILINEAR_CONSTANT,
	VX_KERNEL_AMD_SCALE_IMAGE_U8_U8_NEAREST,
	VX_KERNEL_AMD_SCALE_IMAGE_U8_U8_BILINEAR,
	VX_KERNEL_AMD_SCALE_IMAGE_U8_U8_BILINEAR_REPLICATE,
	VX_KERNEL_AMD_SCALE_IMAGE_U8_U8_BILINEAR_CONSTANT,
	VX_KERNEL_AMD_SCALE_IMAGE_U8_U8_AREA,
	VX_KERNEL_AMD_REMAP_U24_U24_BILINEAR,
	VX_KERNEL_AMD_REMAP_U24_U32_BILINEAR,
	VX_KERNEL_AMD_REMAP_U32_U32_BILINEAR,

	// Point Neighbors: XY = op XY (4)
	VX_KERNEL_AMD_OPTICAL_FLOW_PYR_LK_XY_XY,
	VX_KERNEL_AMD_OPTICAL_FLOW_PREPARE_LK_XY_XY,
	VX_KERNEL_AMD_OPTICAL_FLOW_IMAGE_LK_XY_XY,
	VX_KERNEL_AMD_OPTICAL_FLOW_FINAL_LK_XY_XY,

	// Sequential: XY = op HVC (1)
	VX_KERNEL_AMD_HARRIS_MERGE_SORT_AND_PICK_XY_HVC,

	// Sequential: XY = op XY (2)
	VX_KERNEL_AMD_FAST_CORNER_MERGE_XY_XY,
	VX_KERNEL_AMD_HARRIS_MERGE_SORT_AND_PICK_XY_XYS,

	// Sequential: U8 = op U8 (1)
	VX_KERNEL_AMD_CANNY_EDGE_TRACE_U8_U8,

	// Sequential: U8 = op U8XY (1)
	VX_KERNEL_AMD_CANNY_EDGE_TRACE_U8_U8XY,

	// Sequential: U32 = op U8 (1)
	VX_KERNEL_AMD_INTEGRAL_IMAGE_U32_U8,

	// Sequential: DATA = op U8 (3)
	VX_KERNEL_AMD_HISTOGRAM_DATA_U8,
	VX_KERNEL_AMD_MEAN_STD_DEV_DATA_U8,
	VX_KERNEL_AMD_MIN_MAX_DATA_U8,

	// Sequential: DATA = op U1
	VX_KERNEL_AMD_MEAN_STD_DEV_DATA_U1,

	// Sequential: DATA = op S16 (1)
	VX_KERNEL_AMD_MIN_MAX_DATA_S16,

	// Sequential: DATA = op DATA (1)
	VX_KERNEL_AMD_EQUALIZE_DATA_DATA,

	// Sequential: DATA = DATA op DATA (20)
	VX_KERNEL_AMD_HISTOGRAM_MERGE_DATA_DATA,
	VX_KERNEL_AMD_MEAN_STD_DEV_MERGE_DATA_DATA,
	VX_KERNEL_AMD_MIN_MAX_MERGE_DATA_DATA,
	VX_KERNEL_AMD_MIN_MAX_LOC_DATA_U8DATA_LOC_NONE_COUNT_MIN,
	VX_KERNEL_AMD_MIN_MAX_LOC_DATA_U8DATA_LOC_NONE_COUNT_MAX,
	VX_KERNEL_AMD_MIN_MAX_LOC_DATA_U8DATA_LOC_NONE_COUNT_MINMAX,
	VX_KERNEL_AMD_MIN_MAX_LOC_DATA_U8DATA_LOC_MIN_COUNT_MIN,
	VX_KERNEL_AMD_MIN_MAX_LOC_DATA_U8DATA_LOC_MIN_COUNT_MINMAX,
	VX_KERNEL_AMD_MIN_MAX_LOC_DATA_U8DATA_LOC_MAX_COUNT_MAX,
	VX_KERNEL_AMD_MIN_MAX_LOC_DATA_U8DATA_LOC_MAX_COUNT_MINMAX,
	VX_KERNEL_AMD_MIN_MAX_LOC_DATA_U8DATA_LOC_MINMAX_COUNT_MINMAX,
	VX_KERNEL_AMD_MIN_MAX_LOC_DATA_S16DATA_LOC_NONE_COUNT_MIN,
	VX_KERNEL_AMD_MIN_MAX_LOC_DATA_S16DATA_LOC_NONE_COUNT_MAX,
	VX_KERNEL_AMD_MIN_MAX_LOC_DATA_S16DATA_LOC_NONE_COUNT_MINMAX,
	VX_KERNEL_AMD_MIN_MAX_LOC_DATA_S16DATA_LOC_MIN_COUNT_MIN,
	VX_KERNEL_AMD_MIN_MAX_LOC_DATA_S16DATA_LOC_MIN_COUNT_MINMAX,
	VX_KERNEL_AMD_MIN_MAX_LOC_DATA_S16DATA_LOC_MAX_COUNT_MAX,
	VX_KERNEL_AMD_MIN_MAX_LOC_DATA_S16DATA_LOC_MAX_COUNT_MINMAX,
	VX_KERNEL_AMD_MIN_MAX_LOC_DATA_S16DATA_LOC_MINMAX_COUNT_MINMAX,
	VX_KERNEL_AMD_MIN_MAX_LOC_MERGE_DATA_DATA,

	// OpenVX 1.2 kernels
	VX_KERNEL_AMD_COPY_DATA_DATA,
	VX_KERNEL_AMD_SELECT_DATA_DATA_DATA,

	// OpenVX 1.3 kernels
	VX_KERNEL_AMD_WEIGHTED_AVERAGE_U8_U8_U8,
	VX_KERNEL_AMD_NON_LINEAR_FILTER_DATA_DATA_DATA,
	VX_KERNEL_AMD_LAPLACIAN_PYRAMID_DATA_DATA_DATA,
	VX_KERNEL_AMD_LAPLACIAN_RECONSTRUCT_DATA_DATA_DATA,

	VX_KERNEL_AMD_MAX_1_0, // Used for bounds checking in the internal conformance test
};

#ifdef  __cplusplus
}
#endif

#endif  // __ago_kernel_h__
