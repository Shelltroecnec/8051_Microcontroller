#include<reg51.h>
#include"uart_header.h"
#include"lcd-4bit-board.h"
unsigned char c;
int main()
{
	serial_init();
	lcd_init();
	lcd_display("Show your Tag !");
	lcd_cmd(0xC0);
	while(1)
	{
		c = rx();
	tx(c);
	}
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	lcd_display("Thank You !");
}
