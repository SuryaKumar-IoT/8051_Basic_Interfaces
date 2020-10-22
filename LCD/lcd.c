#include <REGX51.H>

#include "ORL/delay.h"
#include "ORL/lcd.h"
#define led P2
void main()
{

 	lcd_init();  // initializing LCD 
    lcd_cmd(1); //clears lcd
    
    lcd_cmd(0x80);
    lcd_string("WELCOME 2 ORANGE");
    delay(1000);
    lcd_cmd(0xC1);
    lcd_string(" RESEARCH LABS ");
    delay(1000);
	while(1)
	{
		led=0x00;
		delay(500);
		led=0xFF;
		delay(500);
	}
}