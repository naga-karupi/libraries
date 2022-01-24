#include"../inc/motor_PID.h"

motor_PID_stm32::motor_PID_stm32(MD_stm*_MD, stm32_rotary_encoder*_encoder, PosType*_PID) : MD(_MD), encoder(_encoder), PID(_PID){
    freqency = PID->period;
}

void motor_PID_stm32::operator ()(float target_spd){
    uint32_t _encoder = encoder();

    if (_encoder > 0xffff/2){encoder_val = -(0xffff-_encoder);}

    now_spd = encoder_val * 2 * M_PI / encoder_resolution / frequency;

    float dif_spd = target_spd - now_spd;

    MD = PID(dif_spd);
}