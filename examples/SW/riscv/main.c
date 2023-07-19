#include <stdlib.h>
#include <stdio.h>

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


typedef struct regs 
{
	uint32_t ifmap;   
	uint32_t weights;
	uint32_t bias; 
	uint32_t result;  
	int32_t oc;      
	int32_t iw;      
	int32_t ih;      
	int32_t ic;      
	int32_t kh;      
	int32_t kw; 
	int32_t i_zp;  // Can be negative
	int32_t k_zp;  // Can be negative
	uint32_t control;
} regs_t;


uint32_t qvanilla_accelerator_conv2dnchw(int8_t* q_vanilla_accelerator_0_i0, int8_t* q_vanilla_accelerator_0_i1, 									  int32_t* bias_data, int32_t* compute, 
									  int32_t oc, int32_t iw, int32_t ih, int32_t ic, int32_t kh, int32_t kw, int32_t i_zp, int32_t k_zp) 
{

	regs_t *p_regs  = (regs_t *)0x70000000;  // set the base address of the peripheral, that would come form some hw ip header. 
	p_regs->ifmap   = (uint32_t) q_vanilla_accelerator_0_i0; 
	p_regs->weights = (uint32_t) q_vanilla_accelerator_0_i1;
	p_regs->bias    = (uint32_t) bias_data; 
	p_regs->result  = (uint32_t) compute;  
	
	p_regs->oc = oc;      
	p_regs->iw = iw;      
	p_regs->ih = ih;      
	p_regs->ic = ic;      
	p_regs->kh = kh;      
	p_regs->kw = kw; 
	p_regs->i_zp = i_zp;
	p_regs->k_zp = k_zp;
	p_regs->control = 1;  // last command, to start the operation

	// MK: TODO: well, this implementation provides no status! So we don't know, if that operation was successful!

    return 0;
}



int main()
{
    printf("hello world!\n");

	printf("qvanilla_accelerator test:\n");
	
	int8_t  i0[9] = { 1, 0, 1, 1, 0, 1, 1, 0, 1 };
	int8_t  i1[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	int32_t bias_data[9] = { -1, 0, -1, 1, 0, 1, 1, 0, 1 };
	int32_t result[9];
	
	qvanilla_accelerator_conv2dnchw(i0, i1, bias_data, result, 1, 3, 3, 1, 3, 3, 0, 0);
			
	printf("result: 0x");
	for( int i = 0; i < sizeof(result)/sizeof(int32_t); ++i)
	{
		printf("%08x ", result[i]);
	}
	printf("\n");
}
