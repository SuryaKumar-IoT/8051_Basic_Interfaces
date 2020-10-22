#include <REGX51.H>

sbit en1=P2^0;
sbit en2=P2^1;
sbit in1=P2^2;
sbit in2=P2^3;
sbit in3=P2^4;
sbit in4=P2^5;

sbit sw1=P1^0;  //forward
sbit sw2=P1^1;  //backward
sbit sw3=P1^2;  //left
sbit sw4=P1^3;  //right



void main()
{

    while(1)
    {
          if(sw1==0) // forward
          {
              en1=1;
              en2=1;
              in1=1;
              in2=0; 
              in3=1;
              in4=0;
          }
          else if(sw2==0) // backward
          {
              en1=1;
              en2=1;
              in1=0;
              in2=1; 
              in3=0;
              in4=1;
          }
          else if(sw3==0) //left
          {
              en1=0;
              en2=1;
              in1=0;
              in2=0; 
              in3=1;
              in4=0;
          }
           else if(sw4==0) // right
          {
              en1=1;
              en2=0;
              in1=1;
              in2=0; 
              in3=0;
              in4=0;
          }
          else  //stop
          {
              en1=0;
              en2=0;
              in1=0;
              in2=0; 
              in3=0;
              in4=0;
          }
    }

}