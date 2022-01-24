#pragma once

#define _USE_MATH_DEFINES

#include<stdint.h>
#include<cmath>

#ifdef STM32_LIBRARY_NAGA
#include<main.h>
#endif

#ifndef ROTARY_ENCODER_HEADER
#define ROTARY_ENCODER_HEADER

class I_rotary_encoder{
public:
    virtual ~I_rotary_encoder() = 0;
};


I_rotary_encoder::~I_rotary_encoder(){}

#ifdef ARDUINO_LIBRARY_NAGA

class Arduino_rotary_encoder{
    
};

#endif

#ifdef STM32_LIBRARY_NAGA

class stm32_rotary_encoder : private I_rotary_encoder{
    const size_t encoder_resolution;
    const TIM_HandleTypeDef*htim;
public:;
    stm32_rotary_encoder(size_t arg_resolution, TIM_HandleTypeDef *_htim): encoder_resolution(arg_resolution), htim(_htim){
        HAL_TIM_Encoder_Start(htim, TIM_CHANNEL_ALL);
    }

    size_t getter(){
        return encoder_resolution;
    }
    
    uint32_t operator()(){
        uint32_t counter = __HAL_TIM_GET_COUNTER(htim);
        __HAL_TIM_GET_COUNTER(htim) = 0;
        return counter;
    }
};

#endif
#endif