#pragma once
#include "ByteCode.h"
#include <memory>
#include <stdint.h>
  
class Process{
  
public:  
  Process(const ByteCode &byte_code) : byte_code_(byte_code){};
    
  void NextOpCode();
  
  bool      NextOpCodeIsValid() const;
  uint32_t  GetCurrentOpCode() const;

  
private:
  const ByteCode &byte_code_;
};