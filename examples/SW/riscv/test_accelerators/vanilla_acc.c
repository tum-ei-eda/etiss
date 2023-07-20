#include "vanilla_acc.h"

typedef struct regs 
{
	uint32_t ifmap;   
	uint32_t weights;
	uint32_t result;  
	int32_t oc;      
	int32_t iw;      
	int32_t ih;      
	int32_t ic;      
	int32_t kh;      
	int32_t kw; 
	uint32_t control;
} regs_t;

uint32_t vanilla_accelerator_conv2dnchw(float* ifmap, float* weights, float* result, int oc, int iw, int ih, int ic,
                        int kh, int kw) 
{

	regs_t *p_regs  = (regs_t *)0x70001000;  // set the base address of the peripheral, that would come form some hw ip header. 
	p_regs->ifmap   = (uint32_t) ifmap; 
	p_regs->weights = (uint32_t) weights;
	p_regs->result  = (uint32_t) result;  
	
	p_regs->oc = oc;      
	p_regs->iw = iw;      
	p_regs->ih = ih;      
	p_regs->ic = ic;      
	p_regs->kh = kh;      
	p_regs->kw = kw; 
	p_regs->control = 1;  // last command, to start the operation

	// MK: TODO: well, this implementation provides no status! So we don't know, if that operation was successful!

    return 0;
}