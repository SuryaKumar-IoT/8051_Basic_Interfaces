#include <REGX51.H>

#include "ORL/delay.h"
#include "ORL/lcd.h"

sbit moc=P2^0;
sbit sw=P2^7;

void main()
{

  lcd_init();
  lcd_cmd(0x83);
  lcd_string("TRAIC AC TEST");
  delay(200);

  while(1)
  {
     if(sw==0)
	 {
	   moc=~moc;
	 }
  }
}
