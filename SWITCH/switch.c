#include <REGX51.H>

#include "ORL/delay.h"

sbit sw1=P2^0;
sbit sw2=P2^1;
sbit sw3=P2^2;
sbit sw4=P2^3;
sbit sw5=P2^4;

sbit led1=P1^0;
sbit led2=P1^1;
sbit led3=P1^2;
sbit led4=P1^3;
sbit led5=P1^4;

void main()
{
  while(1)
  {  
     if(sw1==0)
	   led1=0;
	 else if(sw2==0)
	   led2=0;
	 else if(sw3==0)
	   led3=0;
	 else if(sw4==0)
	   led4=0;
	 else if(sw5==0)
	   led5=0;
	 else
	   led1=led2=led3=led4=led5=1;
   }
}

