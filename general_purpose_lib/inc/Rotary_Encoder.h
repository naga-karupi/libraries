#pragma once

#include<stdint.h>
#include<cmath>

#ifdef STM32_LIB_NAGA
#include<main.h>
#endif

#pragma once

#ifndef ROTARY_ENCODER_HEADER
#define ROTARY_ENCODER_HEADER

class I_Rotary_Encoder{
public:
    virtual ~I_Rotary_Encoder() = 0;
};

#ifdef ARDUINO_LIBS_NAGA
class Arduino_Rotary_Encoder{
    
};

#endif

#ifdef STM32_LIB_NAGA

class stm32_Rotary_Encoder : private I_Rotary_Encoder{
    TIM_HandleTypeDef*htim;
public:;
    stm32_Rotary_Encoder(TIM_HandleTypeDef *_htim):htim(_htim){
        HAL_TIM_Encoder_Start(htim, TIM_CHANNEL_ALL);
    }
    
    uint32_t operator()(){
        uint32_t counter = __HAL_TIM_GET_COUNTER(htim);
        __HAL_TIM_GET_COUNTER(htim) = 0;
        return counter;
    }
};

#endif

#endif