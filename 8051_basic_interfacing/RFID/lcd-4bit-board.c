
#define Data P2								//LCD data lines connected to port 1

void lcd_init();
void lcd_cmd(char cmd);
void lcd_data(char d);
void display(char *p);
void delay(int t);

sbit RS = P2^4;
//sbit RW = P1^1;
sbit EN = P2^5;

/*void main(){
	lcd_init();
	//lcd_data('8');
	display("Embedded");
	lcd_cmd(0xC0);
	display("Technosolutions");
	while(1);
}*/

void lcd_init(){
	lcd_cmd(0x28);							//8-bit data mode										//For 4-bit data mode - 0x28
	lcd_cmd(0x01);							//Clear Display	
	lcd_cmd(0x0E);							//Display On and Cursor blinking					//For Cursor off - 0x0C ; for cursor On - 0x0E
	lcd_cmd(0x06);							//Entry Mode
	lcd_cmd(0x80);							//First Line of LCD									//For 2nd line - 0xC0
}

void lcd_cmd(char cmd){
	Data = ((cmd>>4) & 0x0F);				//Send upper 4-bit command to Port where lcd is connected
	RS = 0;											//RS 0 for commmand register
	//RW = 0;											//Write operation
	EN = 1;											//EN goes high to low to write data into lcd
	delay(10);
	EN = 0;
	delay(10);
	
	Data = (cmd & 0x0F);		//Send lower 4-bit command to Port where lcd is connected
	RS = 0;											//RS 0 for commmand register
	//RW = 0;											//Write operation
	EN = 1;											//EN goes high to low to write data into lcd
	delay(10);
	EN = 0;
	delay(10);
}

void lcd_data(char d){
	Data = ((d>>4) & 0x0F);					//Send upper 4-bit data to Port where lcd is connected
	RS = 1;											//RS 1 for data register
	//RW = 0;											//Write operation
	EN = 1;											//EN goes high to low to write data into lcd
	delay(10);
	EN = 0;
	delay(10);
	
	Data = (d & 0x0F);			//Send lower 4-bit data to Port where lcd is connected
	RS = 1;											//RS 1 for data register
	//RW = 0;											//Write operation
	EN = 1;											//EN goes high to low to write data into lcd
	delay(10);
	EN = 0;
	delay(10);
}

void display(char *p){
	int i;
	for(i=0;*p!='\0';i++){
		lcd_data(*p++);
	}
}

void delay(int t){
	int i,j;
	for(i=0;i<=t;i++){
		for(j=0;j<=1275;j++);
	}
}
