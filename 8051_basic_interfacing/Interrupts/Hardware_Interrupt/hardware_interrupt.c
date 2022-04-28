#include<reg51.h>
sbit LED = P1^0;
void delay(unsigned int a);
void ISR(void) interrupt 0
{
LED = ~LED;
}
void main()
{
EA = 1;  //enable the interrupt register 
EX0 = 1; //enable the external interrupt 0
while(1)
{
LED = 0;
delay(1000);
}
}
void delay(unsigned int a)
{
unsigned int b;
for(b=0;b<=1234*a;b++);
}
