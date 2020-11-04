# See LICENSE for license details.

#*****************************************************************************
# add.S
#-----------------------------------------------------------------------------
#
# Test add instruction.
#

#include "riscv_test.h"
#include "test_macros.h"

RVTEST_RV32U
RVTEST_CODE_BEGIN

#define CSR_0 0x0

  #-------------------------------------------------------------
  # Arithmetic tests
  #-------------------------------------------------------------

  TEST_CASE( 2, x2, 0x1234,\
             li x1, 0x1234;\
             csrrw x1, 773, x1;\
             csrrw x2, 773, x0;\
           )  

  TEST_CASE( 3, x3, 0x0,\
             li x1, 0x1234;\
             csrrw x1, 773, x1;\
             csrrw x2, 773, x0;\
             csrrw x3, 773, x0;\
           )  



  TEST_PASSFAIL

RVTEST_CODE_END

  .data
RVTEST_DATA_BEGIN

  TEST_DATA

RVTEST_DATA_END
