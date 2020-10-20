//************************************//

//TITLE:  PROGRAM FOR DATA TRANSMISION USING SERIAL COMMUNICATION
//DATE:   11/03/2014

//***********************************//

//***********START****************//

#include<p18f4520.h>

void delay_ms(unsigned int time)
{
	unsigned int i;
	T0CON = 0x08;
	
	for(i = 0; i < time; i++)
	{
		TMR0H = 0xF5;
		TMR0L = 0x32;

		T0CONbits.TMR0ON = 1;	//enable timer0;
		while(INTCONbits.TMR0IF == 0);

		T0CONbits.TMR0ON = 0;	//disable timer0;
		INTCONbits.TMR0IF = 0;	//clear IF flag;
	}	
}

/*************SERIAL COMMUNICATION INITIALIZATION*********/

void initial_com(void)
{
	TXSTA = 0x20;
	SPBRG = 17;
	RCSTAbits.SPEN = 1;
}

void TX(const rom char *buffer)	// Function to display string on LCD
{
	int i=0;
	while(*buffer !='\0')
	{
 	  	TXREG=*buffer;
   		while(PIR1bits.TXIF==0);
   		delay_ms(10);
 	  	buffer++;					  				
   	}
	return; 
}

void TX2(unsigned char dat)	// Function to display string on LCD
{
	  TXREG = dat;
	while(PIR1bits.TXIF==0);							  				
    return; 
}




void main()
{
	initial_com();
	TX("AT+CMGF=1\r");
	//delay_ms(10);
	TX("AT+CMGS=");
	TX2('"');
	TX("9624246570");
	TX2('"');
	TX("\r");
	TX("hello");
	TX2(26);
	delay_ms(1000);
	while(1);
}