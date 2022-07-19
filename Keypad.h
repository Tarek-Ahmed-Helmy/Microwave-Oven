// file written by Mohamed Fathy Mohamed AbdelWahab  1900549
#define NO_PRESS        0xFF

void Keypad_Init(){
	SYSCTL_RCGCGPIO_R|=0x04;
	while((SYSCTL_PRGPIO_R&0x04)==0);
	GPIO_PORTC_LOCK_R = 0x4C4F434B;
	GPIO_PORTC_CR_R |= 0xF0;
	GPIO_PORTC_AMSEL_R &=  ~(0xF0);
	GPIO_PORTC_AFSEL_R &=  ~(0xF0);
	GPIO_PORTC_PCTL_R  &=  ~(0xFFFF0000);
	GPIO_PORTC_DEN_R   |=   (0xF0);

	Port_Init('E');

	Pin_Init_Dir('E', 0, 1);
	Pin_Init_Dir('E', 1, 1);
	Pin_Init_Dir('E', 2, 1);
	Pin_Init_Dir('E', 3, 1);

	GPIO_PORTC_DIR_R &= ~(0xF0);
	Port_PUR_Enable('C', 0xF0);
}
//C is col and E is row
/*
*Note:
*code is written suppossing that the keypad will be connected in portB
*from data sheet of keypad
*connect pin number 8765.... of the keypad to B0B1B2B3... respectively
*to keep the char mapping correct
*/

unsigned char Keypad_Read(){
	unsigned char button_to_char_mapping[4][4] =
	{   {'A','3','2','1'},
		{'B','6','5','4'},
		{'C','9','8','7'},
		{'D','#','0','*'}
	};
	int row, col, button;
	for(row = 0; row < 4; row++){
		GPIO_PORTE_DATA_R = 0x0F; //propagate 1 in rows
		Pin_Write('E', row, 0); // but propagate 0 inside a specific row i know
		for(col = 0; col < 4; col++){
			button = Pin_Read('C', 4 + col);  //col will be connected E0-E3
				if(button == 0){ // if 0 is detected in a specific col i know then i know which row and col is pressed
						//button from col is presesed
						return button_to_char_mapping[row][col];
				}
		}
	}
	return NO_PRESS; //if you loop over every button and no button is pressed then return no press constant
}
