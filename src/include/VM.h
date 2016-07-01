#include "ByteCode.h"
#include "Process.h"


class VirtualMachine{
  
  VirtualMachine(const std::string  &file_name);
  VirtualMachine(const ByteCode     &file_name);
  
public:  
  
  bool    ExecProcess();
  void    DumpExecutionContext() const;

private:  
  int     LoadProcess(const std::string &file_name);
  
  std::unique_ptr<ByteCode> byte_code_;
  std::unique_ptr<Process>  process_;
  
};