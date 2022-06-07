//have to include calculus.hpp

#pragma once
#include"difference_equation.hpp"

#ifndef NAGA_LIBRARIES_PID_HPP__
#define NAGA_LIBRARIES_PID_HPP__

namespace naga_libs{
    class I_PID{

    public:
        I_PID() {}
        virtual ~I_PID() = 0;
    };

    class PosType_PID : private I_PID{
        difference_equation difference;
        const float kp, ki, kd;
    public:
        PosType_PID(float _period = 1.0f, float _kp = 0, float _ki = 0, float _kd = 0):kp(_kp), ki(_ki), kd(_kd){}
        float operator()();
    };
};
#endif //NAGA_LIBRARIES_PID_HPP__
