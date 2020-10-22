#include <reg51.h>
#define seg P2

sbit en1 = P3^0;
sbit en2 = P3^1;
sbit en3 = P3^2;
sbit en4 = P3^3;

sbit sw1  = P1^0;
sbit sw2  = P1^1;
sbit sw3  = P1^2;
sbit sw4  = P1^3;
sbit sw5  = P1^4;

void main()
 {
  en1 = en2 = en3 = en4 = 1;
  while(1)
   {
  	  if(sw1 == 0)				 // for sw1 segment display	0
	    P2 = 0x82;	
	  if(sw2 == 0)				 // for sw2 segment display	1
	   	P2 = 0xA4;	
	  if(sw3 == 0)				 // for sw3 segment display	2
	   	P2 = 0xF8;	
	  if(sw4 == 0)				 // for sw4 segment display	3
	   	P2 = 0x80;
	  if(sw5 == 0)				 // for sw5 segment display	4
	   	P2 = 0x98;
	  					  
   }
 
 }