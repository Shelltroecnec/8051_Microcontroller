#include<reg51.h>
sbit LED=P1^0;
void delay();

int main()
{
//P1=0x00;
	LED=1;
while(1)
{
LED=0;
delay();
LED=1;
delay();
}
}
void delay()
{
TMOD = 0x01; //TIMER MODE 1
TH1 = 0x4B;
TL1 = 0xFD;
TF1 = 0;
TR1 = 1;
while(TF1==0);
TF1 = 0;
TR1 = 0;
}