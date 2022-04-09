#include<reg51.h>
sbit LED = P1^0;
sbit SWITCH1 = P3^2;
sbit SWITCH2 = P3^3;
void delay(unsigned int a);

void main()
{
	//P1=0x00; // P1.0 as output
	//P3=0xff; //P2 as Input
	LED=1;
	while(1)
	{
		if (SWITCH1==0)
		{
		LED=1; //LED OFF
	}
	if (SWITCH2==0)
	{
		LED=0; //LED ON
}
}
}

void delay(unsigned int a)
{
	unsigned int b;
	for(b=0;b<=1234*a;b++);
}
