#include <REGX51.H>

#include "ORL/delay.h"
#include "ORL/lcd.h"
#include "ORL/uart.h"

void main()
{
  unsigned char ch;
  lcd_init();
  lcd_cmd(0x85);
  lcd_string("UART TEST");
  delay(100);
  uart_init();

  while(1)
  {
    ch=uart_rx();

	if(ch=='a')
	{								  
	  lcd_cmd(1);
	  lcd_string("FORWARD");
	  delay(200);
	  uart_string("FORWARD");
	  uart_enter();
	  delay(200);
	}
	else if(ch=='b')
	{								  
	  lcd_cmd(1);
	  lcd_string("BACKWARD");
	  delay(200);
	  uart_string("BACKWARD");
	  delay(200);
	  uart_enter();
	}
	else if(ch=='c')
	{								  
	  lcd_cmd(1);
	  lcd_string("LEFT");
	  delay(200);
	  uart_string("LEFT");
	  delay(200);
	  uart_enter();
	}
	else if(ch=='d')
	{								  
	  lcd_cmd(1);
	  lcd_string("RIGHT");
	  delay(200);
	  uart_string("RIGHT");
	  delay(200);
	  uart_enter();
	}
	else
	{
	  lcd_cmd(1);
	  lcd_string("STOP");
	  delay(200);
	  uart_string("STOP");
	  delay(200);
	  uart_enter();
	}
  }
}
