#include <REGX51.H>

#include "ORL/delay.h"
#include "ORL/lcd.h"

#define sw P3
#define l293d P2


void main()
{
  lcd_init();
  lcd_cmd(0x85);
  lcd_string("WELCOME");

  while(1)
  { 
    if(sw==0xFE)
	{
	  lcd_cmd(1);
	  lcd_string("ROBO FRWD");
	  delay(200);
	  l293d=0xD7;
	}
	else if(sw==0xFD)
	{ 
	  lcd_cmd(1);
	  lcd_string("ROBO BACK");
	  delay(200);
	  l293d=0xEB;
	}
	else if(sw==0xFB)
	{
	  lcd_cmd(1);
	  lcd_string("ROBO LEFT");
	  delay(200);
	  l293d=0xF5;

	}
	else if(sw==0xF7)
	{
	  lcd_cmd(1);
	  lcd_string("ROBO RIGHT");
	  delay(200);
	  l293d=0xD2;
	}
	else
	{
	  lcd_cmd(1);
	  lcd_string("ROBO STOP");
	  delay(200);
	  l293d=0xFF;
	}
  }
}