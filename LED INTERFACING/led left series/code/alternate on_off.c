//************************************//

//OUTHOR	:VARA ASHISH H.
//TITLE		:LED ON OFF in left series
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
	char a[] = {0x00,0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01,0x08};
	int z;
	TRISB = 0x00;
	while(1)		//for continuously execution of loop;
	{
		for(z=0;z<9;z++)
		{
			LED = a[z];
			delay_ms(50);
		}
	}
}
