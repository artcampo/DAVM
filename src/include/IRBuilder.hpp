#pragma once
#include "IRCodification.hpp"

namespace IRBuilder{

bool        checkIRCodification();
std::string PrintInstruction(uint32_t const &instruction);

using Target = uint32_t;
using Inst   = uint32_t;
using Reg   = uint32_t;

uint32_t Stop();
uint32_t Load(uint32_t const &reg_dst, uint32_t const &literal);

//
uint32_t Arith(uint32_t const &reg_src1, uint32_t const &reg_src2,
               uint32_t const &reg_dst, uint32_t const &op);

uint32_t Comp(uint32_t const &reg_src1, uint32_t const &reg_src2,
               uint32_t const &reg_dst, uint32_t const &op);

Inst Comp(uint32_t const &reg_src1, uint32_t const &reg_src2,
              uint32_t const &reg_dst, uint32_t const &op);


Inst IfElse(Reg const &reg_src1, Target const &target_exit,
            Target const &target_else);
Inst If(Reg const &reg_src1, Target const &target_exit);

//Creates new variable, reg_src1 = TypeId
Inst NewVar(Reg const &reg_src1);

//Register a new typeeId
// reg_src1, typeId
// reg_src2, size of type
Inst NewTypeId(Reg const &reg_src1, Reg const &reg_src2);


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

