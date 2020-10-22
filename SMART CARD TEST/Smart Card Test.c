#include<reg51.h>
#include"lcddisplay.h"
#include "uart.h"
#include<string.h>

unsigned char i,j=0;
unsigned char buf[50],ch,tempdata[10];
unsigned int balance=0,amount=0,duration;

void convert(unsigned int temp1_value)  

{
            unsigned int value,d1,d2,d3;
              value=temp1_value/10;
              d3=temp1_value%10;
              d1=value/10;
              d2=value%10;
              lcddata(d1+48);
              lcddata(d2+48);
              lcddata(d3+48);
}


void serial(void) interrupt 4
{
   
 if(RI)
  {
   
  if((SBUF !=13)&&(SBUF != 10))
	{
	buf[j] = SBUF;
	ch=buf[j];
	j++;
    }

   	RI = 0;
	
  }

}


void main()
 {
  lcd_init();
  delay(50);
  UART_init(); 
  delay(50);
 
  lcdcmd(0x85);
  msgdisplay("WELCOME");
 
  start:
 
   lcdcmd(0x01);
   msgdisplay("INSERT CARD");
   
   EA=1;
   ES=1;
   
   j=0;
   while(j==0);
   delay(1000);
   buf[j]='\0';
  	j=0;

    lcdcmd(0x01);
   msgdisplay("Card Testing..");
  
	 delay(2000);
   if(!strcmp(buf,"Enter password:"))
   	{
	  j=0;
	  send_to_modem("AAA");				//ENTER SECURITY CODE
	  ch_send_to_modem(13);
	  ch_send_to_modem(10);
	  
	  while(j==0);
	  delay(1500);
	  lcdcmd(0x01);
      msgdisplay("CARD ACCEPTED..");
	  delay(1000);
	  
	  j=0;
	  send_to_modem("READ 50 1");		//READING THE DATA
	  ch_send_to_modem(13);
	  ch_send_to_modem(10);	
  	  
	  j=0;
	  while(j==0);
	  delay(1500);
	  buf[j]='\0';

	  if(ch == 'A')
	  {
	   lcdcmd(1);
	   msgdisplay("CARD A");
       delay(1000);
	  }

	  else if(ch == 'B')
	  {
	   lcdcmd(1);
	   msgdisplay("CARD B");
       delay(1000);
	  }

	  else
	  {
	   lcdcmd(1);
	   msgdisplay("UNAUTHORIZED");
       delay(1000);
	  }
	  lcdcmd(0xc0);
      msgdisplay("Remove Your Card");
	 
	 	   j=0;
		   while(j==0);
		   delay(1000);
		   j=0;

		   goto start;
		 
		 } 
	   	  
  else
   {
	lcdcmd(0x01);
    msgdisplay("Card Error");
	lcdcmd(0xc0);
    msgdisplay("Re Insert Card");
    
	j=0;
	while(j==0);
	delay(2000); 	  
  	 goto start;
  
   }
 }  	 

