#include <REGX51.H>
#include <STRING.H>
#include <INTRINS.H>

#include "ORL/delay.h"
#include "ORL/lcd.h"
#include "ORL/mems.h"


void main()
{

  lcd_init();
  lcd_cmd(1);
  lcd_cmd(0x84);
  lcd_string("I2C TEST");
  delay(200);
  mems_init();
  lcd_cmd(1);
	
  while(1)
  {
		memsdata=mems_start();
		delay(10);
		lcd_cmd(0x80);
		lcd_num(memsdata);
		delay(100);
		
		delay(300);
		lcd_cmd(1);
		mems_stop();
	}  
}
