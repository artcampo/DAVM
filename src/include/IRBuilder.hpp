#pragma once
#include "IRCodification.hpp"

namespace IRBuilder{
  
bool        checkIRCodification();
std::string PrintInstruction(uint32_t const &instruction);

uint32_t Stop();
uint32_t Load(uint32_t const &reg_dst, uint32_t const &literal);
uint32_t Add(uint32_t const &reg_src1, uint32_t const &reg_src2,
             uint32_t const &reg_dst);

uint32_t Mul(uint32_t const &reg_src1, uint32_t const &reg_src2,
             uint32_t const &reg_dst);

}; //namespace IRBuilder

