//************************************//


//TITLE		:Display the clock(HH : MM : SS) on LCD
//DATE		:22/02/2014

//***********************************//

//***********START****************//


#include<p18f4520.h>
#include"lcd.h"

char j, k, l, m, c, d, i;
char a[] = {'0','1','2','3','4','5','6','7','8','9'};

void display_MM_SS();

//************MAIN PROGRAM*********//

void main()
{
	
	

	TRISB = 0x00;
	TRISC = 0x00;

	initial_lcd();
	
	lcd_cmd(0x81);
	delay_ms(1);
	lcd_display("HH : MM : SS");

	lcd_cmd(0xC4);		//fource cursor to beginning of 1st line,with 2 position;
	delay_ms(1);

	lcd_data(':');
	delay_ms(1);

	lcd_cmd(0xC9);		//fource cursor to beginning of 1st line,with 2 position;
	delay_ms(1);

	lcd_data(':');
	delay_ms(1);

	while(1)	
	{
		for(j = 0; j < 1; j++ )
		{
	
			for(k = 0; k < 10; k++ )
			{
				display_MM_SS();	
			}
		}

		for(j = 1; j < 2; j++ )
		{
	
			for(k = 0; k < 2; k++ )
			{
				display_MM_SS();		
			}
		}
	}

}

//***************FUNCTION OF DISPLAY MM:SS****************//

void display_MM_SS()
{
	for(l = 0;l < 6; l++ )
	{
					
		for(m = 0;m < 10; m++ )
		{

			for(c = 0;c < 6; c++)
			{
					
				for(d = 0; d < 10; d++ )
				{

					lcd_cmd(0xC1);		//fource cursor to beginning of 2nd line,with 1 position;

					lcd_data(a[j]);
			        delay_ms(1);

					lcd_cmd(0xC2);		//fource cursor to beginning of 2nd line,with 2 position;

					lcd_data(a[k]);
				    delay_ms(1);

					lcd_cmd(0xC6);		//fource cursor to beginning of 2nd line,with 6 position;
				  

					lcd_data(a[l]);
					delay_ms(1);

					lcd_cmd(0xC7);		//fource cursor to beginning of 2nd line,with 7 position;
		

					lcd_data(a[m]);
					delay_ms(1);

					lcd_cmd(0xCB);		//fource cursor to beginning of 2nd line,with 11 position;
		

					lcd_data(a[c]);
					delay_ms(1);

					lcd_cmd(0xCC);		//fource cursor to beginning of 2nd line,with 12 position;
			

					lcd_data(a[d]);
					delay_ms(1);

					delay_ms(1000);
							
				}
			}		                
		}	
	}
	
	return;
}

/***************STOP****************/

