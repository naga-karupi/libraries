#pragma once

#include"../../Core/Inc/stm32_library/inc/MD.hpp"

//typedef
typedef int mm_int_t;
typedef float rad_t;
typedef float tim_f_t;

//enum
enum func{
    CONSTANT_V,
    PROPORTIONAL,
    SQR,
    LOG,
    EXP,
    SIN
};

class pos2 {
    mm_int_t ave_velocity = 0;
    mm_int_t ave_angular_v = 0;
    mm_int_t velocity = 0;
    mm_int_t angular_v = 0;
    mm_int_t x_coordinate = 0;
    mm_int_t y_coordinate = 0;
    rad_t angle = 0;

    MD_stm MD1, MD2;

    int spd_func(tim_f_t sec, int spd_type);

public:
    pos2(MD_stm _MD1, MD_stm _MD2) : MD1(_MD1), MD2(_MD2){}
    void circle_r(mm_int_t x_coordinate_to, mm_int_t y_coordinate_to, float beat, mm_int_t radius, int spd_type);
    void circle_c(float beat, mm_int_t radius, rad_t angle_to, mm_int_t c_posi_x, mm_int_t c_posi_y, int spd_type);
    void turn(float beat, rad_t angle_to, int spd_type);
    void straight(int beat, mm_int_t coordinate_x_to, mm_int_t coordinate_y_to, int spd_type);
};
