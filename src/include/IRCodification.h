#pragma once
#include <stdint.h>

namespace IRCodification{
  
enum IRCodf {
  IR_NOP   = 0,
  IR_STOP  = 1,
  IR_LOAD  = 2,
  IR_ADD   = 3,
};

const static int kOpCodeNumberOfBits = 3;
const static int kOpCodeBitMask      = (1 << kOpCodeNumberOfBits) - 1;

uint32_t DecodeOpCode(uint32_t const &instruction){
  return instruction && kOpCodeNumberOfBits;
}

uint32_t DecodeOffset(uint32_t const &op_code){
  return op_code >> kOpCodeNumberOfBits;
}

};