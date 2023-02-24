#ifndef __LCD1602_H
#define __LCD1602_H

#include "stm32f1xx_hal.h"


#define  LCD_CTRL_PORT   GPIOB           
#define  LCD_CTRL_CLK()  __HAL_RCC_GPIOB_CLK_ENABLE()

#define  LCD_DATA_PORT   GPIOB          
#define  LCD_DATA_CLK()  __HAL_RCC_GPIOB_CLK_ENABLE()


#define  LCD_RS_PIN      GPIO_PIN_5
#define  LCD_RW_PIN      GPIO_PIN_6
#define  LCD_EN_PIN      GPIO_PIN_7

#define  LCD_DATA0_PIN   GPIO_PIN_8
#define  LCD_DATA1_PIN   GPIO_PIN_9
#define  LCD_DATA2_PIN   GPIO_PIN_10
#define  LCD_DATA3_PIN   GPIO_PIN_11
#define  LCD_DATA4_PIN   GPIO_PIN_12
#define  LCD_DATA5_PIN   GPIO_PIN_13
#define  LCD_DATA6_PIN   GPIO_PIN_14
#define  LCD_DATA7_PIN   GPIO_PIN_15



#define  LCD_RS(x)  x ?  HAL_GPIO_WritePin(LCD_CTRL_PORT, LCD_RS_PIN,  GPIO_PIN_SET):  HAL_GPIO_WritePin(LCD_CTRL_PORT, LCD_RS_PIN,  GPIO_PIN_RESET)
#define  LCD_RW(x)  x ?  HAL_GPIO_WritePin(LCD_CTRL_PORT, LCD_RW_PIN,  GPIO_PIN_SET):  HAL_GPIO_WritePin(LCD_CTRL_PORT, LCD_RW_PIN,  GPIO_PIN_RESET)
#define  LCD_EN(x)  x ?  HAL_GPIO_WritePin(LCD_CTRL_PORT, LCD_EN_PIN,  GPIO_PIN_SET):  HAL_GPIO_WritePin(LCD_CTRL_PORT, LCD_EN_PIN,  GPIO_PIN_RESET)

#define  data0(x)   x ?  HAL_GPIO_WritePin(LCD_DATA_PORT, LCD_DATA0_PIN,  GPIO_PIN_SET):  HAL_GPIO_WritePin(LCD_DATA_PORT, LCD_DATA0_PIN,  GPIO_PIN_RESET)
#define  data1(x)   x ?  HAL_GPIO_WritePin(LCD_DATA_PORT, LCD_DATA1_PIN,  GPIO_PIN_SET):  HAL_GPIO_WritePin(LCD_DATA_PORT, LCD_DATA1_PIN,  GPIO_PIN_RESET)
#define  data2(x)   x ?  HAL_GPIO_WritePin(LCD_DATA_PORT, LCD_DATA2_PIN,  GPIO_PIN_SET):  HAL_GPIO_WritePin(LCD_DATA_PORT, LCD_DATA2_PIN,  GPIO_PIN_RESET)
#define  data3(x)   x ?  HAL_GPIO_WritePin(LCD_DATA_PORT, LCD_DATA3_PIN,  GPIO_PIN_SET):  HAL_GPIO_WritePin(LCD_DATA_PORT, LCD_DATA3_PIN,  GPIO_PIN_RESET)
#define  data4(x)   x ?  HAL_GPIO_WritePin(LCD_DATA_PORT, LCD_DATA4_PIN,  GPIO_PIN_SET):  HAL_GPIO_WritePin(LCD_DATA_PORT, LCD_DATA4_PIN,  GPIO_PIN_RESET)
#define  data5(x)   x ?  HAL_GPIO_WritePin(LCD_DATA_PORT, LCD_DATA5_PIN,  GPIO_PIN_SET):  HAL_GPIO_WritePin(LCD_DATA_PORT, LCD_DATA5_PIN,  GPIO_PIN_RESET)
#define  data6(x)   x ?  HAL_GPIO_WritePin(LCD_DATA_PORT, LCD_DATA6_PIN,  GPIO_PIN_SET):  HAL_GPIO_WritePin(LCD_DATA_PORT, LCD_DATA6_PIN,  GPIO_PIN_RESET)
#define  data7(x)   x ?  HAL_GPIO_WritePin(LCD_DATA_PORT, LCD_DATA7_PIN,  GPIO_PIN_SET):  HAL_GPIO_WritePin(LCD_DATA_PORT, LCD_DATA7_PIN,  GPIO_PIN_RESET)


void LCD_Init                     (void);
void LCD_write_cmd          (unsigned char cmd);
void LCD_write_data         (unsigned char w_data);
void LCD_Write_byte    (unsigned char half_byte);
void LCD_set_xy             (unsigned char x, unsigned char y);
void LCD_write_string       (unsigned char X,unsigned char Y, char *s);


void LCD_wstring(unsigned char X,unsigned char *s);
//==================================================


void lcd_delay_us(unsigned int t);
void lcd_delay_ms(unsigned int t);



#endif


