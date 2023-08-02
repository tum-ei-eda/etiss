#include <cstddef>
#include "etiss/IntegratedLibrary/VanillaAccelerator.h"

namespace etiss
{

namespace plugin
{

uint32_t conv2dnchw(float* ifmap, float* weights, float* result, int oc, int iw, int ih, int ic,
                        int kh, int kw);

void VanillaAccelerator::write32(uint64_t addr, uint32_t val)
{
    uint64_t offset = addr - base_addr; 
    size_t reg_index = offset/sizeof(uint32_t);
    regIf.arr[reg_index] = val;
    regs_t *p_regs = &regIf.regs;

    // std::cout << "adr = " << addr << std::endl;
    // std::cout << "val = " << val << std::endl;

    // call the "run" function if the control register is written, with a value none zero!
    if( offset == offsetof(regs_t, control) && p_regs->control != 0UL ) 
    {
        // copy memory from etiss buffer to own buffer
       
        size_t inputSize = p_regs->iw * p_regs->ih * p_regs->ic * sizeof(float);
        size_t filterSize = p_regs->kw * p_regs->kh * p_regs->ic * p_regs->oc * sizeof(float);         
        size_t resultSize = p_regs->iw * p_regs->ih * p_regs->oc * sizeof(float);

        float* input_buffer = (float*)malloc(inputSize);  
        float* filter_buffer = (float*)malloc(filterSize);
        float* result_buffer = (float*)malloc(resultSize);
        
        // TODO: MK well, might be best, if we add sanity check for the source address and weights address

        plugin_system_->dread(plugin_system_->handle, plugin_cpu_, p_regs->ifmap, (etiss_uint8 *)input_buffer, inputSize); //input data  
        plugin_system_->dread(plugin_system_->handle, plugin_cpu_, p_regs->weights, (etiss_uint8 *)filter_buffer, filterSize); //filter data   
        // etiss_int32 (*dread)(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint8 *buffer, etiss_uint32 length);
        (void) conv2dnchw(input_buffer, filter_buffer, result_buffer, p_regs->oc, p_regs->iw, p_regs->ih, 
                                       p_regs->ic, p_regs->kh, p_regs->kw);

        plugin_system_->dwrite(plugin_system_->handle, plugin_cpu_, p_regs->result, (etiss_uint8 *)result_buffer, resultSize);

        std::cout << "completed!  " << std::endl;
        //free the allocated space
        free(input_buffer);
        free(filter_buffer);
        free(result_buffer);
        
    }
}


uint32_t VanillaAccelerator::read32(uint64_t addr)
{

    uint64_t offset = addr - base_addr; 
    size_t reg_index = offset/sizeof(uint32_t);
    uint32_t val = regIf.arr[reg_index];

    // std::cout << "read" << std::endl;
    // std::cout << "adr = " << addr << std::endl;
    // std::cout << "val = " << val << std::endl;
    return val;
}

std::string VanillaAccelerator::_getPluginName() const 
{ 
    return std::string("VanillaAccelerator"); 
}


//use the loggger for finding the format of data

uint32_t conv2dnchw(float* ifmap, float* weights, float* result, int oc, int iw, int ih, int ic,
                        int kh, int kw) {


  std::cout << "conv2d function...\n" << std::endl;

  int kw_low = kw / 2;
  int kh_low = kh / 2;
  int kw_high = iw + kw / 2;
  int kh_high = ih + kh / 2;

  int padded_iw = iw + 2 * kw_low;
  int padded_ih = ih + 2 * kh_low;

  // This is only example code. A real hardware accelerator would call a device specific malloc
  // function.
  float* pad_temp = (float*)malloc(
      (((ic * padded_iw * padded_ih) + (padded_ih * padded_iw)) + padded_iw) * sizeof(float));

  if (pad_temp == NULL) {
    return -1;
  }

  for (int i1 = 0; i1 < ic; ++i1) {
    for (int i2 = 0; i2 < padded_ih; ++i2) {
      for (int i3 = 0; i3 < padded_iw; ++i3) {
        ((float*)pad_temp)[(((i1 * padded_iw * padded_ih) + (i2 * padded_iw)) + i3)] =
            (((((kh_low <= i2) && (i2 < kh_high)) && (kw_low <= i3)) && (i3 < kw_high))
                 ? ifmap[((((i1 * iw * ih) + ((i2 - kh_low) * iw)) + i3 - kw_low))]
                 : 0.000000e+00f);
      }
    }
  }
  for (int i11 = 0; i11 < oc; ++i11) {
    for (int i21 = 0; i21 < ih; ++i21) {
      for (int i31 = 0; i31 < iw; ++i31) {
        for (int i4 = 0; i4 < ic; ++i4) {
          for (int i5 = 0; i5 < kh; ++i5) {
            for (int i6 = 0; i6 < kw; ++i6) {
              int cse_var_1 = (((i11 * iw * ih) + (i21 * iw)) + i31);
              if (((i4 == 0) && (i5 == 0)) && (i6 == 0)) {
                result[cse_var_1] = 0.000000e+00f;
              }
              result[cse_var_1] =
                  (result[cse_var_1] +
                   (((float*)
                         pad_temp)[i4 * padded_iw * padded_ih + (i21 + i5) * padded_iw + i31 + i6] *
                    weights[((((i11 * ic * kh * kw) + (i4 * kh * kw)) + (i5 * kw)) + i6)]));
            }
          }
        }
      }
    }
  }

  // This is only example code. A real hardware accelerator would call a device specific free
  // function.
  free(pad_temp);
  std::cout << "done conv2d function...\n" << std::endl;
  return 0;
}

} // namespace plugin

} // namespace etiss
