#pragma once
#include "ByteCode.h"
#include <memory>
#include <stdint.h>
  
class Process{
  
  const ByteCode &byte_code_;
  
  Process(const ByteCode &byteCode) : byte_code_(byte_code){};
  
  void NextOpCode();
  
  bool      NextOpCodeIsValid() const;
  uint32_t  GetCurrentOpCode() const;

};