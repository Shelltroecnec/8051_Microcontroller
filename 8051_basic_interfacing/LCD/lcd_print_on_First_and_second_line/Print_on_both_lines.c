#include<reg51.h>
#define DATA P2 
sbit RS=P3^0;
sbit RW=P3^1;
sbit EN=P3^2;
void delay(unsigned int t);
void cmd(unsigned int c);
void lcd_data(unsigned int d);
void init_lcd();
void msg(char *p);

void init_lcd()
{
cmd(0x38); //Using in 8bit 5x7 dot matrix
cmd(0x01); //Clear the Screen
cmd(0x06); //Move the Cursor to the left
cmd(0x0C); //Cursor off LCD on
cmd(0x80); //Take Cursor to the Begining
}
void cmd(unsigned int c)
{
DATA=c;
RS=0; //Command Mode
RW=0; //Write Mode
EN=1; //Enable =1
delay(1);
EN=0; //Enable =0
}
void lcd_data(unsigned int d)
{
DATA=d;
RS=1; //Data Mode
RW=0; //Write Mode
EN=1; //Enable=1
delay(1);
EN=0; //Enable=0
}
void msg(char *p)
{
while(*p != '\0')
{
lcd_data(*p++);
}}
void delay(unsigned int t)
{
unsigned int a;
for(a=0;a<=1275*t;a++);
}
int main()
{
	P2=0X00;
	P3=0X00;
	init_lcd();
	msg("Embedded Solution");
	cmd(0xC0);
	msg("Shahid Hashmhi");
	while(1);
}