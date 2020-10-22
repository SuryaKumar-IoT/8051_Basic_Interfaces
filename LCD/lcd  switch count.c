#include <REGX51.H>

#include "ORL/delay.h"
#include "ORL/lcd.h"

sbit sw=P2^0;

void main()
{
  unsigned  int count=0; 
  lcd_init();
  lcd_cmd(0x80);
  lcd_string("Count: ");
  lcd_cmd(0x89);
  lcd_num(count);
  while(1)
  {  
      if(sw==0)
	  {
	    
		while(sw==0);
		count++;
		lcd_cmd(0x89);
  		lcd_num(count);
	  }
  }
}