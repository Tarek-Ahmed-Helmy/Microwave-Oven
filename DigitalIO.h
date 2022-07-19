#include "tm4c123gh6pm.h"  //file written by Mohamed Fathy Mohamed AbdelWahab  1900549
#include "stdint.h"
#define SET_BIT(reg, bit)				reg |= (1<<bit)
#define CLR_BIT(reg, bit)				reg &= (~(1<<bit))
#define TOG_BIT(reg, bit)				reg ^= (1<<bit)
#define READ_BIT(reg, bit)			    ((reg&(1<<bit)) >> bit)



void Pin_Init_Dir(char portName, unsigned char pinNumber, unsigned char dir){
	switch(portName){
case 'A':
case 'a': {
				 if(dir == 1) SET_BIT(GPIO_PORTA_DIR_R, pinNumber);
				 else 				CLR_BIT(GPIO_PORTA_DIR_R,pinNumber);
break;
}
case 'B':
case 'b': {
				 if(dir == 1) SET_BIT(GPIO_PORTB_DIR_R, pinNumber);
				 else 				CLR_BIT(GPIO_PORTB_DIR_R,pinNumber);
break;
}
case 'C':
case 'c': {
				 if(dir == 1) SET_BIT(GPIO_PORTC_DIR_R, pinNumber);
				 else 				CLR_BIT(GPIO_PORTC_DIR_R,pinNumber);
break;
}
case 'D':
case 'd': {
				 if(dir == 1) SET_BIT(GPIO_PORTD_DIR_R, pinNumber);
				 else 				CLR_BIT(GPIO_PORTD_DIR_R,pinNumber);
break;
}
case 'E':
case 'e': {
				 if(dir == 1) SET_BIT(GPIO_PORTE_DIR_R, pinNumber);
				 else 				CLR_BIT(GPIO_PORTE_DIR_R,pinNumber);
break;
}
case 'F':
case 'f': {
				 if(dir == 1) SET_BIT(GPIO_PORTF_DIR_R, pinNumber);
				 else 				CLR_BIT(GPIO_PORTF_DIR_R,pinNumber);
break;
}
	}

}

void Port_Init_Dir(char portName, unsigned char dir){
	switch(portName){
case 'A':
case 'a': {
				 if(dir == 1) GPIO_PORTA_DIR_R |= 0xFF;
				 else 				GPIO_PORTA_DIR_R &= ~(0xFF);
break;
}
case 'B':
case 'b': {
				 if(dir == 1) GPIO_PORTB_DIR_R |= 0xFF;
				 else 				GPIO_PORTB_DIR_R &= ~(0xFF);
break;
}
case 'C':
case 'c': {
				 if(dir == 1) GPIO_PORTC_DIR_R |= 0xFF;
				 else 				GPIO_PORTC_DIR_R &= ~(0xFF);
break;
}
case 'D':
case 'd': {
				 if(dir == 1) GPIO_PORTD_DIR_R |= 0xFF;
				 else 				GPIO_PORTD_DIR_R &= ~(0xFF);
break;
}
case 'E':
case 'e': {
				 if(dir == 1) GPIO_PORTE_DIR_R |= 0xFF;
				 else 				GPIO_PORTE_DIR_R &= ~(0xFF);
break;
}
case 'F':
case 'f': {
				 if(dir == 1) GPIO_PORTF_DIR_R |= 0xFF;
				 else 				GPIO_PORTF_DIR_R &= ~(0xFF);
break;
}

	}
}

void Port_Init(char portName){
	switch(portName){
case 'A':
case 'a': {
				 SET_BIT(SYSCTL_RCGCGPIO_R,0);
				 while((SYSCTL_PRGPIO_R&(0x01)) == 0);
				 GPIO_PORTA_LOCK_R = 0x4C4F434B;
				 GPIO_PORTA_CR_R |= 0xFF;
				 GPIO_PORTA_AMSEL_R &=  ~(0xFF);
				 GPIO_PORTA_AFSEL_R &=  ~(0xFF);
				 GPIO_PORTA_PCTL_R  &=  ~(0xFFFFFFFF);
				 GPIO_PORTA_DEN_R   |=   (0xFF);
break;
}
case 'B':
case 'b': {
				 SET_BIT(SYSCTL_RCGCGPIO_R,1);
				 while((SYSCTL_PRGPIO_R&(0x02)) == 0);
				 GPIO_PORTB_LOCK_R = 0x4C4F434B;
				 GPIO_PORTB_CR_R |= 0xFF;
				 GPIO_PORTB_AMSEL_R &=  ~(0xFF);
				 GPIO_PORTB_AFSEL_R &=  ~(0xFF);
				 GPIO_PORTB_PCTL_R  &=  ~(0xFFFFFFFF);
				 GPIO_PORTB_DEN_R   |=   (0xFF);
break;
}
case 'C':
case 'c': {
				 SET_BIT(SYSCTL_RCGCGPIO_R,2);
				 while((SYSCTL_PRGPIO_R&(0x04)) == 0);
				 GPIO_PORTC_LOCK_R = 0x4C4F434B;
				 GPIO_PORTC_CR_R |= 0xFF;
				 GPIO_PORTC_AMSEL_R &=  ~(0xFF);
				 GPIO_PORTC_AFSEL_R &=  ~(0xFF);
				 GPIO_PORTC_PCTL_R  &=  ~(0xFFFFFFFF);
				 GPIO_PORTC_DEN_R   |=   (0xFF);
break;
}
case 'D':
case 'd': {
				 SET_BIT(SYSCTL_RCGCGPIO_R,3);
				 while((SYSCTL_PRGPIO_R&(0x08)) == 0);
				 GPIO_PORTD_LOCK_R = 0x4C4F434B;
				 GPIO_PORTD_CR_R |= 0xFF;
				 GPIO_PORTD_AMSEL_R &=  ~(0xFF);
				 GPIO_PORTD_AFSEL_R &=  ~(0xFF);
				 GPIO_PORTD_PCTL_R  &=  ~(0xFFFFFFFF);
				 GPIO_PORTD_DEN_R   |=   (0xFF);
break;
}
case 'E':
case 'e': {
				 SET_BIT(SYSCTL_RCGCGPIO_R,4);
				 while((SYSCTL_PRGPIO_R&(0x10)) == 0);
				 GPIO_PORTE_LOCK_R = 0x4C4F434B;
				 GPIO_PORTE_CR_R |= 0xFF;
				 GPIO_PORTE_AMSEL_R &=  ~(0xFF);
				 GPIO_PORTE_AFSEL_R &=  ~(0xFF);
				 GPIO_PORTE_PCTL_R  &=  ~(0xFFFFFFFF);
				 GPIO_PORTE_DEN_R   |=   (0xFF);
break;
}
case 'F':
case 'f': {
				 SYSCTL_RCGCGPIO_R|=0x20; //INTIALIZE THE CLOCK OF PORTF
				while((SYSCTL_PRGPIO_R & 0x20)==0); //delay
				GPIO_PORTF_LOCK_R = 0x4C4F434B; //Constant value
				GPIO_PORTF_AMSEL_R &=~0x1F; //disable analog function
				GPIO_PORTF_CR_R |= 0x1F; //setting pin p0->4 to change
				GPIO_PORTF_PCTL_R &=~0x000FFFFF; //enable digital function
				GPIO_PORTF_AFSEL_R &=~0x1F; //disable alterante function
				GPIO_PORTF_DIR_R &=~0x11; //DIR--> 0->input & 1->output
				GPIO_PORTF_PUR_R |=0x11; //active low
				GPIO_PORTF_DEN_R |= 0x1F; //Enable digital for sw2
				break;
}
	}
}
void Pin_Write(char portName, unsigned char pinNumber, unsigned char data){
	switch(portName){
case 'A':
case 'a': {
					if(data == 1) SET_BIT(GPIO_PORTA_DATA_R, pinNumber);
					else CLR_BIT(GPIO_PORTA_DATA_R, pinNumber);
break;
}
case 'B':
case 'b': {
					if(data == 1) SET_BIT(GPIO_PORTB_DATA_R, pinNumber);
					else CLR_BIT(GPIO_PORTB_DATA_R, pinNumber);
break;
}
case 'C':
case 'c': {
					if(data == 1) SET_BIT(GPIO_PORTC_DATA_R, pinNumber);
					else CLR_BIT(GPIO_PORTC_DATA_R, pinNumber);
break;
}
case 'D':
case 'd': {
					if(data == 1) SET_BIT(GPIO_PORTD_DATA_R, pinNumber);
					else CLR_BIT(GPIO_PORTD_DATA_R, pinNumber);
break;
}
case 'E':
case 'e': {
					if(data == 1) SET_BIT(GPIO_PORTE_DATA_R, pinNumber);
					else CLR_BIT(GPIO_PORTE_DATA_R, pinNumber);
break;
}
case 'F':
case 'f': {
					if(data == 1) SET_BIT(GPIO_PORTF_DATA_R, pinNumber);
					else CLR_BIT(GPIO_PORTF_DATA_R, pinNumber);
break;
}

	}
}

void Port_Write(char portName, unsigned char data){
	switch(portName){
case 'A':
case 'a': {
				 GPIO_PORTA_DATA_R = data;
break;
}
case 'B':
case 'b': {
				 GPIO_PORTB_DATA_R = data;
break;
}
case 'C':
case 'c': {
				 GPIO_PORTC_DATA_R = data;
break;
}
case 'D':
case 'd': {
				 GPIO_PORTD_DATA_R = data;
break;
}
case 'E':
case 'e': {
				 GPIO_PORTE_DATA_R = data;
break;
}
case 'F':
case 'f': {
				 GPIO_PORTF_DATA_R = data;
break;
}
	}
}
void Port_Write_L(char portName, unsigned char data){
	switch(portName){
case 'A':
case 'a': {
					GPIO_PORTA_DATA_R &= ~0x0F;
					GPIO_PORTA_DATA_R |= data;
break;
}
case 'B':
case 'b': {
					GPIO_PORTB_DATA_R &= ~0x0F;
					GPIO_PORTB_DATA_R |= data;
break;
}
case 'C':
case 'c': {
					GPIO_PORTC_DATA_R &= ~0x0F;
					GPIO_PORTC_DATA_R |= data;
break;
}
case 'D':
case 'd': {
					GPIO_PORTD_DATA_R &= ~0x0F;
					GPIO_PORTD_DATA_R |= data;
break;
}
case 'E':
case 'e': {
					GPIO_PORTE_DATA_R &= ~0x0F;
					GPIO_PORTE_DATA_R |= data;
break;
}
case 'F':
case 'f': {
					GPIO_PORTF_DATA_R &= ~0x0F;
					GPIO_PORTF_DATA_R |= data;
break;
}
	}
}
void Port_Write_M(char portName, unsigned char data){
	switch(portName){
case 'A':
case 'a': {
				  GPIO_PORTA_DATA_R &= ~0xF0;
					GPIO_PORTA_DATA_R |= data;
break;
}
case 'B':
case 'b': {
				  GPIO_PORTB_DATA_R &= ~0xF0;
					GPIO_PORTB_DATA_R |= data;
break;
}
case 'C':
case 'c': {
				  GPIO_PORTC_DATA_R &= ~0xF0;
					GPIO_PORTC_DATA_R |= data;
break;
}
case 'D':
case 'd': {
				  GPIO_PORTD_DATA_R &= ~0xF0;
					GPIO_PORTD_DATA_R |= data;
break;
}
case 'E':
case 'e': {
				  GPIO_PORTE_DATA_R &= ~0xF0;
					GPIO_PORTE_DATA_R |= data;
break;
}
case 'F':
case 'f': {
				  GPIO_PORTF_DATA_R &= ~0xF0;
					GPIO_PORTF_DATA_R |= data;
break;
}
	}
}
void Port_PUR_Enable(char portName, unsigned char data){
	switch(portName){
case 'A':
case 'a': {
					GPIO_PORTA_PUR_R = ( (GPIO_PORTA_PUR_R&0x00)| data);
break;
}
case 'B':
case 'b': {
					GPIO_PORTB_PUR_R = ( (GPIO_PORTB_PUR_R&0x00)| data);
break;
}
case 'C':
case 'c': {
					GPIO_PORTC_PUR_R = ( (GPIO_PORTC_PUR_R&0x00)| data);
break;
}
case 'D':
case 'd': {
					GPIO_PORTD_PUR_R = ( (GPIO_PORTD_PUR_R&0x00)| data);
break;
}
case 'E':
case 'e': {
					GPIO_PORTE_PUR_R = ( (GPIO_PORTE_PUR_R&0x00)| data);
break;
}
case 'F':
case 'f': {
					GPIO_PORTF_PUR_R = ( (GPIO_PORTF_PUR_R&0x00)| data);
break;
}
	}
}
unsigned char Pin_Read(char portName, unsigned char pinNumber){
	switch(portName){
case 'A':
case 'a': {
					return (((1 << pinNumber)&GPIO_PORTA_DATA_R) >> pinNumber);
}
case 'B':
case 'b': {
					return (((1 << pinNumber)&GPIO_PORTB_DATA_R) >> pinNumber);
}
case 'C':
case 'c': {
					return (((1 << pinNumber)&GPIO_PORTC_DATA_R) >> pinNumber);
}
case 'D':
case 'd': {
					return (((1 << pinNumber)&GPIO_PORTD_DATA_R) >> pinNumber);
}
case 'E':
case 'e': {
					return (((1 << pinNumber)&GPIO_PORTE_DATA_R) >> pinNumber);
}
case 'F':
case 'f': {
					return (((1 << pinNumber)&GPIO_PORTF_DATA_R) >> pinNumber);
}
	}
	//return 0; // to remove warning user is expected to enter a valid port name and its his responsibility
}
void Pin_Toggle(char portName, unsigned char pinNumber){
	switch(portName){
case 'A':
case 'a': {
	        TOG_BIT(GPIO_PORTA_DATA_R, pinNumber);
break;
}
case 'B':
case 'b': {
	        TOG_BIT(GPIO_PORTB_DATA_R, pinNumber);
break;
}
case 'C':
case 'c': {
	        TOG_BIT(GPIO_PORTC_DATA_R, pinNumber);
break;
}
case 'D':
case 'd': {
	        TOG_BIT(GPIO_PORTD_DATA_R, pinNumber);
break;
}
case 'E':
case 'e': {
	        TOG_BIT(GPIO_PORTE_DATA_R, pinNumber);
break;
}
case 'F':
case 'f': {
	        TOG_BIT(GPIO_PORTF_DATA_R, pinNumber);
break;
}
	}
}

void portA_init_for_sw3(){
	SYSCTL_RCGCGPIO_R |=0x01;
				 while((SYSCTL_PRGPIO_R &0x01)==0);
				 GPIO_PORTA_LOCK_R=0x4C4F434B;
				 GPIO_PORTA_CR_R=0x0C;
				 GPIO_PORTA_PUR_R |= 0x08;
				 GPIO_PORTA_DEN_R |= 0x0C;
			   GPIO_PORTA_DIR_R |= 0x04;
				 GPIO_PORTA_PCTL_R &= ~0x0000FF00;
				 GPIO_PORTA_AMSEL_R &= ~0x0C;
				 GPIO_PORTA_AFSEL_R &= ~0x0C;
}
