#include <REGX51.H>
#include "ORL/delay.h"
#include "ORL/7SEG.H"

#define enable P3

void main()
{
   enable=0x01;	 
   while(1)
   {
 	 	 
	 led=0xC0;
	 delay(500);
	 led=0xF9;
	 delay(500);
	 led=0xA4;
	 delay(500);
	 led=0xB0;
	 delay(500);
	 led=0x99;
	 delay(500);
	 led=0x92;
	 delay(500);
	 led=0x82;
	 delay(500);
	 led=0xF8;
	 delay(500);
	 led=0x80;
	 delay(500);
	 led=0x98;
	 delay(500);
  }	 
}