#include"../inc/differential.h"


template<typename T>
constexpr differential<T>* differential<T>::operator+(differential*_func){
    re += _func->re;
    im += _func->im;
    return this;
}

template<typename T>
constexpr differential<T>* differential<T>::operator-(differential*_func){
    re -= _func->re;
    im -= _func->im;
    return this;
}

template<typename T>
constexpr differential<T>* differential<T>::operator*(differential*_func){
    re *= _func->re;
    im = _func->re*im + _func->im*re;
    return this;
}

template<typename T>
constexpr differential<T>* differential<T>::operator/(differential*_func){
    re /= _func->re;
    im = (im*_func->re - re*_func->im)/_func->re*_func->re;
    return this;
}