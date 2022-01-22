#include<array>
#include<cmath>
#include <bits/stdc++.h>
#include"../Inc/stm32_library/inc/MD.hpp"
#include"../Inc/stm32_library/inc/Rotary_Encoder.h"
#include"../Inc/inc/rad_to_pulse.h"
#include"../Inc/inc/circle.h"
#include"../Inc/inc/PID.h"    


    MD_stm Move_1(IN_A1_GPIO_Port, IN_A1_Pin, IN_B1_GPIO_Port, IN_B1_Pin, &htim1, TIM_CHANNEL_4);
    MD_stm Move_2(IN_A2_GPIO_Port, IN_A2_Pin, IN_B2_GPIO_Port, IN_B2_Pin, &htim1, TIM_CHANNEL_2);

    stm32_Rotary_Encoder Encoder_Right(&htim2);
	stm32_Rotary_Encoder Encoder_Left(&htim3);

	constexpr int rotary_encoder_resolution_r = -800;

	float Ku_r = 800;
	float Tu_r = 0.6;
    PosType_PID PID1(0.01, 3);
    //PosType_PID PID2(0.01, 0.4*Ku_l, 0.5*Tu_l, 0.125*Tu_l);

    constexpr int32_t init_spd_pwm = 0;
	int32_t now_pwm_r = init_spd_pwm;

	std::array<uint32_t, 2> Encoder_Count_r = {0}, Encoder_Count_l = {0};

	float target_spd = 2*M_PI;

	char variable[2]{
		48,//0
		120//x
	};

	char value[5];
	value[4] = 10;
	std::array<int, 4> num;

	int k1 = 1;

	float angular_velocity = 0;

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
uint32_t counter = 0;
uint32_t enc_counter = 0;

    while (1) {
    	HAL_GPIO_TogglePin (LED1_GPIO_Port, LED1_Pin);
    	/*
    	 * rpm/15 = t
    	 * t   : time
    	 * rpm : revolution per minute
    	 * acceleration max : 0.25 [m/s^2]
    	 */

    	HAL_Delay(10);//control cycle about 100Hz

    	TIM_HandleTypeDef*htim = &htim2;

    	enc_counter += __HAL_TIM_GET_COUNTER(htim);
    	counter++;
    	if(counter == 10){//get transmit num
    		num[0] = (0xF000&enc_counter)/0x1000;
    		num[1] = (0x0F00&enc_counter)/0x0100;
    		num[2] = (0x00F0&enc_counter)/0x0010;
			num[3] = (0x000F&enc_counter)/0x0001;

			for(int i = 0; i < 4; i++){
				if(num[i] <= 9 && num[i] >= 0){
					value[i] = num[i] + 48;//num change to character of num
				}else if(num[i] <= 15 && num[i] >= 10){
					value[i] = num[i] + 55;//16 bit num from 10 to 15 change to character of A to F
				}else{
					value[i] = 89;//y
				}
				enc_counter = 0;
				counter = 0;
			}

    		HAL_UART_Transmit(&huart2, (uint8_t*)variable, sizeof(variable), 0xff);

    		HAL_UART_Transmit(&huart2, (uint8_t*)value, sizeof(value), 0xff);

			for(int i = 0; i < 4; i++){
				value[i] = 90;//z
			}
    	}

    	Encoder_Count_r[1] = Encoder_Count_r[0];
    	Encoder_Count_r[0] = Encoder_Right();
    	Encoder_Count_l[1] = Encoder_Count_l[0];
    	Encoder_Count_l[0] = Encoder_Left();

    	k1 = 1;

    	if(Encoder_Count_r[0] > 0xffff/2){
    		Encoder_Count_r[0] = 0xffff - Encoder_Count_r[0];
    		k1 = -1;
    	}

    	angular_velocity = (Encoder_Count_r[0]) * 2*M_PI / rotary_encoder_resolution_r / 0.01*k1;

    	float dif_spd_r = target_spd - angular_velocity;

    	now_pwm_r += PID1(dif_spd_r);

    	Move_1 = now_pwm_r;