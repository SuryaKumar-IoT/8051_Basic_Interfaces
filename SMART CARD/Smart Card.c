#include "ORL/ORL.h"
#include "ORL/DELAY.h"
#include "ORL/LCD.h"
#include "ORL/UART.h"

unsigned char i,j=0;
unsigned char buf[50],ch,tempdata[10];

void serial(void) interrupt 4
{
   
 if(RI)
  {
 	buf[j] = SBUF;
	ch=buf[j];
	j++;
  }
  RI = 0;
}

void main()
{
	lcd_init();
  	delay(50);
  	uart_init(); 
  	delay(50);
 
  	lcd_cmd(0x85);
  	lcd_string("WELCOME");
	delay(500);
 
  start:
 
   	lcd_cmd(0x01);
   	lcd_string("INSERT CARD");
   
   	EA=1;
   	ES=1;
   
   	j=0;
   	while(j==0);
   	delay(1000);
   	j=j-2;
	buf[j]='\0';
  	j=0;

    lcd_cmd(0x01);
   	lcd_string("Card Testing..");
  
	delay(2000);

	if(!strcmp(buf,"Enter password:"))
   	{
	  j=0;
	  uart_string("AAA");				//ENTER SECURITY CODE
	  uart_enter();

	  while(j==0);
	  delay(1500);
	  lcd_cmd(0x01);
      lcd_string("CARD ACCEPTED..");
	  delay(1000);
	  
	  j=0;
	  uart_string("READ 40 5");		//READING THE DATA
	  uart_enter();
				   	  
	  while(j==0);
	  delay(1500);
	  j=j-2;
	  buf[j]='\0';

	  delay(500);
	  lcd_cmd(0xc0);
	  lcd_string(buf);
	  delay(2000);
	  delay(2000);

	  lcd_cmd(1);
	  lcd_cmd(0x80);
	  lcd_string("REMOVE CARD");
	  delay(2000);
	  j=0;
	  while(j==0);
	  delay(1000);

	  j=j-2;
	  buf[j]='\0';
	  if(!strcmp(buf,"Card Removed"))
	    goto start;

	}

	else
   	{
		lcd_cmd(0x01);
    	lcd_string("Card Error");
		lcd_cmd(0xc0);
    	lcd_string("Re Insert Card");
    
		j=0;
		while(j==0);
		delay(2000); 	  
  	 	goto start;
  
   }
}
 
