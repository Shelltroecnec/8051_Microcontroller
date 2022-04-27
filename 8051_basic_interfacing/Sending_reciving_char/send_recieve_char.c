#include<reg51.h>
void SERIAL_INIT(void);
void SERIAL_TRANSMIT(unsigned char a);
unsigned char SERIAL_RECEIVE(void);
unsigned char ch;

void main()
{
ch = 'A';
SERIAL_INIT();
SERIAL_TRANSMIT(ch);
TR1=1;
while(1)
{
ch = SERIAL_RECEIVE();
SERIAL_TRANSMIT(ch);
}
}

void SERIAL_INIT(void)
{
TMOD = 0x20; // Timer 1 mode 2
REN =1;
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

unsigned char SERIAL_RECEIVE(void)
{
while(RI == 0);
ch = SBUF;
RI = 0; 
return ch; 
}