#pragma once

#include<cmath>
#include<stdint.h>

#ifdef STM32_LIB_NAGA
#include<main.h>
#endif

class I_MD{
public:
    virtual ~I_MD() = 0;
};


#ifdef ARDUINO_LIBS_NAGA
class MD_Arduino final : private I_MD{
    const uint8_t PIN_A, PIN_B, pwm_pin;
    int pwm;
public:
    MD_Arduino(uint8_t _PIN_A, uint8_t _PIN_B, uint8_t _pwm_pin):PIN_A(_PIN_A), PIN_B(_PIN_B), pwm_pin(_pwm_pin){}
    ~MD_Arduino() = default;
    void operator =(int re){
        pwm = re;
        digitalWrite(PIN_A, pwm >= 0);
        digitalWrite(PIN_B, pwm <= 0);
        analogWrite(pwm_pin, std::abs(pwm));
    }
};
#endif

#ifdef STM32_LIB_NAGA
class MD_stm final : private I_MD{
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
    void operator =(int32_t re){
        pwm = re;
        HAL_GPIO_WritePin(Port_A, PIN_A, pwm >= 0 ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(Port_B, PIN_B, pwm <= 0 ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    __HAL_TIM_SET_COMPARE(pwm_Port, pwm_Channel, std::abs(pwm));
        void operator ()(int re){
            pwm = re;
            HAL_GPIO_WritePin(Port_A, PIN_A, pwm >= 0 ? GPIO_PIN_SET : GPIO_PIN_RESET);
    	    HAL_GPIO_WritePin(Port_B, PIN_B, pwm <= 0 ? GPIO_PIN_SET : GPIO_PIN_RESET);
    	    __HAL_TIM_SET_COMPARE(pwm_Port, pwm_Channel, std::abs(pwm));
        }
};
#endif
    
