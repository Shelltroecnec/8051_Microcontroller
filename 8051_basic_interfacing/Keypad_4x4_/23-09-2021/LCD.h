//---LCD Prototype Declaration
void LCD_INIT(void);                 // Initialise the LCD
void LCD_COMMAND(unsigned char a);   // Sending commands to lcd
void LCD_DATA(unsigned char b);     // Sending data to lcd
void LCD_MESSAGE(unsigned char *ptr); //For displaying messages on LCD
void delay(unsigned int a);           

//---LCD Control Pins
sbit RS = P3^0;
sbit RW = P3^1;
sbit EN = P3^2;

void LCD_INIT(void)
{
LCD_COMMAND(0x01); //To clear the LCD screen
LCD_COMMAND(0x06); //To increment the cursor
LCD_COMMAND(0x0C); //Internal SMD LED of the LCD are on and cursor is not getting displayed
LCD_COMMAND(0x38); //All the pixels of LCD
LCD_COMMAND(0x80); //Bring the cursor to the top left i.e. 1st matrix of 1st row
}

void LCD_COMMAND(unsigned char a)
{
P2 = a;
RS = 0; //selecting command register
RW = 0; //Writing Data to LCD
EN = 1; // High 
delay(5);
EN = 0; // LOW
}

void LCD_DATA(unsigned char b)
{
P2 = b;
RS = 1; //selecting data register
RW = 0; //Writing Data to LCD
EN = 1; // High 
delay(5);
EN = 0; // LOW
}

void delay(unsigned int a)
{
unsigned int b;
for(b=0;b<=1234*a;b++);
}

void LCD_MESSAGE(unsigned char *ptr)
{
while(*ptr != '\0')
{
LCD_DATA(*ptr);
ptr++;
}
}