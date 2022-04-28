#include<reg51.h>
sbit LED = P3^4;
void timer_init(unsigned int a);

void ISR(void) interrupt 1
{
LED = ~LED;
}

void main()
{
EA = 1;  //enable the interrupt register 
ET0 = 1; //enable the timer interrupt 0
TR0 = 1;
timer_init(1000);
}

void timer_init(unsigned int a)
{
int count = 1;
while(count <= a)
{ 
TMOD = 0x00;
TL0 = 0x33;
TH0 = 0x1E;
TF0 = 0;
TR0 = 1;
while(TF0 == 0);
TR0 = 0;
TF0 = 0;
count = count+1; 
}}