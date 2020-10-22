#include <REGX51.H>

#include "ORL/delay.h"
#include "ORL/tsopir.h"
#include "ORL/lcd.h"

sbit moc1=P2^0;
sbit moc2=P2^1;
sbit moc3=P2^2;
sbit moc4=P2^3;
sbit moc5=P2^4;
sbit moc6=P2^5;
sbit moc7=P2^6;
sbit moc8=P2^7;


void main()
{
    lcd_init();
	lcd_cmd(0x83);
	lcd_string("IR TEST");
	delay(200); 	

 	EA=1;
 	EX0=1;

	
 	while(1)
 	{
	   
  		if(key==1)
   		{
				moc1=~moc1;
				key=0;
   		}
  		
  		if(key==2)  
  		{
   			moc2=~moc2;
   			key=0;	
  		}
			
			if(key==3)
			{
				moc3=~moc3;
				key=0;
			}
			
			if(key==4)
			{
				moc4=~moc4;
				key=0;
			}
			
			if(key==5)
			{
				moc5=~moc5;
				key=0;
			}
			
			if(key==6)
			{
				moc6=~moc6;
				key=0;
			}
			
			if(key==7)
			{
				moc7=~moc7;
				key=0;
			}
			
			if(key==8)
			{
				moc8=~moc8;
				key=0;
			}
			
			if(key==9)
			{
				moc1=moc2=moc3=moc4=moc5=moc6=moc7=moc8=1;
				key=0;
			}
	}
}

