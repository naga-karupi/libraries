#pragma once

#include<array>

class difference_equation{
    static constexpr float min = -100, max = 100;//undecided
    const float period;

    static constexpr uint32_t size = 3;

    uint32_t suff = 0;
    std::array<float, size> inputs = {0};
    int sigma = 0;

    void reset_sigma(){sigma = 0;}
    void clamp_sigma(){
        if (sigma>max)sigma = max; 
        if (sigma<min)sigma = min;  
    }

    static uint32_t surplus(uint32_t n) {return n&(size-1);}
    float at(int n) const {return inputs[surplus(suff+n)];}//i dont know

public:
    difference_equation(float _period = 1) : period(_period) {}

    void set_inputs(float in){
        suff++;
        inputs[surplus(suff-1)] = in;
        sigma += (at(3) + at(2))/2*period;
        clamp_sigma();
    }
    
    float proportional() const{return at(3);}
    float first_order_Difference_Equation() const {return (at(3) - at(2))/period;}
    float second_order_Difference_Equation() const {return (at(3) - 2*at(2) + at(1)) / (period*period);}
    float integral() const {return sigma;}
};

