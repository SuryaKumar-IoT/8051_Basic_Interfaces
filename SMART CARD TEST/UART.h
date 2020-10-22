
void UART_init(void);
void send_to_modem (unsigned char s[]);
void enter (void);
void ch_send_to_modem (unsigned char single_char);
void delay(unsigned int value);

void UART_init(void)
 {
  TMOD=0x20;
  PCON = 0x80;	   
  TH1=0xFD;
  SCON=0x50;
  TR1=1;
 }


void send_to_modem (unsigned char s[])
 {
  unsigned char r;

for(r=0;s[r]!='\0';r++)	// to send the command to GSM modem to avoid echo signal 
  {							//  the command is "ate0", 
    SBUF=s[r];
    while(TI==0);
    TI=0;
	
   }
 // enter(); 
 }


 void ch_send_to_modem (unsigned char single_char)
  {
      
  SBUF=single_char;
  while(TI==0);
  TI=0;
  //delay(5);
  }

 /* void enter (void)
 {
    SBUF=13;		  // Enter ASC values are 13 and 10,
    while(TI==0);	  // After sending commands to GSM modem  you must be send Enter's ASC values. 
    TI=0;
	delay(5);
    SBUF=10;
    while(TI==0);
    TI=0;
  }	*/
 