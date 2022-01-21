#include"../inc/Omni.h"
#include"eigen3/Eigen/Dense"

void three_wheel_omni::operator()(float x_spd, float y_spd, float angular_v){
    
}

void four_wheel_omni_1::operator() (float x_spd, float y_spd, float angular_v){
    Eigen::Vector3f input;
    input << x_spd, y_spd, angular_v;

    wheel = omni_matrix * input;
}
