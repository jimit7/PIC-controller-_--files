//************************************//

  TITLE		:Display four counter on LCD using switch
				SW1 : when press, display 0 to 9
				SW2 : when press, display 00 to 99
				SW3 : when press, display 000 to 999
				SW4 : when press, display 0000 to 9999	

  DATE		:22/02/2014	*/

//***********************************//

//***********START****************//


#include<p18f4520.h>
#include"lcd.h"

#define SWITCH1 PORTCbits.RC0
#define SWITCH2 PORTCbits.RC1
#define SWITCH3 PORTCbits.RC2
#define SWITCH4 PORTCbits.RC3

//************MAIN PROGRAM*********//

void main()
{
	char dat[] = {'0','1','2','3','4','5','6','7','8','9'};
	char a, b, c,d, p, q, j, k, l, m, z;

	TRISB = 0x00;
	TRISC = 0x0F;
	SWITCH1 = 1;
	SWITCH2 = 1;
	SWITCH3 = 1;
	SWITCH4 = 1;

	initial_lcd();

//***************COUNTER 1*******************//

	if(SWITCH1 == 0)
	{
		while(1)
		{
counter1:  	
			lcd_cmd(0x01);		//clear display screen;
			delay_ms(1);

			for(z=0;z<10;z++)
			{
				for(d=0;d<100;d++)
				{
					if(SWITCH2 == 0)
					{
						goto counter2;
					}
	
					if(SWITCH3 == 0)
					{
						goto counter3;
					}
	
					if(SWITCH4 == 0)
					{
						goto counter4;
					}
					
					lcd_cmd(0x80);		//fource cursor to beginning of 1st line,with 0 position;
					lcd_data(dat[z]);
					delay_ms(10);
				}

				lcd_cmd(0x01);		//clear display screen;	
			}
		}
	}

//***************COUNTER 2*******************//	
	if(SWITCH2 == 0)
	{

		while(1)
		{
counter2:	
			lcd_cmd(0x01);		//clear display screen;
			delay_ms(1);

			for(p=0;p<10;p++)
			{
	
				for(q=0;q<10;q++)
				{
					for(d=0;d<100;d++)
					{
						if(SWITCH1 == 0)
						{
							goto counter1;
						}
	
						if(SWITCH3 == 0)
						{
							goto counter3;
						}
	
						if(SWITCH4 == 0)
						{
							goto counter4;
						}
						
						lcd_cmd(0x80);		//fource cursor to beginning of 1st line,with 0 position;
	
						lcd_data(dat[p]);
	
						lcd_cmd(0x81);		//fource cursor to beginning of 1st line,with 1 position;
	
						lcd_data(dat[q]);
						delay_ms(10);
					}

					lcd_cmd(0x01);		//clear display screen;
				}	
			}
		}	
	}
	
//***************COUNTER 3*******************//	
	
	if(SWITCH3 == 0)
	{

		while(1)
		{
counter3:
			lcd_cmd(0x01);		//clear display screen;
			delay_ms(1);

			for(a=0;a<10;a++)
			{
	
				for(b=0;b<10;b++)
				{
				
					for(c=0;c<10;c++)
					{

						for(d=0;d<100;d++)
						{

							if(SWITCH1 == 0)
							{
								goto counter1;
							}
	
							if(SWITCH2 == 0)
							{
								goto counter2;
							}
	
							if(SWITCH4 == 0)
							{
								goto counter4;
							}
	
							lcd_cmd(0x80);		//fource cursor to beginning of 1st line,with 0 position;
	
							lcd_data(dat[a]);
	
							lcd_cmd(0x81);		//fource cursor to beginning of 1st line,with 1 position;
	
							lcd_data(dat[b]);
	
							lcd_cmd(0x82);		//fource cursor to beginning of 1st line,with 2 position;
	
							lcd_data(dat[c]);
	
							delay_ms(10);
						}
	
						lcd_cmd(0x01);	   	//clear display screen;
					}		                
				}	
			}
	 	}
	}

//***************COUNTER 4*******************//

	if(SWITCH4 ==0)
	{	
		while(1)
		{		

counter4:
			lcd_cmd(0x01);		//clear display screen;
			delay_ms(1);

			for(j=0;j<10;j++)
			{
	
				for(k=0;k<10;k++)
				{
				
					for(l=0;l<10;l++)
					{
					
						for(m=0;m<10;m++)
						{
							
							for(d=0;d<100;d++)
							{

								if(SWITCH1 == 0)
								{
									goto counter1;
								}
	
								if(SWITCH2 == 0)
								{
									goto counter2;
								}
	
								if(SWITCH3 == 0)
								{
									goto counter3;
								}
	
								lcd_cmd(0x80);		//fource cursor to beginning of 1st line,with 0 position;
	
								lcd_data(dat[j]);
	
								lcd_cmd(0x81);		//fource cursor to beginning of 1st line,with 1 position;
	
								lcd_data(dat[k]);
	
								lcd_cmd(0x82);		//fource cursor to beginning of 1st line,with 2 position;
	
								lcd_data(dat[l]);
	
								lcd_cmd(0x83);		//fource cursor to beginning of 1st line,with 3 position;
	
								lcd_data(dat[m]);
	
								delay_ms(10);
							}
	
							lcd_cmd(0x01);	   	//clear display screen;
						}
					}		                
				}	
			}		
		}
	}
}
/***************STOP*******************/

