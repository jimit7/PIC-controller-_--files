//************************************//


//TITLE		:Display  00 to 99 on segment
//DATE		:22/02/2014

//***********************************//

//***********START****************//


#include<p18f4520.h>
#include"lcd.h"

//************MAIN PROGRAM*********//

void main()
{
	char a[] = {'0','1','2','3','4','5','6','7','8','9'};
	char j,k;

	TRISB = 0x00;		//PORTB configure as output port;
	TRISC = 0x00;		//PORTC configure as output port;
	
	initial_lcd();

	while(1)
	{
		for(j=0;j<10;j++)
		{
	
			for(k=0;k<10;k++)
			{
				lcd_cmd(0x80);		//fource cursor to beginning of 1st line,with 0 position;
				delay_ms(1);

				lcd_data(a[j]);
				delay_ms(1);

				lcd_cmd(0x81);		//fource cursor to beginning of 1st line,with 1 position;
				delay_ms(1);

				lcd_data(a[k]);
				delay_ms(1000);

				lcd_cmd(0x01);		//clear display screen;
				delay_ms(1);
			}	
		}	
	}
}

/***************STOP****************/

