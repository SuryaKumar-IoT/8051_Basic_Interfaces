#include <REGX51.H>

#include "ORL/delay.h"
#include "ORL/7seg.h"

sbit sw=P3^0;

void main()
{
  unsigned int count=0;
  //en1=en2=en3=en4=1;
  while(1)
  {
     
	 if(sw==0)
	 {  
	   //while(sw==0);
	   count++;
	   led_num(count);
	   delay(200);
	 }
  }
}