#pragma once
#include "IRCodification.hpp"

namespace IRBuilder{
  
bool        checkIRCodification();
std::string PrintInstruction(uint32_t const &instruction);

uint32_t Stop();
uint32_t Load(uint32_t const &reg_dst, uint32_t const &literal);

//
uint32_t Arith(uint32_t const &reg_src1, uint32_t const &reg_src2,
               uint32_t const &reg_dst, uint32_t const &op);

uint32_t Comp(uint32_t const &reg_src1, uint32_t const &reg_src2,
               uint32_t const &reg_dst, uint32_t const &op);

namespace IRBuilderAPI{
// These should not be used by compiler, only direct API
uint32_t Add(uint32_t const &reg_src1, uint32_t const &reg_src2,
             uint32_t const &reg_dst);
uint32_t Sub(uint32_t const &reg_src1, uint32_t const &reg_src2,
             uint32_t const &reg_dst);
uint32_t Mul(uint32_t const &reg_src1, uint32_t const &reg_src2,
             uint32_t const &reg_dst);
uint32_t Div(uint32_t const &reg_src1, uint32_t const &reg_src2,
             uint32_t const &reg_dst);

}; //namespace IRBuilderAPI

}; //namespace IRBuilder

