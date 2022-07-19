
void Clock_Delay(unsigned long delay)  //file written by Tarek Ahmed Helmy 1900759
{
    NVIC_ST_CTRL_R = 0x00;
    NVIC_ST_RELOAD_R = delay -1;
    NVIC_ST_CURRENT_R = 0;
    NVIC_ST_CTRL_R = 0x05;
    while((NVIC_ST_CTRL_R & 0x00010000) == 0);
}

void Wait_1ms(int factor)
{
    int i;
	for(i=0; i<factor; i++)
		Clock_Delay(16000);
}

void Wait_1sec(int factor)
{
	int i;
	for(i=0; i<factor; i++)
		Wait_1ms(1000);
}

void Wait_1min(int number_of_minutes)
{
    int i;  
	for(i=0; i<number_of_minutes; i++)
		Wait_1sec(60);
}
