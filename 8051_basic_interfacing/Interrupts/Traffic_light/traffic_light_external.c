//Traffic Light control using Interrupt 0

#include<reg51.h>
sbit red = P1^0;
sbit yellow = P1^1;
sbit green = P1^2;
void delay(unsigned int t);
void ISR(void) interrupt 0
{
red = 0;
yellow = 1;
green = 1;
delay(5);
red = 1;
yellow = 0;
green = 1;
delay(1);
red = 1;
yellow = 1;
green = 0;
delay(5);
}
int main()
{
EA = 1; //Enabling the interrupt
EX0 = 1; //Enabling External Interrupt 0
while(1)
{
red = 0;
yellow = 0;
green = 0;
}}
void delay(unsigned int t)
{
 int i,j;
for(i=0;i<=100*t;i++)
{
for(j=0;j<=1275;j++);
}}
