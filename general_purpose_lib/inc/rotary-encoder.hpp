/* 
 * 
 * 
 * 
 * 
*/

#pragma once

#include<stdint.h>
#include<cmath>

#ifndef NAGA_LIBRARIES_ROTARY_ENCODER_HPP__
#define NAGA_LIBRARIES_ROTARY_ENCODER_HPP__

#ifdef ARDUINO_NAGA_LIB
#include<main.h>
#endif //ARDUINO_NAGA_LIB


class I_Rotary_Encoder{
public:
    virtual ~I_Rotary_Encoder() = 0;
};

#ifdef ARDUINO_NAGA_LIB
class Arduino_Rotary_Encoder{
    
};
#endif //ARDUINO_NAGA_LIB

#ifdef STM32_NAGA_LIB
class stm32_Rotary_Encoder : private I_Rotary_Encoder{
    TIM_HandleTypeDef*htim;
public:;
    stm32_Rotary_Encoder(TIM_HandleTypeDef *_htim):htim(_htim){
        HAL_TIM_Encoder_Start(htim, TIM_CHANNEL_ALL);
    }
    
    __attribute__((weak)) uint32_t operator()(){
        uint32_t counter = __HAL_TIM_GET_COUNTER(htim);
        __HAL_TIM_GET_COUNTER(htim) = 0;
        return counter;
    }
};
#endif //STM32_NAGA_LIB
#endif //NAGA_LIBRARIES_ROTARY_ENCODER_HPP__