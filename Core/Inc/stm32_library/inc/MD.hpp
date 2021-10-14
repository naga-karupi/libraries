#pragma once

#include<main.h>
#include<cmath>
#include<stdint.h>

class MD_stm{
    GPIO_TypeDef *Port_A; uint16_t PIN_A;
    GPIO_TypeDef *Port_B; uint16_t PIN_B;

    TIM_HandleTypeDef *pwm_Port;
    uint32_t pwm_Channel;

    int pwm;
public:
    MD_stm(GPIO_TypeDef*_Port_A, uint16_t _PIN_A, GPIO_TypeDef*_Port_B, uint16_t _PIN_B, TIM_HandleTypeDef *_pwm_Port, uint32_t _pwm_Channel):
		Port_A(_Port_A),PIN_A(_PIN_A), Port_B(_Port_B),PIN_B(_PIN_B), pwm_Port(_pwm_Port), pwm_Channel(_pwm_Channel){
    	HAL_TIM_PWM_Start(pwm_Port, pwm_Channel);
    }
    ~MD_stm() = default;
    void operator =(int re){
        pwm = re;
        HAL_GPIO_WritePin(Port_A, PIN_A, pwm >= 0 ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(Port_B, PIN_B, pwm <= 0 ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    __HAL_TIM_SET_COMPARE(pwm_Port, pwm_Channel, std::abs(pwm));
    }
    
    void operator ()(int re){
            pwm = re;
            HAL_GPIO_WritePin(Port_A, PIN_A, pwm >= 0 ? GPIO_PIN_SET : GPIO_PIN_RESET);
    	    HAL_GPIO_WritePin(Port_B, PIN_B, pwm <= 0 ? GPIO_PIN_SET : GPIO_PIN_RESET);
    	    __HAL_TIM_SET_COMPARE(pwm_Port, pwm_Channel, std::abs(pwm));
        }
};
