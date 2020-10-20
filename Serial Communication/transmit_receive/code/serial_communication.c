//************************************//


//TITLE:  PROGRAM FOR STRING TRANSMISION AND RECEIPTION USING SERIAL COMMUNICATION
//DATE:   11/03/2014

//***********************************//

//***********START****************//

#include<p18f4520.h>

char MyName[80];
int i;

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
	RCSTA = 0x90;		//enable serial communication,continuous receive;
	SPBRG = 17;			//select 9600 baud rate for 11.0592 MHz;
}

void main()
{	
	i = 0;
	initial_com();		//initialization of serial communication;
	
	for(i = 0 ; i < 80 ; i++)
	{ 
		while(PIR1bits.RCIF==0);	//wait for receive;
		MyName[i] = RCREG;			//take data from SBUF;
		if(MyName[i] == 0x0D)		
		{
			break;
		}
	}
	
	i = 0;
	
	while(MyName[i] != 0x0D)
	{ 
		while(PIR1bits.TXIF==0);	//wait for transmit;
		TXREG = MyName[i];			//place data in SBUF;
		i++;
		delay_ms(1);
	}
	
}