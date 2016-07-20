#include "IRBuilder.h"
#include "IRDefinition.h"
#include "IRCodification.h"
#include <string>

namespace IRBuilder{

using namespace IRDefinition;
using namespace IRCodification;

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


using namespace SubtypesArithmetic;

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
