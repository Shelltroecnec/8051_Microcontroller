#include<reg51.h>
#include"uart_header.h"
#include<string.h>
unsigned int i;
unsigned char stored[12]="3B003B3B86BD";
unsigned char input[12]=0;
int main()
{
serial_init();
	display("Show Your ID !");
new_line();
while(1)
{
for(i=0;i<=12;i++)
	{
	input[i]=rx();
	}
if(strncmp(stored,input,12)==0)
{
display("Access Granted !");
input[i]=0;
}
else
{
display("Access Denied !");
	input[i]=0;
}}
}

