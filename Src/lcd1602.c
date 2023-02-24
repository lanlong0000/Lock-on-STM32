#include "lcd1602.h"
                             
#define DELAY_2N     0

void lcd_delay_us(unsigned int t)
{
	unsigned int i, j;
	
	for(i = 10; i > 0; i--)
		for(j = t; j > 0; j--);
}

void lcd_delay_ms(unsigned int t)
{	
	unsigned int i;
	
	for(i = t; i > 0; i--)
		lcd_delay_us(10);
}

//==================================================
void LCD_Init(void)
{
		GPIO_InitTypeDef GPIO_Initure;   

		LCD_CTRL_CLK();
		LCD_DATA_CLK();
		
		GPIO_Initure.Pin = LCD_RS_PIN|LCD_RW_PIN|LCD_EN_PIN; 				
		GPIO_Initure.Mode = GPIO_MODE_OUTPUT_PP;  	
		GPIO_Initure.Pull = GPIO_PULLUP;          
		GPIO_Initure.Speed = GPIO_SPEED_FREQ_MEDIUM;   
		HAL_GPIO_Init(LCD_CTRL_PORT, &GPIO_Initure);

		GPIO_Initure.Pin = LCD_DATA0_PIN|LCD_DATA1_PIN|LCD_DATA2_PIN|LCD_DATA3_PIN|LCD_DATA4_PIN|LCD_DATA5_PIN|LCD_DATA6_PIN|LCD_DATA7_PIN; 				
		HAL_GPIO_Init(LCD_DATA_PORT, &GPIO_Initure);
	

    LCD_RW(0);			//��дλֱ�ӵ͵�ƽ��ֻд����

    /*********************Һ����ʼ��**************************/        
    lcd_delay_us(340); 
		LCD_RS(0);
   
    LCD_write_cmd(0x38);          // 8bit��ʾģʽ,2��,5x7����
    lcd_delay_ms(4);  
    LCD_write_cmd(0x08);         // ��ʾ�ر� 
    lcd_delay_ms(4); 
    LCD_write_cmd(0x01);         // ��ʾ���� 
    lcd_delay_ms(4); 
    LCD_write_cmd(0x06);         // ��ʾ����ƶ����� 
    lcd_delay_ms(4);
    LCD_write_cmd(0x0c);         // ��ʾ������꿪�������˸
    lcd_delay_ms(4);
		LCD_write_cmd(0x01);         //����
		lcd_delay_ms(4);
}
/*--------------------------------------------------
����˵����д���Һ��


---------------------------------------------------*/
void LCD_write_cmd(unsigned char cmd)
{
    LCD_RS(0);
    LCD_Write_byte(cmd);
    lcd_delay_us(340);
}
/*--------------------------------------------------
����˵����д���ݵ�Һ��


---------------------------------------------------*/
void LCD_write_data(unsigned char w_data)
{
    LCD_RS(1);
    LCD_Write_byte(w_data);
    lcd_delay_us(340);
}
/*--------------------------------------------------
����˵����д4bit��Һ��
--------------------------------------------------*/
void LCD_Write_byte(unsigned char num)
{  
		if (num&0x01)
				data0(1);
		else
				data0(0);

		if (num&0x02)
				data1(1);
		else
				data1(0);

		if (num&0x04)
				data2(1);
		else
				data2(0);

		if (num&0x08)
				data3(1);
		else
				data3(0);

		if (num&0x10)
				data4(1);
		else
				data4(0);

		if (num&0x20)
				data5(1);
		else
				data5(0);

		if (num&0x40)
				data6(1);
		else
				data6(0);
		
		if (num&0x80)
				data7(1);
		else
				data7(0);
		
		lcd_delay_us(340);
    LCD_EN(1);
    lcd_delay_us(340);
    LCD_EN(0); 
    lcd_delay_us(340);
}

/*----------------------------------------------------
LCD_set_xy        : ����LCD��ʾ����ʼλ��
���������x��y    : ��ʾ�ַ�����λ�ã�X:0-15��Y:0-1                
-----------------------------------------------------*/
void LCD_set_xy( unsigned char x, unsigned char y )
{
    unsigned char address = 0;
    if (y==0) 
    {
        address=0x80+x;
    }
    else 
    {
        address=0xc0+x;
    }
//		y ? (address=0xc0+x): (address=0x80+x) ;
    LCD_write_cmd(address);
}
/*---------------------------------------------------
LCD_write_string  : Ӣ���ַ�����ʾ����
���������*s      ��Ӣ���ַ���ָ�룻
          X��Y    : ��ʾ�ַ�����λ��                
---------------------------------------------------*/
void LCD_write_string(unsigned char X,unsigned char Y, char *s)
{
    LCD_set_xy(X,Y);   
    while (*s) 
    {
        LCD_write_data(*s);
        s++;
    }
}

//=======================================================
void LCD_wstring(unsigned char X,unsigned char *s)
{
    LCD_write_cmd(X);   
    while (*s) 
    {
        LCD_write_data(*s);
        s++;
    }
}
