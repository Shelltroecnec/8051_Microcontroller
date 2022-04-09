#include<reg51.h>
sbit LED_RED = P1^0;
sbit LED_YELLOW = P1^1;
sbit LED_GREEN = P1^2;
sbit SWITCH1 = P3^2;
sbit SWITCH2 = P3^3;

void delay(unsigned int a);

void main()
{
	//P1=0x00; // P1.0 as output
	//P2=0xff; //P2 as Input
	LED_RED=1;
	LED_YELLOW=1;
	LED_GREEN=1;
	while(1)
	{
	if (SWITCH1==0)
	{
		LED_RED=1;
		delay (1000);
		LED_RED=0;
		LED_YELLOW=1;
		delay (1000);
		LED_YELLOW=0;
		LED_GREEN=1;
		delay (1000);
		LED_GREEN=0;
	}
	else if (SWITCH2==0)
	{
		LED_RED=0;
		LED_YELLOW=0;
		LED_GREEN=0;
}
}
}

void delay(unsigned int a)
{
	unsigned int b;
	for(b=0;b<=1234*a;b++);
}
