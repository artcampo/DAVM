#pragma once
#include "ByteCode.h"
#include "Process.h"

#include <string>
#include <memory>


class VirtualMachine{

public:    
  VirtualMachine(const std::string  &file_name);
  VirtualMachine(const ByteCode     &file_name);
  
  bool    ExecProcess();
  void    DumpExecutionContext() const;

private:  
  int     LoadProcess(const std::string &file_name);
  
  std::unique_ptr<ByteCode> byte_code_;
  std::unique_ptr<Process>  process_;
  
  ByteCode* ReadByteCode(const std::string &file_name);
  
};