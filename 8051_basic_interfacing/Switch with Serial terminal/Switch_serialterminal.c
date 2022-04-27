#include<reg51.h>
sbit SWITCH = P1^0;
void SERIAL_INIT(void);
void SERIAL_TRANSMIT(unsigned char a);
void display(unsigned char *p[]);
unsigned char msg1;
unsigned char msg2;

void main()
{
	SERIAL_INIT();
	display("Please Give the inputs !");
	display(0x0d);
	unsigned char a msg1 = 'hi'
	unsigned char a msg2 = 'there'
	
	if(SWITCH==0)
{
	SERIAL_TRANSMIT();
	SBUF=msg1;
}
else
{
	SERIAL_TRANSMIT();
	SBUF=msg2;
}
}
void display(unsigned char *p[])
{
	int i;
	while(*p[i] != '\0');
	SERIAL_TRANSMIT(*p[i]++);
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
SBUF = a;
while(TI == 0);
TI = 0;
}
