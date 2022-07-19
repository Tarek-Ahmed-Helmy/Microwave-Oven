
void Led_Init(char portName, unsigned char pinNumber)  //file written by Ismail Salama Abolsoud Saleh 1900093
{
	
	Pin_Init_Dir(portName, pinNumber, 1);
}

void Led_On(char portName, unsigned char pinNumber)
{
	Pin_Write(portName, pinNumber, 1);
}


void Led_Off(char portName, unsigned char pinNumber)
{
	Pin_Write(portName, pinNumber, 0);
}

void Led_Tog(char portName, unsigned char pinNumber)
{
	Pin_Write(portName, pinNumber, !Pin_Read(portName, pinNumber));
}

void Leds_on(){
	Led_On('f', 1);
	Led_On('f', 2);
	Led_On('f', 3);
}

void Leds_off(){
	Led_Off('f', 1);
	Led_Off('f', 2);
	Led_Off('f', 3);
}

void LEDs_ON(){
    Pin_Write('f', 1, 1);
    Pin_Write('f', 2, 1);
    Pin_Write('f', 3, 1);
}

void LEDs_OFF(){
    Pin_Write('f', 1, 0);
    Pin_Write('f', 2, 0);
    Pin_Write('f', 3, 0);
}

void LEDs_Blink(){
    LEDs_ON();
    Wait_1ms(50);
    LEDs_OFF();
    Wait_1ms(50);
}

void LEDs_Flash(){
    LEDs_ON();
    Wait_1ms(500);
    LEDs_OFF();
    Wait_1ms(500);
}
