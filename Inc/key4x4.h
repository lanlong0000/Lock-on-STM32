#ifndef __KEY4_4_H
#define __KEY4_4_H	 

#include "stm32f1xx_hal.h"

//8������ 4��Ϊ�� 4��Ϊ��
//������˿ڶ���
#define X_GPIO_PORT GPIOA           
//������˿ڶ���
#define Y_GPIO_PORT GPIOA           

#define X_GPIO_CLK() __HAL_RCC_GPIOA_CLK_ENABLE()
#define Y_GPIO_CLK() __HAL_RCC_GPIOA_CLK_ENABLE()


//��������Ŷ���
#define X1_GPIO_PIN GPIO_PIN_8
#define X2_GPIO_PIN GPIO_PIN_7
#define X3_GPIO_PIN GPIO_PIN_6
#define X4_GPIO_PIN GPIO_PIN_5

//���������Ŷ���
#define Y1_GPIO_PIN GPIO_PIN_9
#define Y2_GPIO_PIN GPIO_PIN_10
#define Y3_GPIO_PIN GPIO_PIN_11
#define Y4_GPIO_PIN GPIO_PIN_12


//��ֲ����ֻ��Ҫ�޸�����Ķ˿ں����ź�ʱ�Ӽ��ɣ�����Ĵ��벻���޸ġ�
//����������õ�8�����ſ������ɲ���������ʵ����Ҫ�͸��˰����Լ����塣

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

