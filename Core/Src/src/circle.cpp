/*
angular is expressed radian method

func name 
~_c -> center
~_r -> radius

if angle is more less pi, natural
if angle is more than pi,  
*/

//define
#define _USE_MATH_DEFINES

//const
static constexpr auto WHEEL_RADIUS = 6;  //tire radius  mm
static constexpr auto WHEEL_WIDTH = 8;   //tire to tire distance  mm
static constexpr auto C_CYCLE = 0.001;       //control cycle (undecided) sec

//inlude
#include<vector>
#include<functional>
#include<stdlib.h>
#include<math.h>

#include"../../Inc/inc/beat_to_sec.h"
#include"../../Inc/inc/circle.h"

//typedef
typedef int mm_int_t;
typedef float rad_t;
typedef float tim_f_t;

//structure

//enum

//global variables

//private 
int pos2::spd_func(tim_f_t sec, int spd_type){

    //lambda array
    std::function<float(tim_f_t)> lambda_func[] = {
        [](tim_f_t sum_sec){return 1.0f;},
        [](tim_f_t sum_sec){return sum_sec;},
        [](tim_f_t sum_sec){return sum_sec*sum_sec;},
        [](tim_f_t sum_sec){return logf(sum_sec);},
        [](tim_f_t sum_sec){return expf(sum_sec);},
    };

    float distance = sec*ave_velocity;

    float sum_sec = 0;
    float increase_sec = sec*C_CYCLE; 
    
    int lambda_num;
    float raito;
    float confitient;

    if(ave_velocity == 0){
        ave_velocity = 1;
    }

    raito = ave_angular_v/ ave_velocity;

    switch(spd_type){
        case CONSTANT_V:
            confitient = distance/sec;
            lambda_num = CONSTANT_V;
            break;
        
        case PROPORTIONAL:
            confitient = 2*distance/(sec*sec);
            lambda_num = PROPORTIONAL;
            break;

        case SQR:
            confitient = 3*distance/(sec*sec*sec);
            lambda_num = SQR;
            break;

        case LOG:
            confitient = distance/((sec+1)*logf(sec+1)-sec);
            lambda_num = LOG;
            break;

        case EXP:
            confitient = distance/(expf(sum_sec)-1);
            lambda_num = EXP;
            break;

        case SIN:
            confitient = distance/1;

            while(sec > sum_sec){
                sum_sec += increase_sec;
                velocity = confitient*sin(sum_sec*2/(sec*M_PI));
                angular_v = velocity*raito;

                MD1 = velocity + angular_v;
                MD2 = velocity - angular_v;
                HAL_Delay(1000*sec*C_CYCLE);
            }

            return 0;
            break;

        default:
            return -1;
            break;
    }

    while(sec > sum_sec){
        sum_sec += increase_sec;
        velocity = confitient*lambda_func[lambda_num](sum_sec);
        angular_v = velocity*raito;

		MD1 = velocity + angular_v;
		MD2 = velocity - angular_v;
		HAL_Delay(sec*1000*C_CYCLE);
    }

	HAL_Delay((uint32_t)(2000));//have to deletes

    return 0;
}

//public func in pos2
void pos2::circle_r(mm_int_t x_coordinate_to, mm_int_t y_coordinate_to, float beat, mm_int_t radius, int spd_type){
    mm_int_t center_x, center_y;
    mm_int_t diff_x, diff_y;

    int bpm;//rewrite

    float sec = 10*beat;

    //tim_f_t sec = beat_to_sec(beat, bpm);

    diff_x = x_coordinate_to - x_coordinate;
    diff_y = y_coordinate_to - y_coordinate;


    rad_t  theta = asinf(sqrtf(diff_x*diff_x + diff_y*diff_y /2 /radius));  //center angle

    angle += theta * 2;                                                     //direction machine

    float n = radius * sinf(theta) / sqrtf(1 + diff_x/diff_y);

    mm_int_t center_x_plus = n + diff_x;                //center x coordinate of circle but there are two answers on caliculation 
    mm_int_t center_y_plus = n * diff_x/diff_y + diff_y;  //center y coordinate of circle
    mm_int_t center_x_minus = -n + diff_x;
    mm_int_t center_y_minus = -n * diff_x/diff_y +diff_y;

    if(!(center_x_plus*x_coordinate_to - center_y_plus*y_coordinate_to)){//because n is scalar
        center_x = center_x_plus;
        center_y = center_y_plus;
    }else{
        center_x = center_x_minus;
        center_y = center_y_minus;
        theta *= -1;
    }

    rad_t angle_change = 2 * theta;

    ave_velocity = (int)(angle * radius / sec);
    ave_angular_v = ave_velocity * WHEEL_RADIUS / WHEEL_WIDTH;
    x_coordinate = x_coordinate_to;
    y_coordinate = y_coordinate_to;
    angle += angle_change;

    spd_func(sec, spd_type);
}//write fin(tentative)

void pos2::circle_c(float beat, mm_int_t radius, rad_t angle_to, mm_int_t c_posi_x, mm_int_t c_posi_y, int spd_type){
    mm_int_t x = x_coordinate - c_posi_x;
    mm_int_t y = y_coordinate - c_posi_y;

    int bpm;//rewrite


    float sec = beat * 10;

    //float sec = beat_to_sec(beat, bpm);

    ave_velocity = (int)(angle_to * radius / sec);
    ave_angular_v = ave_velocity * WHEEL_RADIUS / WHEEL_WIDTH;
    x_coordinate += x * cosf(angle_to) + y * sinf(angle_to);
    y_coordinate += -x * sinf(angle_to) + y * cosf(angle_to
    );
    angle += angle_to;

    spd_func(sec, spd_type);
}//write fin

void pos2::turn(float beat, rad_t angle_to, int spd_type){
    int bpm;//rewrite
    //float sec = beat_to_sec(bpm, beat);
    float sec = beat * 10;
    angle_to-=angle;

    ave_velocity = 0;
    ave_angular_v = 5000;//angle_to / sec;

    angular_v = ave_angular_v;
    
    MD1 = angular_v;
    MD2 = -angular_v;

    HAL_Delay(sec);
}//write fin

void pos2::straight(int beat, mm_int_t coordinate_x_to, mm_int_t coordinate_y_to, int spd_type){
    int bpm;//rewrite
    //float sec = beat_to_sec(bpm, beat);
    float sec = beat* 10;

    coordinate_x_to -= x_coordinate;
    coordinate_y_to -= y_coordinate;

    float distance = sqrtf(coordinate_x_to*coordinate_x_to + coordinate_y_to*coordinate_y_to);
    ave_velocity = (int)distance / sec;
    ave_angular_v = 0;

    spd_func(sec, spd_type);
}//write fin
