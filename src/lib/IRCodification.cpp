#include "IRCodification.h"
#include <iostream>

namespace IRCodification{
  
uint32_t DecodeOpCode(uint32_t const &instruction){
  return instruction & kOpCodeBitMask;
}

uint32_t DecodeOffset(uint32_t const &op_code){
  return op_code >> kOpCodeNumberOfBits;
}

bool checkIRCodification(){
  bool wellFormed = true;
  
  //LOAD
  wellFormed &= ( kOpCodeNumberOfBits 
                + kRegisterNumberOfBits
                + kLiteralNumberOfBits) <= 32;

  //ADD
  wellFormed &= ( kOpCodeNumberOfBits 
                + kRegisterNumberOfBits*3) <= 32;
  
  std::cout << "mask: " <<kOpCodeBitMask;
               
  return wellFormed;
}

namespace IRBuilder{
  
uint32_t Load(uint32_t const &reg_dst, uint32_t const& literal){
  return IR_LOAD
    + (reg_dst <<  kOpCodeNumberOfBits)
    + (literal << (kOpCodeNumberOfBits + kRegisterNumberOfBits));
}

uint32_t Add(uint32_t const &reg_src1, 
             uint32_t const &reg_src2,
             uint32_t const &reg_dst
            ){
  return IR_ADD 
    + (reg_src1 << kOpCodeNumberOfBits)
    + (reg_src2 << (kOpCodeNumberOfBits + kRegisterNumberOfBits))
    + (reg_dst  << (kOpCodeNumberOfBits + kRegisterNumberOfBits*2));
}

uint32_t Stop(){
  return IR_STOP;
}

}; //namespace IRBuilder

}; //namespace IRCodification