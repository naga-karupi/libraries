#include<array>
#include<cmath>
#include <bits/stdc++.h>
#include"../inc/MD.h"
#include"../inc/rotary_encoder.h"
#include"../inc/PID.h"    


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
		
    	HAL_Delay(10);//control cycle about 100Hz

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