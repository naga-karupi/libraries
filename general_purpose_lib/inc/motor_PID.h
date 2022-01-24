/*
*facade pattern
*/

#include<array>
#include<cmath>
#include<bits/stdc++.h>

#include"MD.h"
#include"rotary_encoder.h"
#include"PID.h"


#ifdef STM32_LIBRARY_NAGA

class motor_PID_stm32 final {
    float now_spd = 0;
    int32_t encoder_val = 0;
    const float frequency ;

    MD_stm*MD;
    stm32_rotary_encoder*encoder;
    PosType_PID*PID;

public:
    motor_PID_stm32(MD_stm*, stm32_rotary_encoder*, PosType_PID*);//builder pattern?

    void operator ()(float);
};

#endif