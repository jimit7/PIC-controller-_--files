//************************************//

/*	
	TITLE	:Display four counter on segment using switch
				SW1 : when press, display 0 to 9
				SW2 : when press, display 00 to 99
				SW3 : when press, display 000 to 999
				SW4 : when press, display 0000 to 9999

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

/************MAIN PROGRAM*********/

void main()
{	
	char a[] = {0xC0,0xF9,0xA4,0xA8,0x99,0x8A,0x82,0xF8,0x80,0x88};		//HEX code of digit 0 to 9; 

	int p,q,r,s,b,c,d,m,n,k,z;

	TRISB = 0x00;		//PORTB configure as output port;
	TRISC = 0x00;		//PORTC configure as output port;
	TRISD = 0xFF;		//PORTD configure as input port;
	S1 = S2 = S3 = S4 = 0;
	while(1)
	{

//***********COUNTER 1****************//

	if(SWITCH1 == 0)
	{
count1:	while(1)
		{
			for(z=0;z<10;z++)
			{
				for(k=0;k<1000;k++)
				{
					if(SWITCH2 == 0)
					{
				  		goto count2;
					}

					if(SWITCH3 == 0)
					{
				  		goto count3;
					}

					if(SWITCH4 == 0)
					{
				  		goto count4;
					}

					S1 = 0;
					S2 = 0;
					S3 = 0;
					S4 = 1;
					SEGMENT = a[z];
					delay_ms(1);
				}	
			}	
		}
	}

//***********COUNTER 2****************//

	if(SWITCH2 == 0)
	{
count2:	while(1)				               //continuously execution of loop;
		{
			for(m=0;m<10;m++)                  //for segment 1;
			{
		
				for(n=0;n<10;n++)              //for segment 2;
				{
					for(k=0;k<500;k++)		   //switching delay loop;
					{
						if(SWITCH1 == 0)
						{
				  			goto count1;
						}

						if(SWITCH3 == 0)
						{
				  			goto count3;
						}

						if(SWITCH4 == 0)
						{
				  			goto count4;
						}
						S1 = 0;
						S2 = 0;
						S3 = 1;
						SEGMENT = a[m];
						delay_ms(1);
						S3 = 0;

						S4 = 1;
						SEGMENT = a[n];
						delay_ms(1);
						S4 = 0;

					}	
				}
			}	
		}
	}

//***********COUNTER 3****************//

	if(SWITCH3 == 0)
	{
count3:	while(1)				               //continuously execution of loop;
		{
			for(b=0;b<10;b++)                  //for segment 1;
			{
				for(c=0;c<10;c++)              //for segment 2;
				{
					for(d=0;d<10;d++)		   //switching delay loop;
					{
						for(k=0;k<333;k++)
						{
						 	if(SWITCH1 == 0)
							{
				  				goto count1;
							}

							if(SWITCH2 == 0)
							{
				  				goto count2;
							}

							if(SWITCH4 == 0)
							{
				  				goto count4;
							}

							S1 = 0;
							S2 = 1;
							SEGMENT = a[b];
							delay_ms(1);
							S2 = 0;

							S3 = 1;
							SEGMENT = a[c];
							delay_ms(1);
							S3 = 0;

							S4 = 1;
							SEGMENT = a[d];
							delay_ms(1);
							S4 = 0;
						}
					}	
				}
			}	
		}
	}

//***********COUNTER 4****************//

	if(SWITCH4 == 0)
	{
count4:	while(1)				               		//continuously execution of loop;
		{
			for(p=0;p<10;p++)                  		//for segment 1;
			{
				for(q=0;q<10;q++)                   //for segment 2;
				{
					for(r=0;r<10;r++)               //for segment 3;
					{
						for(s=0;s<10;s++)		    //for segment 4;
						{
							for(k=0;k<250;k++)	    //switching delay loop;
							{
								if(SWITCH1 == 0)
								{
				  					goto count1;
								}

								if(SWITCH2 == 0)
								{
				  					goto count2;
								}

								if(SWITCH3 == 0)
								{
				  					goto count3;
								}

								S1 = 1;
								SEGMENT = a[p];
								delay_ms(1);
								S1 = 0;

								S2 = 1;
								SEGMENT = a[q];
								delay_ms(1);
								S2 = 0;

								S3 = 1;
								SEGMENT = a[r];
								delay_ms(1);
								S3 = 0;

								S4 = 1;
								SEGMENT = a[s];
								delay_ms(1);
								S4 = 0;
							}
						}	
					}
				}	
			}
		}
	}
}
}

//***********STOP****************//
