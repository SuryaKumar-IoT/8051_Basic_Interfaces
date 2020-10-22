sbit ir =P3^2;

unsigned char i,key1,key;
bit a;



void ir_delay(void)
{
 unsigned int p,q;
 for(p=0;p<55;p++)
   for(q=0;q<2;q++);
}


void recieve(void) interrupt 0	  //remote decoding logic	RC5 protocol
{
  unsigned char x;
  key1=0;
  
  for(x=0;x<8;x++) //leave the first 8 bits 
    ir_delay();
 
  for(x=0;x<6;x++)	   //store next 6 bits,these are command buttons
  {
    a=ir;
    key1=key1<<1;
    key1=key1|a; 
    ir_delay();
  } 
   
  if((key1>=0)&&(key1<23))
  {
	  key=key1;
  } 
  delay(700);
}		     
