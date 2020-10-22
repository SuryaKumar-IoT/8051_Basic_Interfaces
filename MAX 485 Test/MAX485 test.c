#include "ORL/ORL.h"
#include "ORL/UART.h"

sbit dat=P2^0;
sbit sw=P2^7;

void main()
{
	uart_init();

	if(sw==0)
	{
	   dat=0;
	   uart_string("LS");
	   while(sw==0);
	}
}