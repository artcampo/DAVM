#include "VM.h"
#include <stdint.h>
#include "IRCodification.h"



bool VirtualMachine::ExecProcess(){
  bool executing  = true;
  bool error      = true;
  
  while(executing and not error){
    if( not process_->NextOpCodeIsValid() ){
      error     = true;
      executing = false;
    }else{
      using namespace IRCodification;
      
      uint32_t current_instruction  = process_->GetCurrentOpCode();
      uint32_t current_op_code      = DecodeOpCode(current_instruction);
      uint32_t op_offset            = DecodeOffset(current_op_code);
      
      if (current_op_code == IR_STOP){
        executing = false;
      }else{
        bool instructionHasJump = false;
        switch(current_op_code){
          case IR_LOAD: InstructionLoad(current_instruction);  break;
          case IR_ADD:  InstructionAdd(current_instruction);   break;
          default:      error = true;                          break;
        }
        if (current_op_code == IR_LOAD){
          
        }else 
          

        if (not instructionHasJump ) 
          process_->NextOpCode();
        else        
          process_->ModifyIP(op_offset);
      }
      
    }
  }
  
  return error;
}

ByteCode* VirtualMachine::ReadByteCode(const std::string &file_name){
  ByteCode* byte_code = new ByteCode();
  return byte_code;
}


void VirtualMachine::DumpExecutionContext() const{
}

int VirtualMachine::LoadProcess(const std::string &file_name){
  std::unique_ptr<ByteCode> byte_code(ReadByteCode(file_name)); 
}