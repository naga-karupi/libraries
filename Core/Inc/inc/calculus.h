/*
discretized

differential:Primary retreat difference
integral:sigma

add new input in suff -1

now        : suff + 3
before     : suff + 2
two before : suff + 1
*/

#pragma once
#include<array>

using std::array;

class Difference_Equation{
    static constexpr float min = -100, max = 100;//undecided
    const float period;

    static constexpr uint32_t size = 4;

    uint32_t suff = 0;
    array<float, size> inputs = {0};
    int sigma = 0;

    void reset_sigma(){sigma = 0;}
    void clamp_sigma(){
        if (sigma>max)sigma = max; 
        if (sigma<min)sigma = min;  
    }

    static uint32_t surplus(uint32_t n) {return n&(size-1);}
    float at(int n) const {return inputs[surplus(suff+n)];}

public:
    Difference_Equation(float _period = 1) : period(_period) {}

    void set_inputs(int in){
        suff++;
        inputs[surplus(suff-1)] = in;
        sigma += in;
        clamp_sigma();
    }
    
    float proportional() const{return at(3);}
    float first_order_Difference_Equation() const {return (at(3) - at(2))/period;}
    float second_order_Difference_Equation() const {return (at(3) - 2*at(2) + at(1)) / (period*period);}
    float integral() const {return sigma*period;}
};

