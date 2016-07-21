#include "Utils.hpp"
#include "ByteCode.hpp"
#include "IRBuilder.hpp"
#include <iostream>

namespace VMUtils{
  
void print(ByteCode const &byte_code){
  using namespace IRBuilder;
  for ( auto const inst : byte_code.stream){
    std::cout << PrintInstruction(inst) << "\n";
  }
}

}; //end namespace VMUtils