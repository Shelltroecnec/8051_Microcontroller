//WAP for LED Operations using Modem communication i.e.RF comm.

#include<reg51.h>
#include"uart_header.h"
sbit led = P1^0;
sbit swt = P3^2;

void main()
{
serial_init();
while(1)
{
	if(swt==0)
{
led = 0;
	tx('1');
}
if(swt==1)
{
led = 1;
	tx('2');
}
}}