/*
 * discretized
 * 
 * differential: Primary retreat difference
 * integral    : sigma
 * 
 * file  : differential_equation.hpp
 * author: naga
 * 
 */

#pragma once

#include<array>
#include<cstdint>
#include<mutex>

#ifndef NAGA_LIBRARIES_DIFFERENCE_EQUATION_HPP__
#define NAGA_LIBRARIES_DIFFERENCE_EQUATION_HPP__

namespace naga_libs{
    class ring_buff{
        static constexpr std::uint8_t size = 3;
        std::array<float, 3> ring;
        std::uint8_t counter = 0;

        std::int8_t at(std::uint32_t place){
            return (place+counter)%3;
        }

    public:
        ring_buff (){}
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

        std::once_flag once;

        static constexpr float min = -10000.0f, max = 10000.0f; // undecided
        float period;

        static constexpr uint32_t size = 3;

        ring_buff ring;
        float sigma = 0.0f;

        void clamp_sigma(){
            if (sigma>max)sigma = max;
            if (sigma<min)sigma = min;
        }

        void set_period_once(float _period){
            period = _period;
        }

    public:
        difference_equation (){}
        ~difference_equation(){}

        void set_period(float _period){
            std::call_once(once, set_period_once, _period);
        }

        void set_inputs(float input){
            ring.set(input);
            sigma += (ring[NOW] + ring[PREVIOUS]) *period;
            clamp_sigma();
        }

        void reset_sigma(){sigma = 0;}

        float proportional() {return ring[NOW];}
        float first_order_difference_equation() {return (ring[NOW] - ring[PREVIOUS])/period;}
        float integral() {return sigma;}
    };
};

#endif //NAGA_LIBRARIES_DIFFERENCE_EQUATION_HPP__
