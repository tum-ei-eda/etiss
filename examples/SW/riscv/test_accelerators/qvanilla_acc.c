
#include "qvanilla_acc.h"


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


uint32_t qvanilla_accelerator_conv2dnchw(int8_t* q_vanilla_accelerator_0_i0, int8_t* q_vanilla_accelerator_0_i1, int32_t* bias_data, int32_t* compute, 
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