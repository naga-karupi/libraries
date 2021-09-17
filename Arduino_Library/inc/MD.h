#pragma once
#include<math.h>
#include<stdint.h>

class MD{
    const uint8_t PIN_A, PIN_B, pwm_pin;
    int pwm;
public:
    MD(uint8_t _PIN_A, uint8_t _PIN_B, uint8_t _pwm_pin):PIN_A(_PIN_A), PIN_B(_PIN_B), pwm_pin(_pwm_pin){}
    ~MD() = default;
    void operator =(int re){
        pwm = re;
        digitalWrite(PIN_A, pwm >= 0);
        digitalWrite(PIN_B, pwm <= 0);
        analogWrite(pwm_pin, abs(pwm));
    }
};