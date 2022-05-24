#include"PID.hpp"

I_PID::~I_PID(){}


float PosType_PID::operator()(){
    const float P = kp*difference.proportional();
    const float I = ki*difference.integral();
    const float D = kd*difference.first_order_difference_equation();
    
    return P+I+D;
}
