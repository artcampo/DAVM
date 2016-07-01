#include <stdint.h>
#include "registerBank.h"

struct ExecutionContext{
  
  uint32_t                instruction_pointer_;
  RegisterBank<uint32_t>  registers_;

  
};