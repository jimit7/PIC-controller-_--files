//************************************//

//OUTHOR	:VARA ASHISH H.
//TITLE		:Display 00 to FF on LED
//DATE		:22/02/2014

//***********************************//

//***********START****************//


#include<p18f4550.h>
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

//************MAIN PROGRAM*********//

void main()
{
	char a[] = {0xFF,0x7F,0x3F,0x1F,0x0F,0x07,0x03,0x01,0x00};
	int z;
	TRISB = 0x00;
	while(1)					//for continuously execution of loop;
	{
		unsigned char a;
	 	for(a=0;a<=255;a++)
	 	{
			LED = a;
			delay_ms(1000);	 	
	 	}
	}
}
