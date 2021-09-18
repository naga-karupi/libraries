#pragma once
#include<math.h>
#include"../../Arduino_Library/inc/MD.h"
#include"../../stm32_library/inc/MD.h"

class I_SpeedChange{
protected:
    int TargetSpeed, TargetTime;
    static int NowSpeed;

    void set_MD(MD_Arduino);
    void set_MD(MD_stm);

public:
    I_SpeedChange(int _NowSpeed, int _TargetSpeed, int _TargetTime) : TargetSpeed(_TargetSpeed), TargetTime(_TargetTime) {}
    virtual ~I_SpeedChange() = 0;
};


class proportional : private I_SpeedChange{
    
public:
    proportional(int _NowSpeed, int _targetspd, int _targettime) : I_SpeedChange(_NowSpeed,_targetspd, _targettime){}
    ~proportional() = default;
    int operator ()();

    void Cset_MotorDriver();
};