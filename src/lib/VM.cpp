#include "VM.h"
#include "IRCodification.h"
#include "RegisterBank.h"
#include <stdint.h>
#include <iostream>

bool VirtualMachine::ExecProcess(){
  bool executing  = true;
  bool error      = false;
  
  std::cout << "EXEC\n";
  while(executing and not error){
    if( not process_->NextOpCodeIsValid() ){
      error     = true;
      executing = false;
      error_log_->errors.push_back(std::string("Next opcode invalid"));
    }else{
      using namespace IRCodification;
      
      uint32_t current_instruction  = process_->GetCurrentOpCode();
      uint32_t current_op_code      = DecodeOpCode(current_instruction);
      uint32_t op_offset            = DecodeOffset(current_op_code);
      
      std::cout << "inst: " <<current_instruction 
                << " op: " <<current_op_code <<"\n";
      if (current_op_code == IR_STOP){
        executing = false;
      }else{
        
        std::cout << "OP\n";
        bool instructionHasJump = false;
        switch(current_op_code){
          case IR_LOAD: InstructionLoad(current_instruction);  break;
          case IR_ADD:  InstructionAdd(current_instruction);   break;
          default:      error_log_->errors.push_back(std::string("op not found")); 
                        error = true;                          break;
        }
          

        if (not instructionHasJump ) 
          process_->NextOpCode();
        else        
          process_->ModifyIP(op_offset);
      }
      
    }
  }
  
  return error;
}

// VirtualMachine::VirtualMachine(std::string const &file_name){
//   byte_code_ = 
// }

VirtualMachine::VirtualMachine(ByteCode const &byte_code)
  : byte_code_(byte_code)
  , process_(new Process(byte_code_))
  , error_log_( new ErrorLog()){
}

ByteCode* VirtualMachine::ReadByteCode(const std::string &file_name){
  ByteCode* byte_code = new ByteCode();
  return byte_code;
}


void VirtualMachine::DumpExecutionContext(int const registers_num) const{
  if(error_log_->errors.size() == 0)
    process_->DumpExecutionContext(registers_num);
  else{
    std::cout << "Errors in execution:" << std::endl;
    for(auto it : error_log_->errors)
      std::cout << it << "\n";
  }
}

int VirtualMachine::LoadProcess(const std::string &file_name){
  std::unique_ptr<ByteCode> byte_code(ReadByteCode(file_name)); 
}

// #include "VM_instructions_implementation.cpp"
using namespace IRCodification;
using namespace IRBuilder;
  
void VirtualMachine::InstructionLoad(uint32_t const &current_instruction){
  std::cout << "LOAD\n";
  uint32_t reg_dst, literal;
  DecodeLoad(current_instruction, reg_dst, literal);
  process_->execution_context_.registers_.registers[reg_dst] = literal;
}

void VirtualMachine::InstructionAdd (uint32_t const &current_instruction){
  uint32_t reg_src1, reg_src2, reg_dst;
  DecodeAdd(current_instruction, reg_src1, reg_src2, reg_dst);
}
  