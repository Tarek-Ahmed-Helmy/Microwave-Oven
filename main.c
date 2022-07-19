#include "string.h"
#include "stdbool.h"
#include "tm4c123gh6pm.h"
#include "DigitalIO.h"
#include "Timer.h"
#include "LCD.h"
#include "Keypad.h"
#include "Button.h"
#include "Led.h"

unsigned char sw1,sw2,sw3;
unsigned char finishOvenOperation=0;

void Pause() //function written by Mohamed Fathy Mohamed AbdelWahab  1900549
{    
	Wait_1sec(1);
	while(button_read('F', 4) != 0 && (button_read('F', 0) != 0||button_read('A', 3)!= 1)){LEDs_Blink();};
    while(1)
    {  
        if(button_read('F', 4) == 0)
        {
            finishOvenOperation = 1;
						Leds_off();
            return;
        }
        else if(button_read('F', 0) == 0 && button_read('A', 3) == 1){return;}
	}
}

void Lcd_Shift(char *arr, char time_digit)  //function written by Ismail Salama Abolsoud Saleh 1900093
{
	char i,temp;
	for(i=0;i<4;i++)
    {
        if(arr[i+1]==':')
        {
            temp=arr[i+2];
            arr[i+2]=arr[i];
            arr[i]=temp;
            i+=1;
            continue;
        }
        temp=arr[i+1];
        arr[i+1]=arr[i];
        arr[i]=temp;
    }
    arr[4]=time_digit;
}


void time_format(char * digs,int seconds) // function written by yousef hesham mohamed ahmed 1900416
{
    unsigned char min=0;
    unsigned char time[4]={0};
    while(seconds>=60)
    {
        seconds-=60;
        min++;
    }
    time[0]=(min/10);
    time[1]=(min-(time[0]*10));
    time[2]=(seconds/10);
    time[3]=(seconds-(time[2]*10));

    digs[0]= (time[0]+'0');
    digs[1]= (time[1]+'0');
    digs[3]= (time[2]+'0');
    digs[4]= (time[3]+'0');
}

bool count_down(char * time_digs)  //function written by Tarek Ahmed Helmy 1900759
{
		
    Leds_on();
    while(time_digs[0]!=47)
    {
        while(time_digs[1]!=47)
        {
            while(time_digs[3]!=47)
            {
                while(time_digs[4]!=47)
                {
                    LCD_Clear();
                    LCD_Write_String(time_digs);
                    Wait_1sec(1);
                    time_digs[4]--;
                    if(button_read('f', 4)==0||button_read('a', 3)==0)
                    {
                        Pause();
											Leds_on();
						if(finishOvenOperation==1)
						{
                            finishOvenOperation=0;
														Leds_off();
                            return true;
                        }
                    }
                }
                time_digs[4]='9';
                time_digs[3]--;
            }
            time_digs[3]='5';
            time_digs[1]--;
        }
        time_digs[1]='9';
        time_digs[0]--;
    }
		return false;
}

void A_Popcorn() //function written by yousef hesham mohamed ahmed 1900416
{
	char time_digits[6]="00:00";
    unsigned char cnt=3;  
    
	LCD_Clear();
    LCD_Write_String("Popcorn");
	while(1)
    {
        sw2=button_read('F',0);
        sw3=button_read('A',3);
        if(sw2==0&&sw3==1){break;}
	}
    time_format(time_digits,60);
    if(count_down(time_digits)==true)
    {
        LCD_Clear();
        return;
    }
    LCD_Clear();
    Pin_Write('A',2,1);
    while(cnt--){LEDs_Flash();}
    Pin_Write('A',2,0);
    Leds_off();
}

void B_Beef() // function written by Ismail Salama Abolsoud Saleh 1900093 and Tarek Ahmed Helmy 1900759
{
	char time_digits[6]="00:00";
    unsigned char numOfKilos=0xFF,cnt=3;
    char num[2];
    
	Wait_1ms(200);
	LCD_Clear();
    LCD_Write_String("Beef weight?");
	numOfKilos=Keypad_Read();
	while(numOfKilos==0xFF){numOfKilos=Keypad_Read();}	
	if(numOfKilos<='9'&&numOfKilos>='1')
    {
        num[0]=numOfKilos;
        LCD_Clear();
        LCD_Data(num[0]);
        Wait_1sec(2);
        LCD_Clear();
        sw2=button_read('F',0);
        sw3=button_read('A',3);
        while(1)
        {
            sw2=button_read('F',0);
            sw3=button_read('A',3);
            if(sw2==0&&sw3==1){break;}
        }
        time_format(time_digits,30*(numOfKilos-'0'));
        if(count_down(time_digits))
        {
            LCD_Clear();
            return;
        }
        LCD_Clear();
        Pin_Write('A',2,1);
        while(cnt--){LEDs_Flash();}
        Pin_Write('A',2,0);
        Leds_off();
    }
    else
    {
        LCD_Clear();
        LCD_Write_String("Err");
        Wait_1sec(2);
        LCD_Clear();
        B_Beef();
    }
}

void C_Chicken() // function written by Ismail Salama Abolsoud Saleh 1900093 and Tarek Ahmed Helmy 1900759
{
	char time_digits[6]="00:00";
    unsigned char numOfKilos=0xFF,cnt=3;
    char num[2];
    
	Wait_1ms(200);
	LCD_Clear();
    LCD_Write_String("Chicken weight?");
	numOfKilos=Keypad_Read();
	while(numOfKilos==0xFF){numOfKilos=Keypad_Read();}
	if(numOfKilos<='9'&&numOfKilos>='1')
    {
        num[0]=numOfKilos;
        LCD_Clear();
        LCD_Data(num[0]);
        Wait_1sec(2);
        LCD_Clear();
        sw2=button_read('F',0);
        sw3=button_read('A',3);
        while(1)
        {
            sw2=button_read('F',0);
            sw3=button_read('A',3);
            if(sw2==0&&sw3==1){break;}
        }
        time_format(time_digits,12*(numOfKilos-'0'));
        if(count_down(time_digits))
        {
            LCD_Clear();
            return;
        }
        LCD_Clear();
        Pin_Write('A',2,1);
        while(cnt--){LEDs_Flash();}
        Pin_Write('A',2,0);
        Leds_off();
    }
    else
    {
        LCD_Clear();
        LCD_Write_String("Err");
        Wait_1sec(2);
        LCD_Clear();
        C_Chicken();
    }
}

void D_Cooking_Time() //function written by Mohamed Fathy Mohamed AbdelWahab  1900549
{
	unsigned char time_digit=0xFF;
	unsigned char i=0;
    unsigned char cnt=3;
    char time_digits[6]="00:00";
    
    sw1=1,sw2=1;
    LCD_Clear();
    LCD_Write_String("Cooking time?");
    Wait_1sec(1);
    for(i=0;i<4;i++)
    {
        Wait_1ms(200);
        time_digit=Keypad_Read();
        while(time_digit==0xFF&&button_read('f', 0))
        {
            if(button_read('f', 4)==0)
            {
                LCD_Clear();
				i=-1;
				time_digits[0]='0';
				time_digits[1]='0';
				time_digits[3]='0';
                time_digits[4]='0';
				LCD_Write_String(time_digits);
				continue;
            }
            time_digit=Keypad_Read();
        }
        if(button_read('f', 0)==0){break;}
        Lcd_Shift(time_digits,time_digit);
        if(i==4){break;}
        LCD_Clear();
        LCD_Write_String(time_digits);
        Wait_1sec(1);
        sw2=button_read('F',0);
    }
		while(sw3==0){sw3=button_read('a',3);}
        if(count_down(time_digits))
        {
            LCD_Clear();
            return;
        }
        LCD_Clear();
        Pin_Write('A',2,1);
        while(cnt--){LEDs_Flash();}
        Pin_Write('A',2,0);
        Leds_off();
}



int main() // function written by yousef hesham mohamed ahmed 1900416
{
    unsigned char choice;  
	LCD_Init();
	Keypad_Init();
	Port_Init('f');
	portA_init_for_sw3();
	button_init('f', 0); 
	button_init('f', 4); 
	button_init('a', 3);
	Led_Init('a', 2);
	Led_Init('f', 1);
	Led_Init('f', 2);
	Led_Init('f', 3);
	
	while(1)
    {
        LCD_Write_String("Enter A/B/C/D");
        choice=Keypad_Read();
        while(choice==0xFF){choice=Keypad_Read();}
        switch(choice)
        {
            case 'A':
                A_Popcorn();
                break;
            case 'B':
                B_Beef();
                break;
            case 'C':
                C_Chicken();
                break;
            case 'D':
                D_Cooking_Time();
                break;
            default:
							LCD_Clear();
					      break;
        }
    }
}
