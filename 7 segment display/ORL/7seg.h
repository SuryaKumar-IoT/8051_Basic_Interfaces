void led_num(unsigned int );

void seg7(unsigned int );

#define led P2

sbit en1=P3^4;
sbit en2=P3^5;
sbit en3=P3^6;
sbit en4=P3^7;

void led_num(unsigned int m)
{
  unsigned int d0,d1,d2,d3;
  
  d3=m%10;
  m=m/10;
  d2=m%10;
  m=m/10;
  d1=m%10;
  m=m/10;
  d0=m%10;

  seg7(d3);
  en1=1;
  delay(500);
  en1=0;
 
  seg7(d2);
  en2=1;
  delay(500);
  en2=0;
  
  seg7(d1);
  en3=1;
  delay(500);
  en3=0;
  

  seg7(d0);
  en4=1;
  delay(500);
  en4=0; 
}


	   
void seg7(unsigned int n)
{
  switch(n)
  {
    case 0: 
			led=0xC0;
            break;
    case 1: 
			led=0xF9;
            break;
    case 2: 
			led=0xA4;
            break;
    case 3: 
			led=0xB0;
            break;
    case 4: 
			led=0x99;
            break;
    case 5: 
			led=0x92;
            break;
    case 6: 
			led=0x82;
            break;
    case 7: 
			led=0xF8;
            break;
    case 8: 
			led=0x80;
            break;
    case 9: 
			led=0x98;
            break;
  }
}