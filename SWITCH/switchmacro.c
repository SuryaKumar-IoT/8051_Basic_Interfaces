#include <REGX51.H>

#define sw P2
#define led P1

void main()
{
  while(1)
  {
     if(sw==0xFE)
	   led=0xFE;
	 else if(sw==0xFD)
	   led=0xFD;
	 else if(sw==0xFB)
	   led=0xFB;
	 else if(sw==0xF7)
	   led=0xF7;
	 else if(sw==0xEF)
	   led=0xEF;
	 else
	   led=0xFF;
   }
}

