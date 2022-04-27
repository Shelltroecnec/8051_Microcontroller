#include<reg51.h>
#include"uart_header.h"
sbit led1= P1^0;
sbit led2= P1^1;

int main()
{
led1=1;
led2=1;
serial_init();
display("Enter the value for LED Operation ");
new_line();
while(1)
{
if(rx()=='1')
{
led1=0;
display("LED ON");
}
if(rx()=='2')
{
led1=1;
display("LED OFF");
}}
}