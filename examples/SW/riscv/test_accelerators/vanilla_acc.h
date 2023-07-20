#include <stdint.h>

/*
\param ifmap Pointer to input feature map data of size iw*ih*ic*sizeof(int8_t). 
\param weights Pointer to weight data of size kh*kw*ic**oc*sizeof(int8_t). 
\param bias_data Pointer to bias data of size oc*sizeof(int32_t). 
\param compute Pointer to output feature map data of size iw*ih*oc*sizeof(int32_t). 
\param oc Number of channels of output feature map. 
\param iw Width of input feature map, ifmap. 
\param ih Height of input feature map, ifmap. 
\param ic Number of channels of input feature map. 
\param kh Height of convolution kernels. 
\param kw Width of convolution kernels.
\param i_zp  
\param k_zp 
*/

uint32_t vanilla_accelerator_conv2dnchw(float* ifmap, float* weights, float* result, int oc, int iw, int ih, int ic, int kh, int kw);
