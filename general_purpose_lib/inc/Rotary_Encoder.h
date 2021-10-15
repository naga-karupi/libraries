#pragma once

#include<stdint.h>
#include<cmath>

class I_Rotary_Encoder{
public:
    virtual ~I_Rotary_Encoder() = 0;
};

class Arduino_Rotary_Encoder{
    
}

class stm32_Rotary_Encoder : private I_Rotary_Encoder{
    TIMHandleTypeDef*htim;
public:;
    stm32_Rotary_Encoder(TIMHandleTypeDef *_htim):htim(_htim){
        HAL_TIM_Encoder_Start(htim);
    }
    
    uint32_t operator()(){
        uint32_t counter = __HAL_TIM_GET_COUNTER(htim);
        __HAL_TIM_GET_COUNTER(htim) = 0;
        return counter;
    }
}