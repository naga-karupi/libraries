#pragma once
#include<math.h>
#include"../../Arduino_Library/inc/MD.h"
#include"../../stm32_library/inc/MD.h"

template<class T>
class I_SpeedChange{

protected:
    int TargetSpeed, TargetTime, NowSpeed;
    T MD;

public:
    I_SpeedChange() = default;
    virtual ~I_SpeedChange() = 0;
};

template<class T>
class proportional : virtual public I_SpeedChange<T>{
    
public:
    proportional() = default;
    ~proportional() = default;
    void operator ()(int, int);
};

template<class T> 
class sin{

public:
    sin() = default;
    ~sin() = default;
    void operator ()(int, int);
};

template<class T>
class output : public proportional<T>{

public:
    void set_MD(T _MD){
        I_SpeedChange::MD = _MD;
    }
};