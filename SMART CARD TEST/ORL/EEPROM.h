#include<intrins.h>
		 
sbit SCL=P3^7;		   
sbit SDA=P3^6;

void start(void);
void write_eeprom(unsigned char,unsigned char);
unsigned char read_eeprom(unsigned char);
void send_to_eeprom(unsigned char );
void stop(void);
void i2cdelay(unsigned int );
		
void write_eeprom(unsigned char add,unsigned char dat)
{
	start();
    send_to_eeprom(0Xa0); //device addr in write mode//
    send_to_eeprom(add); //byte addr//
    send_to_eeprom(dat); //data//
    stop();
}

unsigned char read_eeprom(unsigned char add)
{
	unsigned char v,i;  
	start();
	send_to_eeprom(0Xa0); //device addr in write mode//
	send_to_eeprom(add); //byte addr//
	_nop_();
	start();
	send_to_eeprom(0Xa1); //device addr in read mode//
	v=0;
    SDA=1;
    for(i=0;i<=7;i++)
    {
          SCL=0;
          _nop_();
          _nop_();
          SCL=1;
          v=v|SDA;
          if(i<=6)
          v=v<<1;
    }
    SCL=0;
   	i2cdelay(100); 
 	stop();
	return(v);
}

  
void start(void)
{
			   
	SCL=1;
	SDA=1;
			   
	_nop_();
	_nop_();
			   
	SDA=0;
	SCL=0;
}

void send_to_eeprom(unsigned char a)
{
	unsigned char i,c;
	for(i=0;i<=7;i++)
	{
		c=a&128;
		if(c==0)
			SDA=0;
	  	else
			SDA=1;

		SCL=1;
		_nop_();
		_nop_();
		SCL=0;
        a=a<<1;
	}	
	
	SDA=1;
	_nop_();
	_nop_();
	SCL=1;
	_nop_();
	_nop_();
	SCL=0;
}

void stop(void)
{
	SDA=0;
	SCL=1;
	_nop_();
	_nop_();
	SDA=1;
	SCL=0;
}


void i2cdelay(unsigned int s)
{
	unsigned int i,j;
	for(i=0;i<=s;i++)
		for(j=0;j<=250;j++);
}

