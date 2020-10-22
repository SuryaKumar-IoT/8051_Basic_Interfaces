#include <REGX51.H>

#define l293d P2

#define sw P1

void main()
{
  while(1)
  {
    if(sw==0xFE)
	  l293d=0xD7;
	else if(sw==0xFD)
	  l293d=0xEB;
	else if(sw==0xFB)
	  l293d=0xF5;
	else if(sw==0xF7)
	  l293d=0xD2;
	else
	  l293d=0xFF;
  }
}