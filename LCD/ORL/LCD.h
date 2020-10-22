void lcd_init(void);
void lcd_cmd(unsigned char mad);
void lcd_data(unsigned char mad);
void lcd_string(unsigned char s[]);
void lcd_num(unsigned int num);


#define lcd P1

sbit rs=P1^2;
sbit en=P1^3;

void lcd_init(void)
{
	lcd_cmd(0x02);
 	lcd_cmd(0x28);
 	lcd_cmd(0x0e);
 	lcd_cmd(0x06);
 	lcd_cmd(0x01);
	lcd_cmd(0x0c);
}

void lcd_cmd(unsigned char mad)
{
    lcd=(mad)&(0xf0);
	rs=0;
	en=1;
	delay(3);
	en=0;

	lcd=(mad<<4)&(0xf0);
	rs=0;
	en=1;
	delay(3);
	en=0;
}

void lcd_data(unsigned char mad)
{
    lcd=(mad)&(0xf0);
	rs=1;
	en=1;
	delay(3);
	en=0;

	lcd=(mad<<4)&(0xf0);
	rs=1;
	en=1;
	delay(3);
	en=0;
}

void lcd_string(unsigned char s[])
{
   unsigned int i;
   for(i=0;s[i]!='\0';i++)
   {
	  if(i==16)    
		  lcd_cmd(0xc0);

	 lcd_data(s[i]);
	}

}

void lcd_num(unsigned int num)
{
 unsigned int d0,d1,d2;

 d2=num%10;
 num=num/10;
 d1=num%10;
 d0=num/10;

 lcd_data(d0+48);
 lcd_data(d1+48);
 lcd_data(d2+48);
}