//************************************//


//TITLE		:Display  000 to 999 on segment
//DATE		:22/02/2014

//***********************************//

//***********START****************//


#include<p18f4550.h>
#define SEGMENT PORTB

#define S1 PORTCbits.RC4
#define S2 PORTCbits.RC5
#define S3 PORTCbits.RC6
#define S4 PORTCbits.RC7

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
	char a[] = {0xC0,0xF9,0xA4,0xA8,0x99,0x8A,0x82,0xF8,0x80,0x88};
	int x,k,y,z;

	TRISB = 0x00;		//PORTB configure as output port;
	TRISC = 0x00;		//PORTC configure as output port;

	S4 = 0;

	while(1)
	{
		for(x=0;x<10;x++)                  //for segment 1;
		{
			for(y=0;y<10;y++)              //for segment 2;
			{
				for(z=0;z<10;z++)		   //switching delay loop;
				{
					for(k=0;k<333;k++)
					{
						S1 = 1;
						SEGMENT = a[x];
						delay_ms(1);
						S1 = 0;

						S2 = 1;
						SEGMENT = a[y];
						delay_ms(1);
						S2 = 0;

						S3 = 1;
						SEGMENT = a[z];
						delay_ms(1);
						S3 = 0;
					}
				}	
			}
		}	
	}
}
