#include<reg51.h>
sbit RS = P3^4;
sbit RW = P3^5;
sbit EN = P3^6;

void SERIAL_INIT(void);
void SERIAL_TRANSMIT(unsigned char a);
unsigned char SERIAL_RECEIVE(void);
unsigned char ch;
void LCD_INIT(void);
void LCD_COMMAND(unsigned int a);
void LCD_DATA(unsigned int b);
void LCD_DELAY(unsigned int a);
void LCD_MESSAGE(unsigned char *ch);

void ISR(void)interrupt 4
{ 
ch = SERIAL_RECEIVE();
SERIAL_TRANSMIT(ch);
while(1);
}


void main()
{
P2 = 0x00;
P3 = 0x00; 
LCD_INIT();
ch = 'A';
SERIAL_INIT();
SERIAL_TRANSMIT(ch);
EA=1;
ES=1;
LCD_MESSAGE("Embedded Systems");
LCD_DELAY(1);
while(1);
}

void LCD_INIT(void)
{
LCD_COMMAND(0x01); // clear the lcd display
LCD_COMMAND(0x06); // move cursor to the left
LCD_COMMAND(0x0C); // cursor off lcd on
LCD_COMMAND(0x38); // 5x7 matrix
LCD_COMMAND(0x80); // take cursor to the beginning
}

void LCD_COMMAND(unsigned int a)
{
P2 = a;
RS = 0; // command mode
RW = 0; // write operation
EN = 1; // high pulse
LCD_DELAY(1);
EN = 0; // low pulse 
}

void LCD_DATA(unsigned int b)
{
P2 = b;
RS = 1; // data mode
RW = 0; // write operation
EN = 1; // high pulse
LCD_DELAY(1);
EN = 0; // low pulse 
}

void LCD_DELAY(unsigned int a)
{
unsigned int b;
for(b=0;b<=1234*a;b++);
}

void LCD_MESSAGE(unsigned char *ch)
{
while(*ch != '\0')
{
LCD_DATA(*ch);
ch++;
}
}

void SERIAL_INIT(void)
{
TMOD = 0x20; // Timer 1 mode 2
SCON = 0x50; // mode 1 and ren is enable
TH1  = 0xFD; // for 9600 baud rate
TR1  = 1;    // turn on the timer
}

void SERIAL_TRANSMIT(unsigned char a)
{
SBUF = a;
while(TI == 0);
TI = 0;
}

unsigned char SERIAL_RECEIVE(void)
{
while(RI == 0);
ch = SBUF;
RI = 0; 
return ch; 
}