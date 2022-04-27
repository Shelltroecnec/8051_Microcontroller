#include<reg51.h>
void SERIAL_INIT(void);
void SERIAL_TRANSMIT(unsigned char a);
void delay (int t);
unsigned char ch[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
unsigned char SERIAL_RECEIVE(void);
int i;
void main()
{
	
	while (1)
	{
SERIAL_INIT();
SERIAL_TRANSMIT(ch[i]);
delay(2);
i++;
}
}
unsigned char SERIAL_RECEIVE(void)
{
while(RI == 0);
ch = SBUF;
RI = 0; 
return ch; 
}

void SERIAL_INIT(void)
{
TMOD = 0x20; // Timer 1 mode 2
SCON = 0x50; // mode 1 and ren is enable
TH1  = 0xFD; // for 9600 baud rate
TR1  = 1;    // turn on the timer
}

void SERIAL_TRANSMIT(unsigned char a)
{
SBUF = ch[i];
while(TI == 0);
TI = 0;
}
void delay (int t)
{
	int i;
	for(i=0;i<1275*t;i++);
}
