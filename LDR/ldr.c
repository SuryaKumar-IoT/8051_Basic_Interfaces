#include <REGX51.H>

#include "ORL/delay.h"
#include "ORL/lcd.h"

sbit ldr=P2^0;
sbit led=P2^7;

void main()
{

  lcd_init();
  lcd_cmd(0x82);
  lcd_string("LDR TEST");
  delay(200);

  while(1)
  {
    led=0;
	lcd_cmd(1);
	if(ldr==0)
	{
	   led=1;
	   lcd_cmd(1);
	   lcd_string("LDR DETECTED");
	   delay(200);
	   while(ldr==0);
	}
  }
}
