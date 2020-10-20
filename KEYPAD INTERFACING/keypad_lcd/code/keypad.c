//************************************//

/*

TITLE:  PRESS ANY KEY FROM KEYPAD AND DISPLAY ON LCD.
DATE:   06/03/2014
							   */

//***********************************//

//***********START****************//

#include<p18f4520.h>
#include"lcd.h"

#define row1 PORTBbits.RB0
#define row2 PORTBbits.RB1
#define row3 PORTBbits.RB2
#define row4 PORTBbits.RB3

#define col1 PORTBbits.RB4
#define col2 PORTBbits.RB5
#define col3 PORTBbits.RB6
#define col4 PORTBbits.RB7


//************CHECK COLUMN 1 FOR PRESS KEY ANY ROW***********//


void check_col1()
{
	
	row1 = row2 = row3 = row4 = 1;
	
	row1 = 0;
	if(col1 == 0)
	{	
		lcd_cmd(0xC1);
		delay_ms(5);
		lcd_data('0');
	}
	row1 = 1;

	row2 = 0;
	if(col1 == 0)
	{
		lcd_cmd(0xC1);
		delay_ms(5);
		lcd_data('4');
	}
	row2 = 1;

	row3 = 0;
	if(col1 == 0)
	{
		lcd_cmd(0xC1);
		delay_ms(5);
		lcd_data('8');
	}
	row3 = 1;

	row4 = 0;
	if(col1 == 0)
	{
		lcd_cmd(0xC1);
		delay_ms(5);
		lcd_data('C');
	}
	row4 = 1;	
}

//************CHECK COLUMN 2 FOR PRESS KEY ANY ROW***********//

void check_col2()
{
	row1 = row2 = row3 = row4 = 1;
	
	row1 = 0;
	if(col2 == 0)
	{
		lcd_cmd(0xC1);
		delay_ms(1);
		lcd_data('1');
	}
	row1 = 1;

	row2 = 0;
	if(col2 == 0)
	{
		lcd_cmd(0xC1);
		delay_ms(1);
		lcd_data('5');
	}
	row2 = 1;

	row3 = 0;
	if(col2 == 0)
	{
		lcd_cmd(0xC1);
		delay_ms(1);
		lcd_data('9');
	}
	row3 = 1;

	row4 = 0;
	if(col2 == 0)
	{
		lcd_cmd(0xC1);
		delay_ms(1);
		lcd_data('D');
	}
	row4 = 1;
		
}

//************CHECK COLUMN 3 FOR PRESS KEY ANY ROW***********//

void check_col3()
{
	row1 = row2 = row3 = row4 = 1;
	
	row1 = 0;
	if(col3 == 0)
	{
		lcd_cmd(0xC1);
		delay_ms(1);
		lcd_data('2');
	}
	row1 = 1;

	row2 = 0;
	if(col3 == 0)
	{
		lcd_cmd(0xC1);
		delay_ms(1);
		lcd_data('6');
	}
	row2 = 1;

	row3 = 0;
	if(col3 == 0)
	{
		lcd_cmd(0xC1);
		delay_ms(1);
		lcd_data('A');
	}
	row3 = 1;

	row4 = 0;
	if(col3 == 0)
	{
		lcd_cmd(0xC1);
		delay_ms(1);
		lcd_data('E');
	}
	row4 = 1;
		
}

//************CHECK COLUMN 4 FOR PRESS KEY ANY ROW***********//

void check_col4()
{
	row1 = row2 = row3 = row4 = 1;
	
	row1 = 0;
	if(col4 == 0)
	{
		lcd_cmd(0xC1);
		delay_ms(1);
		lcd_data('3');
	}
	row1 = 1;

	row2 = 0;
	if(col4 == 0)
	{
		lcd_cmd(0xC1);
		delay_ms(1);
		lcd_data('7');
	}
	row2 = 1;

	row3 = 0;
	if(col4 == 0)
	{
		lcd_cmd(0xC1);
		delay_ms(1);
		lcd_data('B');
	}
	row3 = 1;

	row4 = 0;
	if(col4 == 0)
	{
		lcd_cmd(0xC1);
		delay_ms(1);
		lcd_data('F');
	}
	row4 = 1;
		
}

//************MAIN PROGRAM***********//

void main()
{

	ADCON1 = 0x0F;
	TRISC = 0x00;		//PORTC make as output port;
	TRISD = 0x00;		//PORTD make as output port;
	TRISB = 0xF0;
    	LATC = 0x00;
    	LATD = 0x00;
    
    	INTCON2bits.RBPU = 0;	//enable PORTB pull-up resistors;
	
	initial_lcd();

	lcd_display("ENTER KEY:");


	col1 = col2 = col3 = col4 = 1 ;		//make all column high ;

	while(1)
	{	
		row1 = row2 = row3 = row4 = 0;	 //make all row ground;

		if(col1 == 0)					 //make 1st row ground;
		{
			check_col1();	
		}
		
		else
		{
			if(col2 == 0)				 //make 2nd row ground;
			{
				check_col2();
			}

			else
			{
				if(col3 == 0)			 //make 3rd row ground;
				{
					check_col3();
				}
				
				else
				{
					if(col4 == 0)		 //make 4th row ground;
					{
						check_col4();
					}
				}		
			}
		} 
	}
}