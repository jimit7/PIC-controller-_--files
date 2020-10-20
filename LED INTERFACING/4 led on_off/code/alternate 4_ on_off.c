//************************************//

//OUTHOR	:VARA ASHISH H.
//TITLE		:IN 8 LEDS,FIRST 4 LED ON AND LAST 4 LED OFF ALTERNANET CONTINUOUSLY
//DATE		:22/02/2014

//***********************************//

//***********START****************//


#include<p18f4520.h>
#define LED PORTB


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

//***********MAIN PROGRAM****************//

void main()
{
	TRISB = 0x00;			//port configure as outout port;
	while(1)
	{
		LED = 0x0F;		//led off;
		delay_ms(1000);		//delay for 1ms;

		LED = 0xF0;		//led on;
		delay_ms(1000);		//delay for 1ms;
	}
}

/***********STOP****************/