  //file written by Tarek Ahmed Helmy 1900759
#define LCD_CLR         0X01 
#define DATAPORT        'B'
#define CTRLPORT        'A'
#define RS              5    
#define RW              6
#define EN              7
#define EIGHT_BITS      0x38
#define LCD_ENTRYMODE	0x06
#define CURSOR_ON       0x0F


static void Send_Pulse(void)
{
    Pin_Write(CTRLPORT,EN,1);
    Wait_1ms(2);
    Pin_Write(CTRLPORT,EN,0);
    Wait_1ms(2);
}

void LCD_Command(unsigned char command)
{
    Port_Write(DATAPORT,command);
    Pin_Write(CTRLPORT,RS,0);
    Send_Pulse();
    Wait_1ms(1);
}

void LCD_Data(unsigned char character)
{
    Port_Write(DATAPORT, character);
    Pin_Write(CTRLPORT, RS, 1);
    Send_Pulse();
    Wait_1ms(1);
}

void LCD_Write_String(char* data)
{
    while((*data) != '\0')
    {
        LCD_Data((*data));
        data++;
    }
}

void LCD_Clear()
{
    LCD_Command(LCD_CLR);
    Wait_1ms(10);
}

void Move_Cursor(char row, char column)
{
    char position=0;
    if(row==1){position = 0x80 + column -1;}
    else if(row==2){position = 0xC0 + column -1;}
    else position = 0x80;
    
    LCD_Command(position);
    Wait_1ms(1);
}

void LCD_Init(void)
{
    SET_BIT(SYSCTL_RCGCGPIO_R,1);
    while((SYSCTL_PRGPIO_R&(0x02)) == 0);
	GPIO_PORTB_LOCK_R = 0x4C4F434B;
	GPIO_PORTB_CR_R |= 0xFF;
	GPIO_PORTB_AMSEL_R &=  ~(0xFF);
	GPIO_PORTB_AFSEL_R &=  ~(0xFF);
	GPIO_PORTB_PCTL_R  &=  ~(0xFFFFFFFF);
	GPIO_PORTB_DEN_R   |=   (0xFF);
	
	SET_BIT(SYSCTL_RCGCGPIO_R,0);
	while((SYSCTL_PRGPIO_R&(0x01)) == 0);
	GPIO_PORTA_LOCK_R = 0x4C4F434B;
	GPIO_PORTA_CR_R |= 0xFF;
	GPIO_PORTA_AMSEL_R &=  ~(0xFF);
	GPIO_PORTA_AFSEL_R &=  ~(0xFF);
	GPIO_PORTA_PCTL_R  &=  ~(0xFFFFFFFF);
	GPIO_PORTA_DEN_R   |=   (0xFF);
	
    GPIO_PORTA_DIR_R |= 0xFF;
    GPIO_PORTB_DIR_R |= 0xFF;
    
    CLR_BIT(GPIO_PORTA_DATA_R, RW);

    LCD_Command(0x38);
    Wait_1ms(1);
    LCD_Command(CURSOR_ON);
    Wait_1ms(1);
    LCD_Command(LCD_CLR);
    Wait_1ms(10);
    LCD_Command(LCD_ENTRYMODE);
}
