#include "Process.h"

void Process::NextOpCode(){
  execution_context_.instruction_pointer_++;
}

bool Process::NextOpCodeIsValid() const{
  return (execution_context_.instruction_pointer_ >= 0 and
          execution_context_.instruction_pointer_ < byte_code_.stream.size() );
}

// PRE: NextOpCodeIsValid() is true
uint32_t Process::GetCurrentOpCode() const{
  return byte_code_.stream[execution_context_.instruction_pointer_];
}

void Process::ModifyIP(uint32_t const &offset){
  execution_context_.instruction_pointer_++;
  execution_context_.instruction_pointer_ += offset;
}