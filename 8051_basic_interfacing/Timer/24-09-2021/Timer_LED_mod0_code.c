#include<reg51.h>
sbit LED=P1^0;
void delay (unsigned int a);

int main()
{
P1 = 0x00; // Port1 as Output
while (1)
{
LED = 0;
delay (100);
LED = 1;
delay (100);
}
}

void delay (unsigned int a)
{
int count = 1;
while (count <= a)
{
TMOD = 0x00; // Timer mode 0
TH1 = 0x1E; // Load THX
TL1 = 0x33; // Load TLX
TF1 = 0;  // clear flag register
TR1 = 1;  //start timer
while (TF1==0);  // checking overflow
TR1 = 0;  // Stop timer
TF1 = 0; // clear flag
count = count+1;
}}
