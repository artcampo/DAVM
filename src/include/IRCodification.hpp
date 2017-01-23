#pragma once
#include <stdint.h>
#include <string>

namespace IRCodification{
  
uint32_t  DecodeClass (uint32_t const &instruction);
uint32_t  DecodeType  (uint32_t const &instruction, uint32_t const &inst_class);
uint32_t  DecodeOpCode(uint32_t const &inst_class, uint32_t const &inst_type);

uint32_t CodeClass1(uint32_t const &reg_dst, uint32_t const& literal,
                    uint32_t const &type);
void DecodeClass1(uint32_t const instruction, uint32_t &reg_dst, 
                uint32_t &literal);

uint32_t CodeClass3(uint32_t const &reg_src1, uint32_t const &reg_src2
                   ,uint32_t const &reg_dst, uint32_t const &type
                   ,uint32_t const &subtype);
void DecodeClass3(uint32_t const instruction, uint32_t &reg_src1
                 ,uint32_t &reg_src2, uint32_t &reg_dst, uint32_t &subtype);

}; //namespace IRCodification

