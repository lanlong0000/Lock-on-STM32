#ifndef	__BEEP_H
#define __BEEP_H


#include "stm32f1xx_hal.h"

#define  BEEP_CLK()  __HAL_RCC_GPIOA_CLK_ENABLE()
#define  BEEP_PORT   GPIOA           
#define  BEEP_PIN    GPIO_PIN_3

#define  LED_CLK()   __HAL_RCC_GPIOA_CLK_ENABLE()
#define  LED_PORT    GPIOA           
#define  LED1_PIN    GPIO_PIN_1
#define  LED2_PIN    GPIO_PIN_2


/* BEEP Config*/
#define  BEEP_ON()   HAL_GPIO_WritePin(BEEP_PORT, BEEP_PIN, GPIO_PIN_RESET)
#define  BEEP_OF()   HAL_GPIO_WritePin(BEEP_PORT, BEEP_PIN, GPIO_PIN_SET)


/* LED1 Config*/
#define  LED1_ON()    HAL_GPIO_WritePin(LED_PORT,  LED1_PIN,  GPIO_PIN_RESET)
#define  LED1_OF()    HAL_GPIO_WritePin(LED_PORT,  LED1_PIN,  GPIO_PIN_SET)
 
#define  LED1_TOG()   HAL_GPIO_TogglePin(LED_PORT,  LED1_PIN)


/* LED2 Config*/
#define  LED2_ON()    HAL_GPIO_WritePin(LED_PORT,  LED2_PIN,  GPIO_PIN_RESET)
#define  LED2_OF()    HAL_GPIO_WritePin(LED_PORT,  LED2_PIN,  GPIO_PIN_SET)
 
#define  LED2_TOG()   HAL_GPIO_TogglePin(LED_PORT,  LED2_PIN)



void buzzer(void);

void Beep_Init(void);//≥ı ºªØ

void BEEP_Blink(uint8_t times, uint16_t time_ms);
void LED_Blink (uint8_t times, uint16_t time_ms);


#endif
