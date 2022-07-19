
void button_init(char portName, unsigned char pinNumber)  //file written by Ismail Salama Abolsoud Saleh 1900093
{
	
	Pin_Init_Dir(portName, pinNumber, 0);
	
}

void button_init_PUR(char portName, unsigned char pinNumber)
{
	
	Pin_Init_Dir(portName, pinNumber, 0);
	Port_PUR_Enable(portName, pinNumber);
}


unsigned char button_read(char portName, unsigned char pinNumber)
{
	return Pin_Read(portName, pinNumber);
}
