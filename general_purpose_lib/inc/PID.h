//have to include calculus.h

#pragma once
#include"calculus.h"

#ifdef __cplusplus
extern "C"{
#endif

class I_PID : public Difference_Equation{
protected:
    const float p_gain, i_gain, d_gain;//have to set all positive nums

public:
    I_PID(float _p_gain = 0, float _i_gain = 0, float _d_gain = 0,float _peripd = 1.0f):p_gain(_p_gain), i_gain(_i_gain), d_gain(_d_gain), Difference_Equation(_peripd){}
    virtual ~I_PID() = 0;
};

class PosType_PID : private I_PID{
    
public:
    PosType_PID(float _p_gain = 0, float _i_gain = 0, float _d_gain = 0, float _period = 1.0f):I_PID(_p_gain, _i_gain, _d_gain, _period) {}
    float operator()();
};


class SpeedType_PID : private I_PID{
    
public:
    SpeedType_PID(float _p_gain = 0, float _i_gain = 0, float _d_gain = 0):I_PID(_p_gain, _i_gain, _d_gain){}
    float operator()();
};


#ifdef __cplusplus
};
#endif