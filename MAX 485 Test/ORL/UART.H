void uart_init(void);
void uart_data(unsigned char);
char uart_rx(void);
void uart_string(unsigned char []);
void uart_num(unsigned int);
void uart_enter(void);
void uart_delay(unsigned int);

void uart_init()
{
	TMOD=0x20;
	SCON=0x50;
	TH1=0xFD;
	TR1=1;
}

void uart_data(unsigned char mad)
{
	SBUF=mad;
	while(TI==0);
	TI=0;
}
char uart_rx()
{
 unsigned char c;
 while(RI==0);
 c=SBUF;
 RI=0;
 return(c);
}

void uart_string(unsigned char mad[])
{
	unsigned int j;

	for(j=0;mad[j]!='\0';j++)
		uart_data(mad[j]);
}

void uart_enter()
{
	uart_data(13);
	uart_delay(10);
	uart_data(10);
}

void uart_delay(unsigned int mad)
{
	unsigned int i,j;
   	for(i=0;i<mad;i++)
    	for(j=0;j<100;j++);

}