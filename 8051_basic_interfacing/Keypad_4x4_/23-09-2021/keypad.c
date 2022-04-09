#include<reg51.h>
#include"LCD.h"

sbit C1 = P1^4;
sbit C2 = P1^5;
sbit C3 = P1^6;
sbit C4 = P1^7;

sbit R1 = P1^0;
sbit R2 = P1^1;
sbit R3 = P1^2;
sbit R4 = P1^3;

unsigned char KEYPAD(void)
{
//all columns at logic 1
C1 = C2 = C3 = C4 = 1;
 
//logic for row 1
R1 = 0;
R2 = R3 = R4 = 1;
 
if(C1 == 0)
{
LCD_DATA('7');
delay(5);
while(C1 == 0); 
} 

if(C2 == 0)
{
LCD_DATA('8');
delay(5);
while(C2 == 0); 
}

if(C3 == 0)
{
LCD_DATA('9');
delay(5);
while(C3 == 0); 
}

if(C4 == 0)
{
LCD_DATA('%');
delay(5);
while(C4 == 0); 
}

//logic for row 2
R2 = 0;
R1 = R3 = R4 = 1;
 
if(C1 == 0)
{
LCD_DATA('4');
delay(5);
while(C1 == 0); 
} 

if(C2 == 0)
{
LCD_DATA('5');
delay(5);
while(C2 == 0); 
}

if(C3 == 0)
{
LCD_DATA('6');
delay(5);
while(C3 == 0); 
}

if(C4 == 0)
{
LCD_DATA('X');
delay(5);
while(C4 == 0); 
}

//logic for row 3
R3 = 0;
R1 = R2 = R4 = 1;
 
if(C1 == 0)
{
LCD_DATA('1');
delay(5);
while(C1 == 0); 
} 

if(C2 == 0)
{
LCD_DATA('2');
delay(5);
while(C2 == 0); 
}

if(C3 == 0)
{
LCD_DATA('3');
delay(5);
while(C3 == 0); 
}

if(C4 == 0)
{
LCD_DATA('-');
delay(5);
while(C4 == 0); 
}

//logic for row 4
R4 = 0;
R2 = R3 = R1 = 1;
 
if(C1 == 0)
{
LCD_DATA('@');
delay(5);
while(C1 == 0); 
} 

if(C2 == 0)
{
LCD_DATA('0');
delay(5);
while(C2 == 0); 
}

if(C3 == 0)
{
LCD_DATA('=');
delay(5);
while(C3 == 0); 
}

if(C4 == 0)
{
LCD_DATA('+');
delay(5);
while(C4 == 0); 
}

return 0;
}


void main()
{
P2 = 0x00;  // Declaring P2 Output Pins
P3 = 0x00;  // Declaring P3 Output Pins
 
P1 = 0x0F;  //  Keypad
LCD_INIT(); // Initialising LCD for operation 
LCD_MESSAGE("Embedded Systems"); //Sending Data to the LCD
LCD_COMMAND(0xC0);
delay(100);
while(!KEYPAD());   // Halting controller at this line infinitly
}