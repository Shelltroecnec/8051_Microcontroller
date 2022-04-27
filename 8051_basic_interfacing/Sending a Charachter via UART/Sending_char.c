#include<reg51.h>
void SERIAL_INIT(void);

void main ()
{
	SERIAL_INIT(); //Calling Serial Function
	while(1)
	{
		SBUF = 'A'; //Loading Data to be Transmitted in Serial Buffer Register
		TR1 =1; //Enabling Timer 1 to Start 
		while (TI == 0); // If Transmitted, TI Flag will be Set
	}
}

void SERIAL_INIT(void)
{
	TMOD = 0X20; //Timer1 in mode 2 i.e. 8-bit auto reload mode selected
	REN = 1; //Enable reciptien
	SCON = 0X50; //Serial mode 1, 8 bit data Transreciption
	TH1 = 0XFD; //Loading value in Timer Higher bit for baudrate 9600
	TR1 = 1; //Enabling Timer
}
