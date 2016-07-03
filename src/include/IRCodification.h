#pragma once
#include <stdint.h>

namespace IRCodification{
  
enum IRCodf {
  IR_NOP   = 0,
  IR_STOP  = 1,
  IR_LOAD  = 2,
  IR_ADD   = 3,
};

enum IRRegisters {
  IR_REG0  = 0,
  IR_REG1  = 1,
  IR_REG2  = 2,
  IR_REG3  = 3,
  IR_REG4  = 4,
  IR_REG5  = 5,
  IR_REG6  = 6,
  IR_REG7  = 7,
  IR_REG8  = 8,
  IR_REG9  = 9,
  IR_REG10 = 10,
  IR_REG11 = 11,
};


const static int kOpCodeNumberOfBits   = 3;
const static int kRegisterNumberOfBits = 4;
const static int kLiteralNumberOfBits  = 16;

const static int kOpCodeBitMask = (1 << kOpCodeNumberOfBits) - 1;
const static int kRegistertMask = (1 << kRegisterNumberOfBits) - 1;
const static int kLiteraltMask  = (1 << kLiteralNumberOfBits) - 1;

uint32_t  DecodeOpCode(uint32_t const &instruction);
uint32_t  DecodeOffset(uint32_t const &op_code);
bool      checkIRCodification();

namespace IRBuilder{
uint32_t Stop();
uint32_t Load(uint32_t const &reg_dst, uint32_t const &literal);
uint32_t Add(uint32_t const &reg_src1, uint32_t const &reg_src2,
             uint32_t const &reg_dst);

void DecodeLoad(uint32_t const instruction, uint32_t &reg_dst, 
                uint32_t &literal);
void DecodeAdd(uint32_t const instruction, uint32_t &reg_src1, 
               uint32_t &reg_src2, uint32_t &reg_dst);



}; //namespace IRBuilder

}; //namespace IRCodification