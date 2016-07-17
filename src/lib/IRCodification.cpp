#include "IRCodification.h"
#include <iostream>

namespace IRCodification{

uint32_t  DecodeClass (uint32_t const &instruction){
  return instruction & kClassBitMask;
}


uint32_t  DecodeType (uint32_t const &instruction){
  if( DecodeClass(instruction) == InstClassNoReg )
    return (instruction >> kClassNumberOfBits) & kClass0BitMask;
  else if( DecodeClass(instruction) == InstClassRegLit )
    return (instruction >> kClassNumberOfBits) & kClass1BitMask;
  else if( DecodeClass(instruction) == InstClassRegLitSub )
    return (instruction >> kClassNumberOfBits) & kClass2BitMask;
 else //if( DecodeClass(instruction) == InstClassRegRegRegSub )
    return (instruction >> kClassNumberOfBits) & kClass3BitMask;
}


uint32_t  DecodeOpCode(uint32_t const &inst_class, uint32_t const &inst_type){
  return inst_class + (inst_type << kClassNumberOfBits);
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

uint32_t CodeClass3(uint32_t const &reg_src1, uint32_t const &reg_src2
                   ,uint32_t const &reg_dst, uint32_t const &type
                   ,uint32_t const &subtype){
  return type
    + (subtype  << (kClass3OpcodeNumberOfBits))
    + (reg_src1 << (kClass3OpcodeNumberOfBits + kSubtypeNumberOfBits))
    + (reg_src2 << (kClass3OpcodeNumberOfBits + kSubtypeNumberOfBits
                    + kRegisterNumberOfBits))
    + (reg_dst  << (kClass3OpcodeNumberOfBits + kSubtypeNumberOfBits
                    + kRegisterNumberOfBits*2));
}

void DecodeClass1(uint32_t const instruction, uint32_t &reg_dst, 
                uint32_t &literal){
  reg_dst = (instruction >> kClass1OpcodeNumberOfBits) 
            & kRegistertMask;
  literal = (instruction >> (kClass1OpcodeNumberOfBits + kRegisterNumberOfBits))
            & kLiteraltMask;
}

void DecodeClass3(uint32_t const instruction, uint32_t &reg_src1
                 ,uint32_t &reg_src2, uint32_t &reg_dst, uint32_t &subtype){
  
  subtype  = (instruction >> (kClass3NumberOfBits + kClassNumberOfBits)) 
           & kSubtypeNumberOfBits;
  reg_src1 = (instruction >> (kClass3NumberOfBits + kClassNumberOfBits 
                              + kSubtypeNumberOfBits)) 
           & kRegistertMask;
  reg_src2 = (instruction >> (kClass3NumberOfBits + kClassNumberOfBits 
                              + kSubtypeNumberOfBits + kRegisterNumberOfBits)) 
           & kRegistertMask;
  reg_dst  = (instruction >> (kClass3NumberOfBits + kClassNumberOfBits 
                              + kSubtypeNumberOfBits + kRegisterNumberOfBits*2))
           & kRegistertMask;            
}


uint32_t Load(uint32_t const &reg_dst, uint32_t const& literal){
  return CodeClass1(reg_dst, literal, IR_LOAD);
}

uint32_t Add(uint32_t const &reg_src1, 
             uint32_t const &reg_src2,
             uint32_t const &reg_dst
            ){
  return CodeClass3(reg_src1, reg_src2, reg_dst, IR_ARI, IR_ADD);
}


uint32_t Stop(){
  return IR_STOP;
}

// static const std::string opcodes[1][2] = { {"a","b"}};
/*
std::string PrintInstruction(uint32_t const &instruction){
  uint32_t const inst_class = DecodeClass(instruction);
  uint32_t const inst_type  = DecodeType(instruction);
  
  return std::string("none");
}
*/

}; //namespace IRBuilder

}; //namespace IRCodification