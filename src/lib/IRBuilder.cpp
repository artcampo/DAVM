#include "IRBuilder.hpp"
#include "IRDefinition.hpp"
#include "IRCodification.hpp"
#include <string>
#include <iostream>

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

uint32_t Arith(uint32_t const &reg_src1, uint32_t const &reg_src2,
               uint32_t const &reg_dst, uint32_t const &op){
  return CodeClass3(reg_src1, reg_src2, reg_dst, IR_ARI, op);
}

namespace IRBuilderAPI{
uint32_t Add(uint32_t const &reg_src1, uint32_t const &reg_src2,
             uint32_t const &reg_dst){
  return CodeClass3(reg_src1, reg_src2, reg_dst, IR_ARI, IR_ADD);
}

uint32_t Sub(uint32_t const &reg_src1, uint32_t const &reg_src2,
             uint32_t const &reg_dst){
  return CodeClass3(reg_src1, reg_src2, reg_dst, IR_ARI, IR_SUB);
}

uint32_t Mul(uint32_t const &reg_src1, uint32_t const &reg_src2,
             uint32_t const &reg_dst){
  return CodeClass3(reg_src1, reg_src2, reg_dst, IR_ARI, IR_MUL);             
}


uint32_t Div(uint32_t const &reg_src1, uint32_t const &reg_src2,
             uint32_t const &reg_dst){
  return CodeClass3(reg_src1, reg_src2, reg_dst, IR_ARI, IR_DIV);             
}
}; //namespace IRBuilderAPI

uint32_t Stop(){
  return IR_STOP;
}

// static const std::string opcodes[1][2] = { {"a","b"}};

std::string PrintInstruction(uint32_t const &instruction){
  uint32_t const current_class   = DecodeClass(instruction);
  uint32_t const current_type    = DecodeType(instruction);  
  uint32_t const current_op_code = DecodeOpCode(current_class, current_type);
  uint32_t reg_src1, reg_src2, reg_dst, sub_type, literal, op_offset;
  std::string s;
  
//   std::cout << "Op: " << current_op_code <<"\n";
  //Decode operans
  switch(current_class){
    case InstClassNoReg: break;
    case InstClassRegLit: DecodeClass1(instruction, reg_dst, literal);  break;
    case InstClassRegLitSub: break;
    case InstClassRegRegRegSub:
      DecodeClass3(instruction, reg_src1, reg_src2, reg_dst, 
                    sub_type);
      break;
    
    default: break;
  }
    
  //Produce string
  using namespace std;
  switch(current_op_code){
    case IR_STOP: 
      s = string("Stop"); break;
    case IR_LOAD: 
      s = string("Load, r:") + to_string(reg_dst) + string(" val: ") +
          to_string(literal); 
      break;
    case IR_ARI: 
//       std::cout << "OP "<<sub_type<<"\n";
      switch(sub_type){
        case IR_ADD: s = string("ADD, rs1:"); break;
        case IR_SUB: s = string("SUB, rs1:"); break;
        case IR_MUL: s = string("MUL, rs1:"); break;
        case IR_DIV: s = string("DIV, rs1:"); break;
        default:     s = string(" - ERROR in print decode -"); break;
      }
      s = s + to_string(reg_src1) + string(" rs2: ") +
          to_string(reg_src2) + string(" rd:") + to_string(reg_dst); 
      break;      
    default: s = string(" - ERROR in print decode -"); break;
  };
  
  return s;
}


}; //namespace IRBuilder
