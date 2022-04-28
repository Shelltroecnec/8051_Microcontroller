#include<reg51.h>
sbit led1=P1^0;
sbit led2=P1^1;
sbit led3=P1^2;
void delay(unsigned int t);
void ISR(void) interrupt 0
{
led1=0;
led2=1;
led3=1;
delay(5);
led1=1;
led2=0;
led3=1;
delay(5);
led1=1;
led2=1;
led3=0;
delay(5);
}
int main()
{
EA=1;
EX0=1;
while(1)
{
led1=0;
led2=0;
led3=0;
}
}
void delay(unsigned int t)
{
int i,j;
for(i=0;i<=100*t;i++)
{
for(j=0;j<=1275;j++);
}
}
