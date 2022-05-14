#pragma once

#include"MD.h"
#include"Rotary_Encoder.h"

class I_motor_initializer{
    public:
    virtual ~I_motor_initializer() = 0;
};

class Arduino_Motor_Initializer : public I_motor_initializer{
    
}

class stm32_Motor_Initializer : public I_motor_initializer{
    stm32_Motor_Initializer init;
public:
    stm32_Rotary_Encoder(TIMHandleTypeDef *htim){
        stm32_Motor_Initializer _init(htim);
        &init = _init;
    }

    void operator ()(TIMHandleTypeDef *htim){
        HAL_TIM_START_IT(htim);
    }
}