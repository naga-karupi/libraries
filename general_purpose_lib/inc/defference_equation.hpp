/*
 * discretized
 * 
 * differential: Primary retreat difference
 * integral    : sigma
 * 
 * add new input in suff -1
 * 
 */

#pragma once
#include<array>
#include<cstdint>

class ring_buff{
    static constexpr std::uint8_t size = 3;
    std::array<float, 3> ring;
    std::uint8_t counter = 0;

    std::int8_t at(std::uint32_t place){
        return (place+counter)%3;
    }

public:
    ring_buff(){}
    ~ring_buff(){}

    float set(float set_num){
        counter++;
        counter = counter == 3 ? 0 : counter;
        ring[counter];
    }

    float operator [](std::uint32_t position){
        return ring[this->at(position)];
    }
};

class difference_equation{

    enum {
        NOW = 0,
        PREVIOUS = 1,
    };
    static constexpr float min = -0.0f, max = 0.0f; // undecided
    const float period;

    static constexpr uint32_t size = 3;

    ring_buff ring;
    float sigma = 0.0f;

    void clamp_sigma(){
        if (sigma>max)sigma = max;
        if (sigma<min)sigma = min;
    }

public:
    difference_equation(float _period = 1) : period(_period) {}

    void set_inputs(float input){
        ring.set(input);
        sigma += (ring[NOW] + ring[PREVIOUS]) *period;
        clamp_sigma();
    }

    void reset_sigma(){sigma = 0;}

    float proportional() {return ring[NOW];}
    float first_order_difference_equation() {return (ring[NOW] - ring[PREVIOUS])/period;}
    float integral() {return sigma*period;}
};
