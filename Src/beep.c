#include "beep.h"


void Beep_Init(void)
{
  GPIO_InitTypeDef GPIO_Initure;   

	BEEP_CLK();
	LED_CLK();
	
	GPIO_Initure.Pin = BEEP_PIN; 				
	GPIO_Initure.Mode = GPIO_MODE_OUTPUT_PP;  	
	GPIO_Initure.Pull = GPIO_PULLUP;          
	GPIO_Initure.Speed = GPIO_SPEED_FREQ_LOW;   
	HAL_GPIO_Init(BEEP_PORT, &GPIO_Initure);

	GPIO_Initure.Pin = LED1_PIN | LED2_PIN; 				
	HAL_GPIO_Init(LED_PORT, &GPIO_Initure);

	BEEP_OF();
	LED1_OF();
	LED2_OF();
}
 
void BEEP_Blink(uint8_t times, uint16_t time_ms)
{
	while(times--)
	{
		BEEP_ON();
		HAL_Delay(time_ms);		
		BEEP_OF();
		HAL_Delay(time_ms);				
	}
}

void LED_Blink(uint8_t times, uint16_t time_ms)
{
	while(times--)
	{
		LED2_ON();
		HAL_Delay(time_ms);		
		LED2_OF();
		HAL_Delay(time_ms);		
		
	}
}


