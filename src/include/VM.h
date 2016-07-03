#pragma once
#include "ByteCode.h"
#include "Process.h"

#include <string>
#include <memory>


class VirtualMachine{

public:    
//   VirtualMachine(std::string const &file_name);
  VirtualMachine(ByteCode const &byte_code);
  
  bool    ExecProcess();
  void    DumpExecutionContext(int const registers_num = 5) const;

private:  
  int     LoadProcess(const std::string &file_name);
  
  ByteCode const &byte_code_;
  std::unique_ptr<Process>  process_;
  
  ByteCode* ReadByteCode(const std::string &file_name);
  
private:
  void InstructionLoad(uint32_t const &current_instruction);
  void InstructionAdd (uint32_t const &current_instruction);
  
};