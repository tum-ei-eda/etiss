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

uint32_t qvanilla_accelerator_conv2dnchw(int8_t* q_vanilla_accelerator_0_i0, int8_t* q_vanilla_accelerator_0_i1, int32_t* bias_data, int32_t* compute, 
									  int32_t oc, int32_t iw, int32_t ih, int32_t ic, int32_t kh, int32_t kw, int32_t i_zp, int32_t k_zp);
