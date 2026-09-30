# SQType
Simple C++ Q Type Helper for fixed point integer aritmethic
 - Safely handles negative signed numbers
 - Safely handles Multiplication and division
 - Automatic conversion to integer types and decimal types

## Usage
```cpp
#include "SQType.h"
        //type  //fractional bits
  SQType<int16_t, 12> number = 1; //
  float as_float = number; // conversion for things like text.
  number.raw // the raw value, 4096 for 1 in Q12
  s16_q12_t result = number / s16_q12_t(2) // outputs 0.5
```
## Common declarations
```cpp
    using s8_q7_t = SQType<int8_t, 7>;
    using u8_q7_t = SQType<uint8_t, 7>;
    using s8_q4_t = SQType<int8_t, 4>;
    using u8_q4_t = SQType<uint8_t, 4>;

    using s16_q15_t = SQType<int16_t, 15>;
    using u16_q15_t = SQType<uint16_t, 15>;
    using s16_q12_t = SQType<int16_t, 12>;
    using u16_q12_t = SQType<uint16_t, 12>;
    using s16_q10_t = SQType<int16_t, 10>;
    using u16_q10_t = SQType<uint16_t, 10>;

    using s32_q24_t =SQType<int32_t, 24>;
    using u32_q24_t =SQType<uint32_t, 24>;
```