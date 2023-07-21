#include "etiss/IntegratedLibrary/QVanillaAccelerator.h"

namespace etiss
{

namespace plugin
{

int conv2dnchw(int8_t* q_vanilla_accelerator_0_i0, int8_t* q_vanilla_accelerator_0_i1, int32_t* bias_data, int32_t* compute,
              int32_t oc, int32_t iw, int32_t ih, int32_t ic, int32_t kh, int32_t kw, int32_t i_zp, int32_t k_zp);

void QVanillaAccelerator::write32(uint64_t addr, int32_t val)
{
    uint64_t offset = addr - 0x70000000; 
    *(int32_t*)((intptr_t)&regIf + offset) = val;

    // std::cout << "adr = " << addr << std::endl;
    // std::cout << "val = " << val << std::endl;

    if (offset == 0x00000030) {     //if (regIf.control == 0x00000001)

        // std::cout << regIf.ifmap << ", " << regIf.weights << ", " << regIf.bias << std::endl;
        
        // copy memory from etiss buffer to own buffer
        size_t inputSize = regIf.iw * regIf.ih * regIf.ic * sizeof(int8_t);
        size_t filterSize = regIf.kw * regIf.kh * regIf.ic * regIf.oc * sizeof(int8_t);  
        size_t biasSize = regIf.oc * sizeof(int32_t);       
        size_t resultSize = regIf.iw * regIf.ih * regIf.oc * sizeof(int32_t);
        

        uint8_t* input_buffer = (uint8_t*)malloc(inputSize);
        uint8_t* filter_buffer = (uint8_t*)malloc(filterSize);
        uint8_t* bias_buffer = (uint8_t*)malloc(biasSize);
        uint8_t* result_buffer = (uint8_t*)malloc(resultSize);
        
        int32_t status;
        
        // etiss_int32 (*dread)(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint8 *buffer, etiss_uint32 length);

        status = plugin_system_->dread(plugin_system_->handle, plugin_cpu_, regIf.ifmap, input_buffer, inputSize); //input data  
        if (status != 0) 
          std::cout << "copy ifmap failed!" << std::endl;
        status = plugin_system_->dread(plugin_system_->handle, plugin_cpu_, regIf.weights, filter_buffer, filterSize); //filter data  
        if (status != 0) 
          std::cout << "copy weights failed!" << std::endl;
        status = plugin_system_->dread(plugin_system_->handle, plugin_cpu_, regIf.bias, bias_buffer, biasSize); //biasData 
        if (status != 0) 
          std::cout << "copy bias failed!" << std::endl;
        

        conv2dnchw((int8_t*)input_buffer, (int8_t*)filter_buffer, (int32_t*)bias_buffer, (int32_t*)result_buffer, regIf.oc, regIf.iw, regIf.ih, 
                                       regIf.ic, regIf.kh, regIf.kw, regIf.i_zp, regIf.k_zp);
        
        // copy from own result buffer to etiss memory
        plugin_system_->dwrite(plugin_system_->handle, plugin_cpu_, regIf.result, result_buffer, resultSize);

        // std::cout << "completed!  " << std::endl;
        //free the allocated space
        free(input_buffer);
        free(filter_buffer);
        free(bias_buffer);
        free(result_buffer);
        
    }
}


int32_t QVanillaAccelerator::read32(uint64_t addr)
{
    uint64_t offset = addr - 0x70000000;
    int32_t val = *(int32*)((intptr_t)&regIf + offset);
    // std::cout << "read" << std::endl;
    // std::cout << "adr = " << addr << std::endl;
    // std::cout << "val = " << val << std::endl;
    return val;
}

std::string QVanillaAccelerator::_getPluginName() const 
{ 
    return std::string("QVanillaAccelerator"); 
}


//use the loggger for finding the format of data

int conv2dnchw(int8_t* q_vanilla_accelerator_0_i0, int8_t* q_vanilla_accelerator_0_i1, int32_t* bias_data, int32_t* compute,
                                      int32_t oc, int32_t iw, int32_t ih, int32_t ic, int32_t kh, int32_t kw, int32_t i_zp, int32_t k_zp) {


  // std::cout << "starting the calculation in QVanillaAccelerator" << std::endl;

  int kw_low = kw / 2;
  int kh_low = kh / 2;
  int kw_high = iw + kw / 2;
  int kh_high = ih + kh / 2;

  int padded_iw = iw + 2 * kw_low;
  int padded_ih = ih + 2 * kh_low;

  int32_t* data_pad_let = (int32_t*)malloc(
      (((ic * padded_iw * padded_ih) + (padded_ih * padded_iw)) + padded_iw) * sizeof(int32_t));

  int32_t* compute_let = (int32_t*)malloc((oc * ic * kh * kw) * sizeof(int32_t));

  
  for (int32_t i1_1 = 0; i1_1 < ic; ++i1_1) {
    for (int32_t i2_1 = 0; i2_1 < padded_ih; ++i2_1) {
      for (int32_t i3_1 = 0; i3_1 < padded_iw; ++i3_1) {
        data_pad_let[(((i1_1 * padded_iw * padded_ih) + (i2_1 * padded_iw)) + i3_1)] = (((((kh_low <= i2_1) && (i2_1 < kh_high)) && (kw_low <= i3_1)) && (i3_1 < kw_high)) 
        ? ((int32_t)q_vanilla_accelerator_0_i0[(((i1_1 * iw * ih) + ((i2_1 - kh_low) * iw) + i3_1 - kw_low))] - (i_zp)) 
        : 0);
      }
    }
  }


  for (int32_t i0 = 0; i0 < oc; ++i0) {
    for (int32_t i1_2 = 0; i1_2 < ic; ++i1_2) {
      for (int32_t i2_2 = 0; i2_2 < kh; ++i2_2) {
        for (int32_t i3_2 = 0; i3_2 < kw; ++i3_2) {
          int32_t cse_var_2 = ((((i0 * ic * kh * kw) + (i1_2 * kw * kh)) + (i2_2 * kw)) + i3_2);
          compute_let[cse_var_2] = (((int32_t)q_vanilla_accelerator_0_i1[cse_var_2]) - k_zp);
        }
      }
    }
  }


  for (int32_t oc_ = 0; oc_ < oc; ++oc_) {
    for (int32_t oh = 0; oh < ih; ++oh) {
      for (int32_t ow = 0; ow < iw; ++ow) {
        int32_t cse_var_3 = (((oc_ * ih * iw) + (oh * iw)) + ow);
        for (int32_t ic_ = 0; ic_ < ic; ++ic_) {
          for (int32_t kh_ = 0; kh_ < kh; ++kh_) {
            for (int32_t kw_ = 0; kw_ < kh; ++kw_) {
              // int32_t cse_var_3 = (((oc_ * ih * iw) + (oh * iw)) + ow);
              if (((ic_ == 0) && (kh_ == 0)) && (kw_ == 0)) {
                compute[cse_var_3] = 0;
              }
              compute[cse_var_3] = (compute[cse_var_3] + ((data_pad_let)[(((((ic_ * padded_iw * padded_ih) + (oh * padded_iw)) + (kh_ * padded_iw)) + ow) + kw_)] * (compute_let)[((((oc_ * ic * kh * kw) + (ic_ * kh * kw)) + (kh_ * kw)) + kw_)]));
            }
          }
        }
        compute[cse_var_3] = compute[cse_var_3] + bias_data[oc_]; //bias_add
      }
    }
  }
  // std::cout << " The calculation in QVanillaAccelerator is done!" << std::endl;
  free(data_pad_let);
  free(compute_let);
  return 0;
}

} // namespace plugin

} // namespace etiss

// #include <cstddef>
// #include "etiss/IntegratedLibrary/QVanillaAccelerator.h"

// namespace etiss
// {

// namespace plugin
// {

// int conv2dnchw(int8_t* q_vanilla_accelerator_0_i0, int8_t* q_vanilla_accelerator_0_i1, int32_t* bias_data, int32_t* compute,
//               int32_t oc, int32_t iw, int32_t ih, int32_t ic, int32_t kh, int32_t kw, int32_t i_zp, int32_t k_zp);

// void QVanillaAccelerator::write32(uint64_t addr, uint32_t val)
// {
//     uint64_t offset = addr - base_addr; 
//     // this is the infeed: it is just also "memory", with-out the understand of a sign. it is just like a copy. 
//     size_t reg_index = offset/sizeof(uint32_t);
//     regIf.arr[reg_index] = val;
//     regs_t *p_regs = &regIf.regs;

//     // std::cout << "adr = " << addr << std::endl;
//     // std::cout << "val = " << val << std::endl;

//     // call the "run" function if the control register is written, with a value none zero!
//     if( offset == offsetof(regs_t, control) && p_regs->control != 0UL ) 
//     {
//         // copy memory from etiss buffer to own buffer

//         // std::cout << p_regs->ifmap << ", " << p_regs->weights << ", " << p_regs->bias << std::endl;
//         // MK: can the parameters be negative? if so, what can happen? 
//         size_t inputSize = p_regs->iw * p_regs->ih * p_regs->ic * sizeof(int8_t);
//         size_t filterSize = p_regs->kw * p_regs->kh * p_regs->ic * p_regs->oc * sizeof(int8_t);
//         size_t biasSize = p_regs->oc * sizeof(int32_t);
//         size_t resultSize = p_regs->iw * p_regs->ih * p_regs->oc * sizeof(int32_t);

//         // TODO: MK: turn output into ETISS Info/Warning via ETISS logger!!!??
//         if (inputSize == 0 || filterSize == 0 || biasSize == 0 || resultSize == 0)
//         {
//             std::cout << "Warning: QVanillaAccelerator: sizes are misconfiguered: " << std::endl;
//             std::cout << "         inputSize  : " << inputSize  << std::endl;
//             std::cout << "         filterSize : " << filterSize << std::endl;
//             std::cout << "         biasSize   : " << biasSize   << std::endl;
//             std::cout << "         resultSize : " << resultSize << std::endl;
//             std::cout << "*** QVanillaAccelerator: stop processing!!!" << std::endl;
//             return;
//         }

//         uint8_t* input_buffer = (uint8_t*)malloc(inputSize);
//         uint8_t* filter_buffer = (uint8_t*)malloc(filterSize);
//         uint8_t* bias_buffer = (uint8_t*)malloc(biasSize);
//         uint8_t* result_buffer = (uint8_t*)malloc(resultSize);
        
//         int32_t status;
        
//         // etiss_int32 (*dread)(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint8 *buffer, etiss_uint32 length);

//         status = plugin_system_->dread(plugin_system_->handle, plugin_cpu_, p_regs->ifmap, input_buffer, inputSize); //input data  
//         if (status != 0) 
//           std::cout << "copy ifmap failed!" << std::endl;
//         status = plugin_system_->dread(plugin_system_->handle, plugin_cpu_, p_regs->weights, filter_buffer, filterSize); //filter data  
//         if (status != 0) 
//           std::cout << "copy weights failed!" << std::endl;
//         status = plugin_system_->dread(plugin_system_->handle, plugin_cpu_, p_regs->bias, bias_buffer, biasSize); //biasData 
//         if (status != 0) 
//           std::cout << "copy bias failed!" << std::endl;

//         conv2dnchw((int8_t*)input_buffer, (int8_t*)filter_buffer, (int32_t*)bias_buffer, (int32_t*)result_buffer, p_regs->oc, p_regs->iw, p_regs->ih, 
//                                        p_regs->ic, p_regs->kh, p_regs->kw, p_regs->i_zp, p_regs->k_zp);
 
//         // copy from own result buffer to etiss memory
//         plugin_system_->dwrite(plugin_system_->handle, plugin_cpu_, p_regs->result, result_buffer, resultSize);

//         // std::cout << "completed!  " << std::endl;
//         //free the allocated space
//         free(input_buffer);
//         free(filter_buffer);
//         free(bias_buffer);
//         free(result_buffer);
        
//     }
// }


// uint32_t QVanillaAccelerator::read32(uint64_t addr)
// {

//     uint64_t offset = addr - base_addr; 
//     size_t reg_index = offset/sizeof(uint32_t);
//     uint32_t val = regIf.arr[reg_index];

//     // std::cout << "read" << std::endl;
//     // std::cout << "adr = " << addr << std::endl;
//     // std::cout << "val = " << val << std::endl;
//     return val;
// }

// std::string QVanillaAccelerator::_getPluginName() const 
// { 
//     return std::string("QVanillaAccelerator"); 
// }


// //use the loggger for finding the format of data

// int conv2dnchw(int8_t* q_vanilla_accelerator_0_i0, int8_t* q_vanilla_accelerator_0_i1, int32_t* bias_data, int32_t* compute,
//                                       int32_t oc, int32_t iw, int32_t ih, int32_t ic, int32_t kh, int32_t kw, int32_t i_zp, int32_t k_zp) {


//   // std::cout << "starting the calculation in QVanillaAccelerator" << std::endl;

//   int kw_low = kw / 2;
//   int kh_low = kh / 2;
//   int kw_high = iw + kw / 2;
//   int kh_high = ih + kh / 2;

//   int padded_iw = iw + 2 * kw_low;
//   int padded_ih = ih + 2 * kh_low;

//   int32_t* data_pad_let = (int32_t*)malloc(
//       (((ic * padded_iw * padded_ih) + (padded_ih * padded_iw)) + padded_iw) * sizeof(int32_t));

//   int32_t* compute_let = (int32_t*)malloc((oc * ic * kh * kw) * sizeof(int32_t));

  
//   for (int32_t i1_1 = 0; i1_1 < ic; ++i1_1) {
//     for (int32_t i2_1 = 0; i2_1 < padded_ih; ++i2_1) {
//       for (int32_t i3_1 = 0; i3_1 < padded_iw; ++i3_1) {
//         data_pad_let[(((i1_1 * padded_iw * padded_ih) + (i2_1 * padded_iw)) + i3_1)] = (((((kh_low <= i2_1) && (i2_1 < kh_high)) && (kw_low <= i3_1)) && (i3_1 < kw_high)) 
//         ? ((int32_t)q_vanilla_accelerator_0_i0[((((i1_1 * iw * ih) + (i2_1 * iw)) + i3_1) - kh_high)] - (i_zp)) 
//         : 0);
//       }
//     }
//   }


//   for (int32_t i0 = 0; i0 < oc; ++i0) {
//     for (int32_t i1_2 = 0; i1_2 < ic; ++i1_2) {
//       for (int32_t i2_2 = 0; i2_2 < kh; ++i2_2) {
//         for (int32_t i3_2 = 0; i3_2 < kw; ++i3_2) {
//           int32_t cse_var_2 = ((((i0 * ic * kh * kw) + (i1_2 * kw * kh)) + (i2_2 * kw)) + i3_2);
//           compute_let[cse_var_2] = (((int32_t)q_vanilla_accelerator_0_i1[cse_var_2]) - k_zp);
//         }
//       }
//     }
//   }


//   for (int32_t oc_ = 0; oc_ < oc; ++oc_) {
//     for (int32_t oh = 0; oh < ih; ++oh) {
//       for (int32_t ow = 0; ow < iw; ++ow) {
//         int32_t cse_var_3 = (((oc_ * ih * iw) + (oh * iw)) + ow);
//         for (int32_t ic_ = 0; ic_ < ic; ++ic_) {
//           for (int32_t kh_ = 0; kh_ < kh; ++kh_) {
//             for (int32_t kw_ = 0; kw_ < kh; ++kw_) {
//               // int32_t cse_var_3 = (((oc_ * ih * iw) + (oh * iw)) + ow);
//               if (((ic_ == 0) && (kh_ == 0)) && (kw_ == 0)) {
//                 compute[cse_var_3] = 0;
//               }
//               compute[cse_var_3] = (compute[cse_var_3] + ((data_pad_let)[(((((ic_ * padded_iw * padded_ih) + (oh * padded_iw)) + (kh_ * padded_iw)) + ow) + kw_)] * (compute_let)[((((oc_ * ic * kh * kw) + (ic_ * kh * kw)) + (kh_ * kw)) + kw_)]));
//             }
//           }
//         }
//         compute[cse_var_3] = compute[cse_var_3] + bias_data[oc_]; //bias_add
//       }
//     }
//   }
//   // std::cout << " The calculation in QVanillaAccelerator is done!" << std::endl;
//   free(data_pad_let);
//   free(compute_let);
//   return 0;
// }

// } // namespace plugin

// } // namespace etiss