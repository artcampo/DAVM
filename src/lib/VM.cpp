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
      uint32_t current_op_code = process_->GetCurrentOpCode();
      using namespace IRCodification;
      
      if(current_op_code == IR_STOP){
        executing = false;
      }else{
        process_->NextOpCode();
      }
      
    }
  }
  
  return error;
}

ByteCode* VirtualMachine::ReadByteCode(const std::string &file_name){
  //ByteCode* byte_code = new 
  return 
}


void VirtualMachine::DumpExecutionContext() const{
}

int VirtualMachine::LoadProcess(const std::string &file_name){
  std::unique_ptr<ByteCode> byte_code = ReadByteCode(); 
}