//************************************//

/*	
	TITLE	:Set the time  using four switch and display the clock on segment
				SW1 : when press, increment 1 digit
				SW2 : when press, decrement 1 digit
				SW3 : when press, display set time 
				SW4 : when press, start  the clock

	DATE	:22/02/2014    */

//***********************************//

//***********START****************//


#include<p18f4550.h>
#define SEGMENT PORTB

#define S1 PORTCbits.RC4
#define S2 PORTCbits.RC5
#define S3 PORTCbits.RC6
#define S4 PORTCbits.RC7

#define SWITCH1 PORTDbits.RD0
#define SWITCH2 PORTDbits.RD1
#define SWITCH3 PORTDbits.RD2
#define SWITCH4 PORTDbits.RD3

char a[] = {0xC0,0xF9,0xA4,0xA8,0x99,0x8A,0x82,0xF8,0x80,0x88};		//HEX code of digit 0 to 9; 
char b[] = {0x40,0x79,0x24,0x28,0x19,0x0A,0x02,0x78,0x00,0x08};	  //HEX code of digit 0 to 9(segment 2) with dp ON; 

int w,x,y,z,k;
int count = 0;


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

//*****************SET TIME(HH:MM)************************//

void time_set()
{

set:
		while(SWITCH3 == 1 & SWITCH4 == 1)
		{
			
			if(SWITCH1 == 0)						 //increment digit for set time;
			{
				
				if(count == 0)					 //for segment 1,set higher digit of hour;
				{
					w++;
					delay_ms(200);

					if(w > 1)
					{
						w = 0;
					}

				}

				if(count == 1)					//for segment 2,set lower digit of hour;
				{
					x++;
					delay_ms(200);

					if(x > 9)
					{
						x = 0;
					}
		
				}
		
				if(count == 2)					//for segment 3,set higher digit of minute;					
				{
					y++;
					delay_ms(200);

					if(y > 5)
					{
						y = 0;
					}
		
				}
		
				if(count == 3)				 	//for segment 4,set lower digit of minute;
				{
					z++;
					delay_ms(200);

					if(z > 9)
					{
						z = 0;
					}
		
				}

			}


			if(SWITCH2 == 0)						//decrement digit for set time;
			{
				
				if(count == 0)					//for segment 1,set higher digit of hour;
				{
					w--;
					delay_ms(200);

					if(w < 0)
					{
						w = 1;
					}

				}

				if(count == 1)					//for segment 2,set lower digit of hour;
				{
					x--;
					delay_ms(200);

					if(x < 0)
					{
						x = 9;
					}
		
				}
		
				if(count == 2)					//for segment 3,set higher digit of minute;
				{
					y--;
					delay_ms(200);

					if(y < 0)
					{
						y = 5;
					}
		
				}
		
				if(count == 3)					//for segment 4,set lower digit of minute;
				{
					z--;
					delay_ms(200);

					if(z < 0)
					{
						z = 9;
					}
		
				}		

			}

		S1 = 1;
		SEGMENT = a[w];
		delay_ms(1);
		S1 = 0;

		S2 = 1;
		SEGMENT = b[x];
		delay_ms(1);
		S2 = 0;

		S3 = 1;
		SEGMENT = a[y];
		delay_ms(1);
		S3 = 0;

		S4 = 1;
		SEGMENT = a[z];
		delay_ms(1);
		S4 = 0;
	
		}
	
		if(SWITCH3 == 0)
		{
			count++;
			delay_ms(200);

			if(count == 4)
			{
				count = 0;
			}

			while(1)
			{
				if(SWITCH3 == 1)
				{
					goto set;
				}
			}
		}
	
	return;

}

//*****************START CLOCK***********************//

void clock_start()
{
	if(SWITCH4 == 0)
	{
		while(1)				               			//continuously execution of loop;
		{
			for(w;w<2;w++)                  			//for segment 1,display higher digit of hour;
			{
				for(x;x<10;x++)                   		//for segment 2,display lower digit of hour;
				{
					for(y;y<6;y++)               		//for segment 3,display higher digit of minute;
					{
						for(z;z<10;z++)		    		//for segment 4,display lower digit of minute;
						{
							for(k=0;k<250;k++)			//switching delay loop;
							{

								if(w == 1 & x == 2)
								{
								 	w = 0;
									x = 0;
								}

								S1 = 1;
								SEGMENT = a[w];
								delay_ms(1);
								S1 = 0;

								S2 = 1;
								SEGMENT = b[x];
								delay_ms(1);
								S2 = 0;

								S3 = 1;
								SEGMENT = a[y];
								delay_ms(1);
								S3 = 0;

								S4 = 1;
								SEGMENT = a[z];
								delay_ms(1);
								S4 = 0;

							}
						}

						z = 0;	
					}

					y =0;
				}

				x = 0;	
			}

			w = 0;
		}
	}

return;

}

/************MAIN PROGRAM*********/

void main()
{	
	
	TRISB = 0x00;		//PORTB configure as output port;
	TRISC = 0x00;		//PORTC configure as output port;
	TRISD = 0xFF;		//PORTD configure as input port;
			
	S1 = 1;
	S2 = 1;
	S3 = 1;
	S4 = 1;

	time_set();			//set the time;
	clock_start();	    //start the clock;

}

/***************STOP**************/