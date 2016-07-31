#pragma once

namespace IRDefinition{

const static int kClassNumberOfBits    = 2;
  const static int kClass0NumberOfBits    = 1;
  const static int kClass1NumberOfBits    = 2;
  const static int kClass2NumberOfBits    = 1;
  const static int kClass3NumberOfBits    = 1;
  const static int kClass0OpcodeNumberOfBits = kClassNumberOfBits + kClass0NumberOfBits;
  const static int kClass1OpcodeNumberOfBits = kClassNumberOfBits + kClass1NumberOfBits;
  const static int kClass2OpcodeNumberOfBits = kClassNumberOfBits + kClass2NumberOfBits;
  const static int kClass3OpcodeNumberOfBits = kClassNumberOfBits + kClass3NumberOfBits;
const static int kRegisterNumberOfBits = 4;
const static int kLiteralNumberOfBits  = 16;
const static int kSubtypeNumberOfBits  = 2;

const static int kClassBitMask =     (1 << kClassNumberOfBits) - 1;  
  const static int kClass0BitMask =  (1 << kClass0NumberOfBits) - 1; 
  const static int kClass1BitMask =  (1 << kClass1NumberOfBits) - 1; 
  const static int kClass2BitMask =  (1 << kClass2NumberOfBits) - 1; 
  const static int kClass3BitMask =  (1 << kClass3NumberOfBits) - 1; 
const static int kRegistertMask =    (1 << kRegisterNumberOfBits) - 1;
const static int kLiteraltMask  =    (1 << kLiteralNumberOfBits) - 1;
const static int kSubtypeMask   =    (1 << kSubtypeNumberOfBits) - 1;

enum InstClasses{
  InstClassNoReg        = 0,
  InstClassRegLit       = 1,
  InstClassRegLitSub    = 2,
  InstClassRegRegRegSub = 3
};

// namespace OpCodes{
enum IRCodf {
  IR_NOP   = InstClassNoReg + (0 << kClassNumberOfBits),
  IR_STOP  = InstClassNoReg + (1 << kClassNumberOfBits),
  
  IR_JMP   = InstClassRegLit + (0 << kClassNumberOfBits),
  IR_LOAD  = InstClassRegLit + (1 << kClassNumberOfBits),
  IR_CALL  = InstClassRegLit + (2 << kClassNumberOfBits),
  
  IR_JMPC  = InstClassRegLitSub + (0 << kClassNumberOfBits),
  IR_ARII  = InstClassRegLitSub + (1 << kClassNumberOfBits),

  IR_ARI   = InstClassRegRegRegSub + (0 << kClassNumberOfBits),
  IR_CMP   = InstClassRegRegRegSub + (1 << kClassNumberOfBits),
};
// };

namespace SubtypesArithmetic{
enum IRSubtypesArithmetic{
  IR_ADD = 0,
  IR_SUB = 1,
  IR_MUL = 2,
  IR_DIV = 3
};
};

namespace SubtypesComparison{
enum IRSubtypesComparison{
  IR_NOT = 0,   // !
  IR_EQL = 1,   // ==
  IR_LST = 2,   // <
  IR_LTE = 3,   // <=    
};
};

enum IRRegisters {
  IR_REG0  = 0,
  IR_REG1  = 1,
  IR_REG2  = 2,
  IR_REG3  = 3,
  IR_REG4  = 4,
  IR_REG5  = 5,
  IR_REG6  = 6,
  IR_REG7  = 7,
  IR_REG8  = 8,
  IR_REG9  = 9,
  IR_REG10 = 10,
  IR_REG11 = 11,
  IR_REG12 = 12,
  IR_REG13 = 13,
  IR_REG14 = 14,
  IR_REG15 = 15
};
  

}; //namespace IRDefinition

