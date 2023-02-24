#include "key4x4.h"


void Key_Init(void)
{
  GPIO_InitTypeDef GPIO_Initure;   

	X_GPIO_CLK();
	Y_GPIO_CLK();
	
/*****************************4行输出*********************************************/
	GPIO_Initure.Pin = X1_GPIO_PIN|X2_GPIO_PIN|X3_GPIO_PIN|X4_GPIO_PIN; 				
	GPIO_Initure.Mode = GPIO_MODE_OUTPUT_PP;  	
	GPIO_Initure.Pull = GPIO_NOPULL;          
	GPIO_Initure.Speed = GPIO_SPEED_FREQ_LOW;   
	HAL_GPIO_Init(X_GPIO_PORT, &GPIO_Initure);
   
/**************************************4列输入*************************************/
	GPIO_Initure.Pin = Y1_GPIO_PIN; 				
	GPIO_Initure.Mode = GPIO_MODE_INPUT;  	
	GPIO_Initure.Pull = GPIO_NOPULL;          
	GPIO_Initure.Speed = GPIO_SPEED_FREQ_LOW;   
	HAL_GPIO_Init(Y_GPIO_PORT, &GPIO_Initure);

	GPIO_Initure.Pin = Y2_GPIO_PIN; 				
	HAL_GPIO_Init(Y_GPIO_PORT, &GPIO_Initure);

	GPIO_Initure.Pin = Y3_GPIO_PIN; 				
	HAL_GPIO_Init(Y_GPIO_PORT, &GPIO_Initure);

	GPIO_Initure.Pin = Y4_GPIO_PIN; 				
	HAL_GPIO_Init(Y_GPIO_PORT, &GPIO_Initure);
}

uint8_t Key_Scan(void)
{
   uint8_t KeyVal = 27;
	 uint8_t Y1 = 0, Y2 = 0, Y3 = 0, Y4 = 0;
	
   X1_OUT(1);  //先让X1输出高
   X2_OUT(1);  //先让X2输出高
   X3_OUT(1);  //先让X3输出高
   X4_OUT(1);  //先让X4输出高


		if( (Y1_IN() | Y2_IN() | Y3_IN() | Y4_IN()) == 0 )
		{		
			return 27; //如果X1到X4全为零则没有按键按下 
		}		
		else
		{	
			HAL_Delay(5); //延时5ms去抖动
			if( (Y1_IN() | Y2_IN() | Y3_IN() | Y4_IN()) == 0 )
				return 27;
		}

    
/*1********************************************************/	 
    X1_OUT(1); X2_OUT(0); X3_OUT(0); X4_OUT(0);
   
    Y1 = Y1_IN(); Y2 = Y2_IN(); Y3 = Y3_IN(); Y4 = Y4_IN();

		if(Y1==1&&Y2==0&&Y3==0&&Y4==0)
        KeyVal=1;
		if(Y1==0&&Y2==1&&Y3==0&&Y4==0)
				KeyVal=5;
		if(Y1==0&&Y2==0&&Y3==1&&Y4==0)
				KeyVal=9;
		if(Y1==0&&Y2==0&&Y3==0&&Y4==1)
				KeyVal=13;       
		//等待按键释放
    while( (Y1_IN() | Y2_IN() | Y3_IN() | Y4_IN()) > 0 );
		

/*2********************************************************/	 
    X1_OUT(0); X2_OUT(1); X3_OUT(0); X4_OUT(0);
        
    Y1 = Y1_IN(); Y2 = Y2_IN(); Y3 = Y3_IN(); Y4 = Y4_IN();

		if(Y1==1&&Y2==0&&Y3==0&&Y4==0)
					KeyVal=2;
		if(Y1==0&&Y2==1&&Y3==0&&Y4==0)
					KeyVal=6;
		if(Y1==0&&Y2==0&&Y3==1&&Y4==0)
					KeyVal=0;
		if(Y1==0&&Y2==0&&Y3==0&&Y4==1)
					KeyVal=14;    		
    //等待按键释放
    while( (Y1_IN() | Y2_IN() | Y3_IN() | Y4_IN()) > 0 );

		 
/*3********************************************************/	 
    X1_OUT(0); X2_OUT(0); X3_OUT(1); X4_OUT(0);

    Y1 = Y1_IN(); Y2 = Y2_IN(); Y3 = Y3_IN(); Y4 = Y4_IN();
		 
		if(Y1==1&&Y2==0&&Y3==0&&Y4==0)
					KeyVal=3;
		if(Y1==0&&Y2==1&&Y3==0&&Y4==0)
					KeyVal=7;
		if(Y1==0&&Y2==0&&Y3==1&&Y4==0)
					KeyVal=11;
		if(Y1==0&&Y2==0&&Y3==0&&Y4==1)
					KeyVal=15;		
    //等待按键释放
    while( (Y1_IN() | Y2_IN() | Y3_IN() | Y4_IN()) > 0 );

/*4********************************************************/	 
		X1_OUT(0); X2_OUT(0); X3_OUT(0); X4_OUT(1);

		Y1 = Y1_IN(); Y2 = Y2_IN(); Y3 = Y3_IN(); Y4 = Y4_IN();

		if(Y1==1&&Y2==0&&Y3==0&&Y4==0)
            KeyVal=4;
    if(Y1==0&&Y2==1&&Y3==0&&Y4==0)
            KeyVal=8;
    if(Y1==0&&Y2==0&&Y3==1&&Y4==0)
            KeyVal=12;
    if(Y1==0&&Y2==0&&Y3==0&&Y4==1)
            KeyVal=16;		
    //等待按键释放
    while( ( Y1_IN() | Y2_IN() | Y3_IN() | Y4_IN() ) > 0 );

		 
		return KeyVal;
}

