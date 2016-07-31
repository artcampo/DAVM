#include "VM.hpp"
#include "IRDefinition.hpp"
#include "IRCodification.hpp"
#include "IRBuilder.hpp"
#include "RegisterBank.hpp"
#include <stdint.h>
#include <iostream>

using namespace IRCodification;
using namespace IRBuilder;
  
void VirtualMachine::InstLoad(uint32_t const &reg_dst, uint32_t const &literal){
  std::cout << "LOAD\n";
  process_->execution_context_.registers_.registers[reg_dst] = literal;
}

bool VirtualMachine::InstTypeArihmetic (uint32_t const &reg_src1, 
  uint32_t const &reg_src2, uint32_t const &reg_dst, uint32_t const &sub_type){
  bool error = false;
  using namespace IRDefinition;
  using namespace SubtypesArithmetic;
  switch(sub_type){
    case IR_ADD:  InstAdd(reg_src1, reg_src2, reg_dst); break;
    default:      error_log_->errors.push_back(
                                std::string("ari :: subtype not found")); 
                  error = true;                          break;
  }
  return error;
}
  
void VirtualMachine::InstAdd (uint32_t const &reg_src1, 
  uint32_t const &reg_src2, uint32_t const &reg_dst){
  std::cout << "ADD\n";
  process_->execution_context_.registers_.registers[reg_dst] = 
      process_->execution_context_.registers_.registers[reg_src1]
    + process_->execution_context_.registers_.registers[reg_src2];
}  

void VirtualMachine::InstSub (uint32_t const &reg_src1, 
  uint32_t const &reg_src2, uint32_t const &reg_dst){
  std::cout << "SUB\n";
  process_->execution_context_.registers_.registers[reg_dst] = 
      process_->execution_context_.registers_.registers[reg_src1]
    - process_->execution_context_.registers_.registers[reg_src2];
}  

void VirtualMachine::InstMul (uint32_t const &reg_src1, 
  uint32_t const &reg_src2, uint32_t const &reg_dst){
  std::cout << "MUL\n";
  process_->execution_context_.registers_.registers[reg_dst] = 
      process_->execution_context_.registers_.registers[reg_src1]
    * process_->execution_context_.registers_.registers[reg_src2];
}  

void VirtualMachine::InstDiv (uint32_t const &reg_src1, 
  uint32_t const &reg_src2, uint32_t const &reg_dst){
  std::cout << "DIV\n";
  process_->execution_context_.registers_.registers[reg_dst] = 
      process_->execution_context_.registers_.registers[reg_src1]
    / process_->execution_context_.registers_.registers[reg_src2];
}  