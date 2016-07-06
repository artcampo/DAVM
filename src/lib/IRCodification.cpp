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
  
  //Class 0
  wellFormed &= ( kClassNumberOfBits
                + kClass0NumberOfBits 
                + kRegisterNumberOfBits
                + kLiteralNumberOfBits) <= 32;
 //Class 1
  wellFormed &= ( kClassNumberOfBits
                + kClass1NumberOfBits 
                + kRegisterNumberOfBits
                + kLiteralNumberOfBits) <= 32;

 //Class 2
  wellFormed &= ( kClassNumberOfBits
                + kClass2NumberOfBits 
                + kRegisterNumberOfBits
                + kLiteralNumberOfBits
                + kSubtypeNumberOfBits) <= 32;                
 //Class 3
  wellFormed &= ( kClassNumberOfBits
                + kClass3NumberOfBits 
                + kRegisterNumberOfBits*3
                + kSubtypeNumberOfBits) <= 32;  
                
  return wellFormed;
}

namespace IRBuilder{

uint32_t CodeClass1(uint32_t const &reg_dst, uint32_t const& literal,
                    uint32_t const &type){
  return type
    + (reg_dst << (kClass1OpcodeNumberOfBits))
    + (literal << (kClass1OpcodeNumberOfBits+ kRegisterNumberOfBits));
}

uint32_t Load(uint32_t const &reg_dst, uint32_t const& literal){
  return CodeClass1(reg_dst, literal, IR_LOAD);
}

void DecodeClass1(uint32_t const instruction, uint32_t &reg_dst, 
                uint32_t &literal){
  reg_dst = (instruction >> kClass1OpcodeNumberOfBits) 
            & kRegistertMask;
  literal = (instruction >> (kClass1OpcodeNumberOfBits + kRegisterNumberOfBits))
            & kLiteraltMask;
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

void DecodeAdd(uint32_t const instruction, uint32_t &reg_src1, 
               uint32_t &reg_src2, uint32_t &reg_dst){
  
  reg_src1 = (instruction >> kOpCodeNumberOfBits) & kRegistertMask;
  reg_src2 = (instruction >> (kOpCodeNumberOfBits + kRegisterNumberOfBits))
            & kRegistertMask;
  reg_dst  = (instruction >> (kOpCodeNumberOfBits + kRegisterNumberOfBits*2))
            & kRegistertMask;            
}


uint32_t Stop(){
  return IR_STOP;
}

}; //namespace IRBuilder

}; //namespace IRCodification