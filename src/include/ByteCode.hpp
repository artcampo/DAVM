#pragma once
#include <stdint.h>
#include <vector>
#include <cstddef>
#include "BasicTypes.hpp"


using VM::Addr;

struct ByteCode{

  std::vector<uint32_t> stream;

  size_t size() const noexcept{ return stream.size();}

  uint32_t GetInst(VM::Addr addr) const { return stream[addr];}
  uint32_t& GetInst(VM::Addr addr){ return stream[addr];}
};
