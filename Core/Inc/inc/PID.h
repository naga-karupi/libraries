//have to include calculus.h

#pragma once
#include"calculus.h"

class I_PID : public Difference_Equation{
protected:
    const float p_gain, i_gain, d_gain;//have to set all positive nums

public:
    I_PID(float _peripd = 1.0f, float _p_gain = 0, float _i_gain = 0, float _d_gain = 0) :  Difference_Equation(_peripd), p_gain(_p_gain), i_gain(_i_gain), d_gain(_d_gain){}
    virtual ~I_PID() = 0;
};



class PosType_PID : virtual private I_PID{
    
public:
    PosType_PID(float _period = 1.0f, float _p_gain = 0, float _i_gain = 0, float _d_gain = 0):I_PID( _period, _p_gain, _i_gain, _d_gain) {}
    float operator()(int);
};


class SpeedType_PID : virtual private I_PID{
    
public:
    SpeedType_PID(float _period = 1.0f, float _p_gain = 0, float _i_gain = 0, float _d_gain = 0):I_PID(_period ,_p_gain, _i_gain, _d_gain){}
    float operator()(int);
};
