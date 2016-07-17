#pragma once
#include "ByteCode.h"
#include "Process.h"
#include "ErrorLog.h"

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
  
  ByteCode const            &byte_code_;
  std::unique_ptr<Process>  process_;
  std::unique_ptr<ErrorLog> error_log_;
  
  ByteCode* ReadByteCode(const std::string &file_name);
  
private:
  void InstructionLoad(uint32_t const &reg_dst, uint32_t const &literal);
  void InstructionAdd (uint32_t const &reg_src1, uint32_t const &reg_src2, 
                       uint32_t const &reg_dst);
  
};