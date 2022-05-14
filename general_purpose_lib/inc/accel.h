//要再プログラム

#pragma once
#include<cmath>
#include"../../Arduino_Library/inc/MD.h"
#include"../../stm32_library/inc/MD.h"

class I_SpeedChange{

protected:
    int TargetSpeed, TargetTime, NowSpeed;

public:
    virtual ~I_SpeedChange() = 0;
};

class proportional : virtual public I_SpeedChange{
    
public:
    void operator()(int, int);
};

class sin : virtual public I_SpeedChange{

public:
    void operator()(int, int);
};

class output : public proportional, public sin{

public:
    output(T*_MD){
        I_SpeedChange<T>::MD = _MD;
    }
    ~output() = default;
};