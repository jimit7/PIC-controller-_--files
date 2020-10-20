//************************************//
/*

//TITLE:  Transmit the data in serial using switch and display on monitor
			SW1 : when press, transmit  “Good Morning ”
			SW1 : when open, transmit  “Bad Morning ”

//DATE:   11/03/2014 */

//***********************************//

//***********START****************//

#include<p18f4520.h>

#define SWITCH PORTDbits.RD0 

int i,j;
char MyName[] = "HITESH N PATEL  ";
char CollegeName[] = "CHAROTAR UNIVERSITY OF SCIENCE & TECHNOLOGY  ";

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

//***********INITIALIZATION OF SERIAL COMMUNICATION****************//

void initial_com()
{
	TXSTA = 0x20;		//select 8-bit,low baud rate,transmit enable;
	//SPBRG = 17;	         //select 9600 baud rate for 11.0592 MHz;
	SPBRG = 35;	        //select 4800 baud rate for 11.0592 MHz;
	RCSTAbits.SPEN = 1;	//enable serial communication;
}

//***********MAIN PROGRAM****************//

void main()
{	
	i = j = 0;
	initial_com();		//initialization of serial communication;
	
	if(SWITCH == 1)
	{
		while(MyName[i] != '\0')
		{
			TXREG = MyName[i];			//place data in SBUF;
			while(PIR1bits.TXIF == 0);	//wait for transmit;
			i++;
			delay_ms(10);
		}		
	}
	
	if(SWITCH == 0)
	{ 	
		while(CollegeName[j] != '\0')
		{
			TXREG = CollegeName[j];			//place data in SBUF;
			while(PIR1bits.TXIF == 0);	//wait for transmit;
			j++;
			delay_ms(10);
		}	
	}
	
}

/***********STOP***************/