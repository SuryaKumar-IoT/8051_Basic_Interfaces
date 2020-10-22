#include "ORL/ORL.h"
#include "ORL/DELAY.h"
#include "ORL/MAX485.h"

//#include "ORL/UART.h"

//sbit dat=P2^0;
sbit led=P2^7;


unsigned char ch[15],j=0;

void serial(void) interrupt	4
{
	if(RI)
	{
		ch[j]=SBUF;
		RI=0;
		j++;
	}
}

void main()
{
	dat=1;
	uart_init();

	EA=1;
  	ES=1;

	j=0;
	while(j==0);
	delay(2000);
	ch[j]='\0';
  
	if(!strcmp(ch,"LS"))
	{
		led=0;
	}
	
}
