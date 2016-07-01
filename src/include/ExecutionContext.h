#pragma once
#include <stdint.h>
#include "RegisterBank.h"

struct ExecutionContext{
  
  uint32_t                instruction_pointer_;
  RegisterBank<uint32_t>  registers_;

  
};