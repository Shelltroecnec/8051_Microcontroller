#include<reg51.h>
#include<string.h>
void serial_init();
void tx(unsigned char ch);
void display(char a[]);
unsigned char rx(void);
unsigned char cr;
void serial_init()
{
TMOD = 0x20;
REN = 1;
SCON = 0x50;
TH1 = 0XFD;
TR1 = 1;
}
void tx(unsigned char ch)
{
SBUF = ch;
while(TI==0);
TI = 0;
}
void display(char a[])
{
int i;
for (i=0; a[i] != '\0';i++)
{
tx(a[i]);
}}
unsigned char rx(void)
{
	while(RI==0);
	cr = SBUF;
	RI = 0;
	return cr;
}
int main()
{
char b[]; 
	serial_init();
display("HELLO");
while(1)
{
	tx(rx());
}}