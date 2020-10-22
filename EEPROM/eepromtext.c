#include <REGX51.H>

#include "ORL/delay.h"
#include "ORL/lcd.h"
#include "ORL/uart.h"
#include "ORL/eeprom.h"

unsigned int i,j;
unsigned char ch1;
unsigned char ch[20];

void main()
{
   
   lcd_init();
   lcd_cmd(0x83);
   lcd_string("EEPROM TEST");

   uart_init();
   uart_string("WELCOME");

   while(1)
   {

      ch1=uart_rx();

	  if(ch1==13)
	  {
	     lcd_cmd(1);
		 lcd_string(ch);
		 delay(1000);
		 uart_string(ch);
		 delay(500);
		 i=0;
	  }
	  else
	  {
	     ch[i]=ch1;
		 i++;
	  }
	  ch[i]='\0';

   }
}
