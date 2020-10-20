#include<p18f4550.h>
void main(void)
{
    TXSTA = 0X20;
	SPBRG = 15;
	TXSTAbits.TXEN = 1;
	RCSTAbits.SPEN = 1;
	
	 {
	  TXREG='H';
	  while(PIR1bits.TXIF==0);
     }

void main(void)
	{ 
	 TRISC = 0;
     RCSTA=0x90;
	 SPBRG=15;
	 while(1)
	 {
		while(PIR1bits.RCIF==0);
		PORTC=RCREG;
  		  } 
}
}