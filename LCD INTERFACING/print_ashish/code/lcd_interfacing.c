//************************************//

//TITLE		:Display ASHISH on LCD
//DATE		:22/02/2014

//***********************************//

//***********START****************//


#include<p18f4520.h>
#include"lcd.h"

//************MAIN PROGRAM*********//

void main()
{

	TRISB = 0x00;
	TRISC = 0x00;
	
	initial_lcd();
	
	lcd_display("PIC18F4520");

}



/***************STOP****************/

