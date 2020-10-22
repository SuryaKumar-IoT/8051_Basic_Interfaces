void led_num(unsigned int m);

void 7seg(unsigned int n);

#define led P2

sbit en1=P3^4;
sbit en2=P3^5;
sbit en3=P3^6;
sbit en4=P3^7;


void led_num(unsigned int m)
{
  unsigned int d0,d1,d2,d3;
  
  d3=m%10;
  en4=0;
  7seg(d3);
  en4=1;
  
  m=m/10;
  d2=m%10;
  en3=0;
  7seg(d2);
  en3=1;
  
  m=m/10;
  d1=m%10;
  en2=0;
  7seg(d1);
  en2=1;
  
  m=m/10;
  d0=m%10;
  en1=0;
  7seg(d0);
  en1=1;
}

void 7seg(unsigned int n)
{
  switch(n)
  {
    case 0: 0xC0;
            break;
    case 1: 0xF9;
            break;
    case 2: oxA6;
            break;
    case 3: 0xB0;
            break;
    case 4: 0x99;
            break;
    case 5: 0x92;
            break;
    case 6: 0x82;
            break;
    case 7: 0xF8;
            break;
    case 8: 0x80;
            break;
    case 9: 0x98;
            break;
  }
}