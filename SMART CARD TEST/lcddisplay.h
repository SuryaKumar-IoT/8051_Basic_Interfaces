#include <reg51.h>

#define lcd_data P1


sbit  lcd_rs   =  P1^2;  // Here we are using LCD in four bit mode that's why LCD's Data pins and control 
sbit  lcd_en   =  P1^3;
 
 void lcd_init(void);    
 void lcdcmd(unsigned char value);
 void lcddata(unsigned char value);
 void lcd_i2c(unsigned char value);
 void msgdisplay(unsigned char b[]);
 void delay(unsigned int value);	                           

void lcd_init(void)
{
 lcdcmd(0x02);	
 lcdcmd(0x02);
 lcdcmd(0x28);  //intialise the lcd in 4 bit mode*/
 lcdcmd(0x28);  //intialise the lcd in 4 bit mode*/
 
 lcdcmd(0x0e);	//cursor blinking
 lcdcmd(0x06);	//move the cursor to right side
 lcdcmd(0x01);	//clear the lcd

}

void lcdcmd(unsigned char value)		   // LCD COMMAND
  {
      
    /*lcd_data=value; //send msb 4 bits
      lcd_rs=0;	  //select command register
      lcd_en=1;	  //enable the lcd to execute command
	  delay(10);
	  lcd_en=0; 
	  delay(10);*/
	
	 lcd_data=value&(0xf0); //send msb 4 bits
      lcd_rs=0;	  //select command register
      lcd_en=1;	  //enable the lcd to execute command
	  delay(3);
	  lcd_en=0;  
      lcd_data=((value<<4)&(0xf0));	 //send lsb 4 bits
      lcd_rs=0;	 //select command register
      lcd_en=1;	 //enable the lcd to execute command
	  delay(3);
	  lcd_en=0;  
      
  }  
	
void lcddata(unsigned char value)

  {
     /*lcd_data=value; //send msb 4 bits
      lcd_rs=1;	  //select command register
      lcd_en=1;	  //enable the lcd to execute command
	  delay(10);
	  lcd_en=0;  */
	       
       
      lcd_data=value&(0xf0); //send msb 4 bits
      lcd_rs=1;	  //select data register
      lcd_en=1;	  //enable the lcd to execute data
	  delay(3);
	  lcd_en=0;  
      lcd_data=((value<<4)&(0xf0));	 //send lsb 4 bits
      lcd_rs=1;	  //select data register
      lcd_en=1;	  //enable the lcd to execute data
	  delay(3);
	  lcd_en=0;  
      
     delay(3); 
  }  



void msgdisplay(unsigned char b[]) // send string to lcd
  {
unsigned char s,count=0;
for(s=0;b[s]!='\0';s++)
 {
  count++;	 
  if(s==16)
   lcdcmd(0xc0);
   if(s==32)
   {
   lcdcmd(1);
   count=0;
   }
  lcddata(b[s]);
 }
}	


void delay(unsigned int value)

 {
   unsigned int x,y;
   for(x=0;x<value;x++)
   for(y=0;y<200;y++);
 } 

 void lcd_i2c(unsigned char value)
{
 unsigned char val1,val2;
 val1=value&(0xf0);
 val1=val1>>4;
 val2=value&(0x0f);
 lcddata(val1+48);
 lcddata(val2+48);
} 

 