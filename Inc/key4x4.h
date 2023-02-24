#ifndef __KEY4_4_H
#define __KEY4_4_H	 

#include "stm32f1xx_hal.h"

//8个引脚 4个为行 4个为列
//行输出端口定义
#define X_GPIO_PORT GPIOA           
//列输入端口定义
#define Y_GPIO_PORT GPIOA           

#define X_GPIO_CLK() __HAL_RCC_GPIOA_CLK_ENABLE()
#define Y_GPIO_CLK() __HAL_RCC_GPIOA_CLK_ENABLE()


//行输出引脚定义
#define X1_GPIO_PIN GPIO_PIN_8
#define X2_GPIO_PIN GPIO_PIN_7
#define X3_GPIO_PIN GPIO_PIN_6
#define X4_GPIO_PIN GPIO_PIN_5

//列输入引脚定义
#define Y1_GPIO_PIN GPIO_PIN_9
#define Y2_GPIO_PIN GPIO_PIN_10
#define Y3_GPIO_PIN GPIO_PIN_11
#define Y4_GPIO_PIN GPIO_PIN_12


//移植代码只需要修改上面的端口和引脚和时钟即可，下面的代码不用修改。
//矩阵键盘所用的8个引脚可连续可不连续，看实际需要和个人爱好自己定义。

#define X1_OUT(x) x? HAL_GPIO_WritePin(X_GPIO_PORT,X1_GPIO_PIN, GPIO_PIN_SET): HAL_GPIO_WritePin(X_GPIO_PORT,X1_GPIO_PIN, GPIO_PIN_RESET)
#define X2_OUT(x) x? HAL_GPIO_WritePin(X_GPIO_PORT,X2_GPIO_PIN, GPIO_PIN_SET): HAL_GPIO_WritePin(X_GPIO_PORT,X2_GPIO_PIN, GPIO_PIN_RESET)
#define X3_OUT(x) x? HAL_GPIO_WritePin(X_GPIO_PORT,X3_GPIO_PIN, GPIO_PIN_SET): HAL_GPIO_WritePin(X_GPIO_PORT,X3_GPIO_PIN, GPIO_PIN_RESET)
#define X4_OUT(x) x? HAL_GPIO_WritePin(X_GPIO_PORT,X4_GPIO_PIN, GPIO_PIN_SET): HAL_GPIO_WritePin(X_GPIO_PORT,X4_GPIO_PIN, GPIO_PIN_RESET)

#define Y1_IN()      HAL_GPIO_ReadPin(Y_GPIO_PORT, Y1_GPIO_PIN)
#define Y2_IN()      HAL_GPIO_ReadPin(Y_GPIO_PORT, Y2_GPIO_PIN)
#define Y3_IN()      HAL_GPIO_ReadPin(Y_GPIO_PORT, Y3_GPIO_PIN)
#define Y4_IN()      HAL_GPIO_ReadPin(Y_GPIO_PORT, Y4_GPIO_PIN)


void Key_Init(void);
uint8_t Key_Scan(void);
void Key_Test(void) ;


#endif

