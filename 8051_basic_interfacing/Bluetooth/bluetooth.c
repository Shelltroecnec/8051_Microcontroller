#include<reg51.h>
void delay(int t);
void tx(unsigned char a);
unsigned char rx(void);
void serial_init(void);

void tx(unsigned char a)
{
SBUF=a;
while(TI==0);
TI=0;
}
unsigned char rx(void)
{
while(RI==0);
return SBUF;
RI=0;
}
void delay(int t)
{
int i;
for(i=0;i<=1275*t;i++);
}
void serial_init()
{
TMOD = 0x20;
REN = 1;
SCON = 0x50;
TH1 = 0xFD;
TR1 = 1;
}
int main()
{
serial_init();
while(1)
{
tx(rx());
}}