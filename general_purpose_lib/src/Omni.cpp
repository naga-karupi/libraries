#include<../inc/Omni.h>

template<typename T>
array<T, 3> Three_Wheel_Omni<T>::operator()(T _x, T _y, T _theta){
    x = _x; y = _y; theta = _theta;
}