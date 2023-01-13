/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32f1xx_hal.h"

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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define AD_VBAT_Pin GPIO_PIN_3
#define AD_VBAT_GPIO_Port GPIOA
#define SW_Vbat_Pin GPIO_PIN_4
#define SW_Vbat_GPIO_Port GPIOA
#define ON_OFF_Pin GPIO_PIN_5
#define ON_OFF_GPIO_Port GPIOA
#define SIG_CHRG_Pin GPIO_PIN_6
#define SIG_CHRG_GPIO_Port GPIOA
#define PB_UP_Pin GPIO_PIN_0
#define PB_UP_GPIO_Port GPIOB
#define PB_UP_EXTI_IRQn EXTI0_IRQn
#define PB_BACK_Pin GPIO_PIN_1
#define PB_BACK_GPIO_Port GPIOB
#define PB_BACK_EXTI_IRQn EXTI1_IRQn
#define PULSE_WT_Pin GPIO_PIN_10
#define PULSE_WT_GPIO_Port GPIOB
#define PULSE_H2_Pin GPIO_PIN_11
#define PULSE_H2_GPIO_Port GPIOB
#define PB_H2_Pin GPIO_PIN_12
#define PB_H2_GPIO_Port GPIOB
#define PB_H2_EXTI_IRQn EXTI15_10_IRQn
#define PULSE_H4_Pin GPIO_PIN_13
#define PULSE_H4_GPIO_Port GPIOB
#define PB_H4_Pin GPIO_PIN_14
#define PB_H4_GPIO_Port GPIOB
#define PB_H4_EXTI_IRQn EXTI15_10_IRQn
#define PB_DOWN_Pin GPIO_PIN_15
#define PB_DOWN_GPIO_Port GPIOB
#define PB_DOWN_EXTI_IRQn EXTI15_10_IRQn
#define BT_RESET_Pin GPIO_PIN_8
#define BT_RESET_GPIO_Port GPIOA
#define PB_H3_Pin GPIO_PIN_11
#define PB_H3_GPIO_Port GPIOA
#define PB_H3_EXTI_IRQn EXTI15_10_IRQn
#define PULSE_H3_Pin GPIO_PIN_12
#define PULSE_H3_GPIO_Port GPIOA
#define BT_KEY_Pin GPIO_PIN_3
#define BT_KEY_GPIO_Port GPIOB
#define BT_STATUS_Pin GPIO_PIN_4
#define BT_STATUS_GPIO_Port GPIOB
#define PB_H1_Pin GPIO_PIN_5
#define PB_H1_GPIO_Port GPIOB
#define PB_H1_EXTI_IRQn EXTI9_5_IRQn
#define PULSE_H1_Pin GPIO_PIN_8
#define PULSE_H1_GPIO_Port GPIOB
#define PB_MENU_Pin GPIO_PIN_9
#define PB_MENU_GPIO_Port GPIOB
#define PB_MENU_EXTI_IRQn EXTI9_5_IRQn
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
