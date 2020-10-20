//************************************//

//TITLE:  PROGRAM FOR DATA TRANSMISION USING SERIAL COMMUNICATION
//DATE:   11/03/2014

//***********************************//

//***********START****************//

#include<p18f4520.h>

//***********DELAY LOOP(1ms)****************//

void delay_ms(unsigned int time)
{
	unsigned int i;
	T0CON = 0x08;
	
	for(i = 0;i<time;i++)
	{
		TMR0H = 0xF5;
		TMR0L = 0x32;

		T0CONbits.TMR0ON = 1;	//enable timer0;
		while(INTCONbits.TMR0IF == 0);

		T0CONbits.TMR0ON = 0;	//disable timer0;
		INTCONbits.TMR0IF = 0;	//clear IF flag;
	}
}

void initial_com()
{
	TXSTA = 0x20;
	SPBRG = 17;
	RCSTAbits.SPEN = 1;
}

void main()
{
	initial_com();
	TXREG = 'A';
	while(PIR1bits.TXIF==0);
	delay_ms(1000);
}