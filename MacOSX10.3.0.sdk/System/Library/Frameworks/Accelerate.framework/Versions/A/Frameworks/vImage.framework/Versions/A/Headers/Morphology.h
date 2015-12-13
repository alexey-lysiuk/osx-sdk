/*
 *  Morphology.h
 *  vImage_Framework
 *
 *  Copyright (c) 2002 Apple Computer. All rights reserved.
 *
 */

#ifndef VIMAGE_MORPHOLOGY_H
#define VIMAGE_MORPHOLOGY_H

#include <vImage/vImage_Types.h>


#ifdef __cplusplus
extern "C" {
#endif

/*  Morphology functions 
    -------------------- 
    Min is a special case for an Erode function with a kernel that contains all the same value. 
    Max is a special case for a Dilate function with a kernel that contains all the same value.
    
    The Erode and Dilate functions do saturated clipping to prevent overflow for UInt8 and ARGB_8888 types.
        No clipping is performed for floating point types. 
    Erode and Dilate handle the edges (areas where the kernel extends beyond the edges of the input buffer)
        by testing only those parts of the kernel that do overlay the input buffer. 
        
    An Open filter may be created by doing an Erode followed by a Dilate.
    A Close filter may be created by doing a Dilate followed by an Erode.
    
    A kernel populated with only one value lets us make some significant algorithmic optimizations. The 
    calculation time for the Dilate and Erode functions are proportional to M*N for a square kernel of 
    dimensions M x N.  The calculation time for the Min and Max functions is roughly proportional to 
    Log2(N) + Log2(M). The speed difference can be orders of magnitude for large kernels. We suggest 
    you use Min/Max instead of Dilate/Erode when possible. 
        
    The temp buffers should be the size returned by vImageGetMinimumTempBufferSizeForMinMax() or larger.
    
    The source and destination buffers must not overlap. Exception: They may overlap if you pass in a temporary buffer
    to Min or Max and you also pass the kvImageDoNotTile flag.
    
    In MacOS X.3, Panther, Min and Max do not respond to kvImageLeaveAlphaUnchanged for interleaved data formats. 
    Due to the large difference in speed between Min/Max and Dilate/Erode for large kernels, developers who wish 
    to do Min/Max with kvImageLeaveAlphaUnchanged should convert the data format to planar, then call Min/Max on the
    appropriate color channels and then convert back to the desired interleaved format. 
*/
vImage_Error vImageDilate_Planar8( const vImage_Buffer *src, const vImage_Buffer *dest, unsigned int srcOffsetToROI_X, unsigned int srcOffsetToROI_Y,  const unsigned char *kernel, unsigned int kernel_height, unsigned int kernel_width, vImage_Flags flags )    AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;
vImage_Error vImageDilate_PlanarF( const vImage_Buffer *src, const vImage_Buffer *dest, unsigned int srcOffsetToROI_X, unsigned int srcOffsetToROI_Y,  const float *kernel, unsigned int kernel_height, unsigned int kernel_width, vImage_Flags flags )    AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;
vImage_Error vImageDilate_ARGB8888( const vImage_Buffer *src, const vImage_Buffer *dest, unsigned int srcOffsetToROI_X, unsigned int srcOffsetToROI_Y,  const unsigned char *kernel, unsigned int kernel_height, unsigned int kernel_width, vImage_Flags flags )    AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;
vImage_Error vImageDilate_ARGBFFFF( const vImage_Buffer *src, const vImage_Buffer *dest, unsigned int srcOffsetToROI_X, unsigned int srcOffsetToROI_Y,  const float *kernel, unsigned int kernel_height, unsigned int kernel_width, vImage_Flags flags )    AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;

vImage_Error vImageErode_Planar8( const vImage_Buffer *src, const vImage_Buffer *dest, unsigned int srcOffsetToROI_X, unsigned int srcOffsetToROI_Y,  const unsigned char *kernel, unsigned int kernel_height, unsigned int kernel_width, vImage_Flags flags )    AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;
vImage_Error vImageErode_PlanarF( const vImage_Buffer *src, const vImage_Buffer *dest, unsigned int srcOffsetToROI_X, unsigned int srcOffsetToROI_Y,  const float *kernel, unsigned int kernel_height, unsigned int kernel_width, vImage_Flags flags )    AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;
vImage_Error vImageErode_ARGB8888( const vImage_Buffer *src, const vImage_Buffer *dest, unsigned int srcOffsetToROI_X, unsigned int srcOffsetToROI_Y,  const unsigned char *kernel, unsigned int kernel_height, unsigned int kernel_width, vImage_Flags flags )    AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;
vImage_Error vImageErode_ARGBFFFF( const vImage_Buffer *src, const vImage_Buffer *dest, unsigned int srcOffsetToROI_X, unsigned int srcOffsetToROI_Y,  const float *kernel, unsigned int kernel_height, unsigned int kernel_width, vImage_Flags flags )    AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;

vImage_Error vImageMax_Planar8( const vImage_Buffer *src, const vImage_Buffer *dest, void *tempBuffer, unsigned int srcOffsetToROI_X, unsigned int srcOffsetToROI_Y, unsigned int kernel_height, unsigned int kernel_width, vImage_Flags flags )    AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;
vImage_Error vImageMax_PlanarF( const vImage_Buffer *src, const vImage_Buffer *dest, void *tempBuffer, unsigned int srcOffsetToROI_X, unsigned int srcOffsetToROI_Y,  unsigned int kernel_height, unsigned int kernel_width, vImage_Flags flags )    AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;
vImage_Error vImageMax_ARGB8888( const vImage_Buffer *src, const vImage_Buffer *dest, void *tempBuffer, unsigned int srcOffsetToROI_X, unsigned int srcOffsetToROI_Y, unsigned int kernel_height, unsigned int kernel_width, vImage_Flags flags )    AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;
vImage_Error vImageMax_ARGBFFFF( const vImage_Buffer *src, const vImage_Buffer *dest, void *tempBuffer, unsigned int srcOffsetToROI_X, unsigned int srcOffsetToROI_Y,  unsigned int kernel_height, unsigned int kernel_width, vImage_Flags flags )    AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;

vImage_Error vImageMin_Planar8( const vImage_Buffer *src, const vImage_Buffer *dest, void *tempBuffer, unsigned int srcOffsetToROI_X, unsigned int srcOffsetToROI_Y, unsigned int kernel_height, unsigned int kernel_width, vImage_Flags flags )    AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;
vImage_Error vImageMin_PlanarF( const vImage_Buffer *src, const vImage_Buffer *dest, void *tempBuffer, unsigned int srcOffsetToROI_X, unsigned int srcOffsetToROI_Y,  unsigned int kernel_height, unsigned int kernel_width, vImage_Flags flags )    AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;
vImage_Error vImageMin_ARGB8888( const vImage_Buffer *src, const vImage_Buffer *dest, void *tempBuffer, unsigned int srcOffsetToROI_X, unsigned int srcOffsetToROI_Y, unsigned int kernel_height, unsigned int kernel_width, vImage_Flags flags )    AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;
vImage_Error vImageMin_ARGBFFFF( const vImage_Buffer *src, const vImage_Buffer *dest, void *tempBuffer, unsigned int srcOffsetToROI_X, unsigned int srcOffsetToROI_Y,  unsigned int kernel_height, unsigned int kernel_width, vImage_Flags flags )    AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


size_t	vImageGetMinimumTempBufferSizeForMinMax( const vImage_Buffer *src, const vImage_Buffer *dest, unsigned int kernel_height, unsigned int kernel_width, vImage_Flags flags, size_t bytesPerPixel )    AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


#ifdef __cplusplus
}
#endif

#endif /* MORPHOLOGY_H */
