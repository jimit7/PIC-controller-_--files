#include<P18f4520.h>
#include<arith.h>
#define  mybit PORTBbits.RB0
//#define _XTAL_FREQ 40000000   //MHz


void delay_msec(unsigned char mseconds)    // This function provides delay in terms of seconds
{
	unsigned char i,j;

	for(i=0;i<mseconds;i++)
		for(j=0;j<165;j++);
		
}

void main()
{
//	RB0 = 0;		// Make RB0 zero
	TRISB = 0x1F;     // Make RB0 output
    INTCON2bits.RBPU=0;
    PORTB=0XFF;
	while(1)
	{
		//mybit=mybit^1;
        //PORTBbits.RB0 = 1;		// Make RB0 one
	//	delay_msec(100);   // delay of one second

        //PORTBbits.RB0 = 0;		// Make RB0 zero
		//delay_msec(100);	// delay of one second
	}
}