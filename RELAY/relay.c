#include <REGX51.H>

#include "ORL/delay.h"
#include "ORL/lcd.h"

sbit relay=P2^0;
sbit sw=P2^7;
void main()
{
  relay=0;
  lcd_init();
  lcd_cmd(0x82);
  lcd_string("RELAY TEST");
  delay(200);

  while(1)
  {
    if(sw==0)
	{  

	  lcd_cmd(1);
	  lcd_string("RELAY ON");
	  delay(200);
	  relay=1;

	}
  	else
	{
	  lcd_cmd(1);
	  lcd_string("RELAY OFF");
	  delay(200);
	  relay=0;
	}
  }
}

  
  