//************************************//


//TITLE		:Display  0 to 9 on segment
//DATE		:22/02/2014

//***********************************//

//***********START****************//


#include<p18f4520.h>
#include"lcd.h"

//************MAIN PROGRAM*********//

void main()
{
	char a[] = {'0','1','2','3','4','5','6','7','8','9'};
	char j;

	TRISB = 0x00;		//PORTB configure as output port;
	TRISC = 0x00;		//PORTC configure as output port;
	
	initial_lcd();
	
	while(1)
	{
		for(j=0;j<10;j++)
		{
			lcd_data(a[j]);
			delay_ms(1000);

			lcd_cmd(0x01);		//clear display screen;
			delay_ms(1);	
		}	
	}
}

/***************STOP****************/

