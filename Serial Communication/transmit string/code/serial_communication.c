//************************************//

//TITLE:  PROGRAM FOR STRING TRANSMISION USING SERIAL COMMUNICATION
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
	TXSTA = 0x20;		//select 8-bit,low baud rate,transmit enable;
	SPBRG = 17;			//select 9600 baud rate for 11.0592 MHz;
	RCSTAbits.SPEN = 1;	//enable serial communication;
}

void main()
{	
	int i = 0;
	char MyName[] = "Ashish Vara";

	initial_com();		//initialization of serial communication;
	
	while(MyName[i] != '\0')
	{
		TXREG = MyName[i];			//place data in SBUF; 
		while(PIR1bits.TXIF==0);	//wait for transmit;
		i++;
		delay_ms(1);
	}
	delay_ms(1000);	
}