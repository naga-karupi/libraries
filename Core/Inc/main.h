/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BATT_VOL_Pin GPIO_PIN_0
#define BATT_VOL_GPIO_Port GPIOC
#define IN_A4_Pin GPIO_PIN_1
#define IN_A4_GPIO_Port GPIOC
#define CS3_Pin GPIO_PIN_2
#define CS3_GPIO_Port GPIOC
#define CS4_Pin GPIO_PIN_3
#define CS4_GPIO_Port GPIOC
#define RE_3A_Pin GPIO_PIN_0
#define RE_3A_GPIO_Port GPIOA
#define RE_3B_Pin GPIO_PIN_1
#define RE_3B_GPIO_Port GPIOA
#define UART2TX_Pin GPIO_PIN_2
#define UART2TX_GPIO_Port GPIOA
#define UART2_RX_Pin GPIO_PIN_3
#define UART2_RX_GPIO_Port GPIOA
#define CS1_Pin GPIO_PIN_4
#define CS1_GPIO_Port GPIOA
#define RE_1A_Pin GPIO_PIN_5
#define RE_1A_GPIO_Port GPIOA
#define RE_2B_Pin GPIO_PIN_6
#define RE_2B_GPIO_Port GPIOA
#define RE_2BA7_Pin GPIO_PIN_7
#define RE_2BA7_GPIO_Port GPIOA
#define IN_B4_Pin GPIO_PIN_5
#define IN_B4_GPIO_Port GPIOC
#define CS2_Pin GPIO_PIN_0
#define CS2_GPIO_Port GPIOB
#define LED3_Pin GPIO_PIN_1
#define LED3_GPIO_Port GPIOB
#define LED2_Pin GPIO_PIN_2
#define LED2_GPIO_Port GPIOB
#define LED1_Pin GPIO_PIN_12
#define LED1_GPIO_Port GPIOB
#define LED4_Pin GPIO_PIN_13
#define LED4_GPIO_Port GPIOB
#define subPWM_Pin GPIO_PIN_14
#define subPWM_GPIO_Port GPIOB
#define BUZ_Pin GPIO_PIN_15
#define BUZ_GPIO_Port GPIOB
#define UART6_TX_Pin GPIO_PIN_6
#define UART6_TX_GPIO_Port GPIOC
#define UART6_RX_Pin GPIO_PIN_7
#define UART6_RX_GPIO_Port GPIOC
#define IN_A2_Pin GPIO_PIN_8
#define IN_A2_GPIO_Port GPIOC
#define IN_B2_Pin GPIO_PIN_9
#define IN_B2_GPIO_Port GPIOC
#define MPWM3_Pin GPIO_PIN_8
#define MPWM3_GPIO_Port GPIOA
#define MPWM2_Pin GPIO_PIN_9
#define MPWM2_GPIO_Port GPIOA
#define MPWM4_Pin GPIO_PIN_10
#define MPWM4_GPIO_Port GPIOA
#define MPWM1_Pin GPIO_PIN_11
#define MPWM1_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define IN_A1_Pin GPIO_PIN_15
#define IN_A1_GPIO_Port GPIOA
#define UART3_TX_Pin GPIO_PIN_10
#define UART3_TX_GPIO_Port GPIOC
#define UART3_RX_Pin GPIO_PIN_11
#define UART3_RX_GPIO_Port GPIOC
#define IN_B1_Pin GPIO_PIN_2
#define IN_B1_GPIO_Port GPIOD
#define RE_1B_Pin GPIO_PIN_3
#define RE_1B_GPIO_Port GPIOB
#define IN_A3_Pin GPIO_PIN_4
#define IN_A3_GPIO_Port GPIOB
#define IN_B3_Pin GPIO_PIN_5
#define IN_B3_GPIO_Port GPIOB
#define RE_4A_Pin GPIO_PIN_6
#define RE_4A_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
