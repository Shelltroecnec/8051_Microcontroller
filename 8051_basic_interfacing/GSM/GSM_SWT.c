/*************************************
Hardware requirement :
>8051 Mico-Controller kit
>GSM module (SIM900A)
>Programmer (TTL - MAX232 Converter)
>SIM card
>Power Adapter for both Module/kit
**************************************/

#include<reg51.h>
#include"uart_header.h"
void string(unsigned char *p);
void sms(unsigned char *num, unsigned char *msg);
sbit SWT1 = P3^4;
sbit SWT2 = P3^5;
sbit SWT3 = P3^2;
sbit SWT4 = P3^3;

void main()
{
serial_init();
delay(10);
display("GSM Interface with 8051");
new_line();
while(1)
{
if(SWT1 == 0)
{
string("ATD9137440186");
tx(0x0D);
delay(10);
}
if(SWT2 == 0)
{
string("ATA");
tx(0x0D);
delay(10);
}
if(SWT3 == 0)
{
string("ATH");
tx(0x0D);
delay(10);
}
if(SWT4 == 0)
{
sms("9137440186","Hello-JUST TEST");
}}}
void string(unsigned char *p)
{
while(*p != '\0')
{
tx(*p++);
}}
void sms(unsigned char *num, unsigned char *msg)
{
string("AT+CMGF=1");
tx(0x0D);
delay(10);
string("AT+CMGS=");
tx('"');
while(*num)
tx(*num++);
tx('"');
tx(0x0D);
delay(10);
while(*msg)
tx(*msg++);
tx(0x1A);
delay(10);
}

