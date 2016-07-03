#include "VM.h"
#include "ByteCode.h"
#include "IRCodification.h"
#include <iostream>

int main(){
  std::unique_ptr<ByteCode> bc(new ByteCode());
  
  using namespace IRCodification;
  using namespace IRBuilder;
  bc->stream = std::vector<uint32_t> {
    Load( IR_REG0, 12),
    Load( IR_REG1, 15),   
  };
  
  std::unique_ptr<VirtualMachine> vm(new VirtualMachine(*bc) );
  
  vm->ExecProcess();
  vm->DumpExecutionContext();
  
  return 0;
}