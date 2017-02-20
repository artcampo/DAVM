#pragma once
#include "IRCodification.hpp"
//TODO:
#include "BasicTypes.hpp"
namespace IRBuilder{

using VM::Addr;
using VM::Inst;
using VM::Target;
using VM::Reg;

bool        checkIRCodification();
std::string PrintInstruction(uint32_t const &instruction);



uint32_t Stop();
uint32_t Load(uint32_t const &reg_dst, uint32_t const &literal);

//
uint32_t Arith(uint32_t const &reg_src1, uint32_t const &reg_src2,
               uint32_t const &reg_dst, uint32_t const &op);

uint32_t Comp(uint32_t const &reg_src1, uint32_t const &reg_src2,
               uint32_t const &reg_dst, uint32_t const &op);

Inst Comp(uint32_t const &reg_src1, uint32_t const &reg_src2,
              uint32_t const &reg_dst, uint32_t const &op);


Inst Jump       (const Target& target);
Inst JumpIfTrue (const Reg& reg_src1, const Target& target);
Inst JumpIfFalse(const Reg& reg_src1, const Target& target);

void PatchJump(Inst& inst, Target const &target);

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

