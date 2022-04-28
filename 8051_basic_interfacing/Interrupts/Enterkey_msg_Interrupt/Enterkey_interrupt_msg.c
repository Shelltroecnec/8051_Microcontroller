#include<reg51.h>
void SERIAL_MESSAGE(unsigned char ch);
void delay (unsigned int i);
void SERIAL_INIT(void);
void SERIAL_TRANSMIT(unsigned char a);
unsigned char SERIAL_RECEIVE(void);
unsigned long Enterkey;
unsigned char ch;
void ISR(void) interrupt 4
{
	while(1)
	{
		if (Enterkey == 0x0d)
		{
	ch=SERIAL_RECEIVE();
	SERIAL_TRANSMIT(ch);
	delay(1);
	ch++;
}}}

void main()
{
SERIAL_INIT();
ch='A';
EA =  1; // Enable the Interrupt Register
ES = 1; // Enable the Serial Interrupt
}
	/*while(1)
{
	if(Enterkey == 0)
{
	ch = SERIAL_RECEIVE();
	SERIAL_TRANSMIT(ch);
}}}
*/
	
void SERIAL_INIT(void)
{
TMOD = 0x20; // Timer 1 mode 2
SCON = 0x50; // mode 1 and ren is enable
TH1  = 0xFD; // for 9600 baud rate
TR1  = 1;    // turn on the timer
}

void SERIAL_TRANSMIT(unsigned char a)
{
SBUF = a;
while(TI == 0)
TI=0;
}
unsigned char SERIAL_RECEIVE(void)
{
while(RI == 0)
ch = SBUF;
RI = 0; 
return ch; 
}
void delay (unsigned int i)
{
	unsigned int b;
	for (b=0;b<=1234*i;b++);
}
/*void SERIAL_MESSAGE(unsigned char *ch)
{
while(*ch != '\0')
{
	SERIAL_TRANSMIT(ch);
	ch++;
}
}*/