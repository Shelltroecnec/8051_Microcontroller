void delay(int t);
unsigned char rx(void);
void serial_init(void);
void display(unsigned char *p);
unsigned int i;
void new_line(void);

void tx(unsigned char b)
{
SBUF=b;
while(TI==0);
TI=0;
}
unsigned char rx(void)
{
	while(RI==0);
	RI=0;
	return SBUF;
}
void delay(int t)
{
int i;
for(i=0;i<=1275*t;i++);
}
void serial_init()
{
TMOD = 0x20;
REN = 1;
SCON = 0x50;
TH1 = 0xFD;
TR1 = 1;
}
void display(unsigned char *p)
{
	int i;
	for(i=0; *p!= '\0';i++)
	{
	tx(*p++);
	}
}
void new_line(void)
{
	tx(0x0D); //
	tx(0x0A); //
}