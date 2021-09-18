#pragma once
#include<math.h>
#include<stdint.h>

class MD_stm{
    const uint16_t Port_A, PIN_A, Port_B, PIN_B, pwm_Channel;
    const void*pwm_Port;
    int pwm;
public:
    template <typename T>
    MD_stm(uint16_t _Port_A, uint16_t _PIN_A, uint16_t _Port_B, uint16_t _PIN_B, void*_pwm_Port, uint16_t _pwm_Channel):Port_A(_Port_A),PIN_A(_PIN_A), Port_B(_Port_B),PIN_B(_PIN_B), pwm_Port(_pwm_Port), pwm_Channel(_pwm_Channel){}
    ~MD_stm() = default;
    void operator =(int re){
        pwm = re;
        HAL_GPIO_WritePin(Port_A, PIN_A, pwm >= 0);
	    HAL_GPIO_WritePin(Port_B, PIN_B, pwm <= 0);
	    __HAL_TIM_SET_COMPARE(pwm_Port, pwm_Channel, pwm);
    }
};