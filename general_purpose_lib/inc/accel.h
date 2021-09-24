#pragma once
#include<math.h>
#include"../../Arduino_Library/inc/MD.h"
#include"../../stm32_library/inc/MD.h"

template<class T>
class I_SpeedChange{

protected:
    int TargetSpeed, TargetTime, NowSpeed;
    const T*MD;

public:
    virtual ~I_SpeedChange() = 0;
};

template<class T>
class proportional : virtual public I_SpeedChange<T>{
    
public:
    void operator()(int, int);
};

template<class T> 
class sins : virtual public I_SpeedChange<T>{

public:
    void operator()(int, int);
};

template<class T>
class output : public proportional<T>, public sins<T>{

public:
    output(T*_MD){
        I_SpeedChange<T>::MD = _MD;
    }
    ~output() = default;
};