#include <REGX51.H>

#include "ORL/delay.h"
#include "ORL/lcd.h"
#include "ORL/eeprom.h"

sbit sw=P2^0;

unsigned char ch,ch1,i,j;

void main()
{
   lcd_init();
   lcd_cmd(1);
   lcd_cmd(0x83);
   lcd_string("EEPROM TEST");

   write_eeprom(0,89);
   delay(1000);
   write_eeprom(1,99);
   delay(1000);
   while(1)
   {
   	if(sw==0)
   	{
		while(sw==0);
		ch=read_eeprom(0);

		lcd_cmd(1);
		lcd_num(ch);
		delay(1000);

		ch1=read_eeprom(1);
		lcd_cmd(1);
		lcd_num(ch1);
		delay(1000);

		i=ch+ch1;
		lcd_cmd(1);
		lcd_num(i);
		delay(1000);

		write_eeprom(2,i);
		delay(1000);

		j=read_eeprom(2);

		lcd_cmd(1);
		lcd_num(j);
		delay(1000);

		
   	}
   	else
   	{
     	lcd_cmd(1);
	 	lcd_string("No data Received ");
	 	delay(300);
	}
  }
}
