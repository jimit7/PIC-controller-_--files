//************************************//
/*

//TITLE:  Receive string  from monitor (serial port) and also transmit again  and display on LCD
//DATE:   11/03/2014 */

//***********************************//

//***********START****************//

#include<p18f4520.h>
#define LCD PORTB

#define RS PORTCbits.RC3
#define RW PORTCbits.RC4
#define EN PORTCbits.RC5

int i;
char MyName[80];

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

//************LCD COMMAND LOOP***********//

void lcd_cmd(unsigned char x)
{
	LCD = x;
	RS = 0;
	RW = 0;
	EN = 1;
	delay_ms(1);
	EN = 0;
}

//************LCD DATA LOOP***********//

void lcd_data(unsigned char y)
{
	LCD = y;
	RS = 1;
	RW = 0;
	EN = 1;
	delay_ms(1);
	EN = 0;
}

//***********INITIALIZATION OF SERIAL COMMUNICATION****************//

void initial_com()
{
	TXSTA = 0x20;		//select 8-bit,low baud rate,transmit enable;
	SPBRG = 17;			//select 9600 baud rate for 11.0592 MHz;
	RCSTA = 0x90;		//enable serial communication,continuous receive;
}

void initial_lcd()
{
	lcd_cmd(0x38);		//intialization of 5X7 matrix of lcd;
	delay_ms(1);

	lcd_cmd(0x0C);		//display ON,cursor off;
	delay_ms(1);

	lcd_cmd(0x01);		//clear display screen;
	delay_ms(1);

	lcd_cmd(0x80);		//fource cursor to beginning of 1st line,with 1 position;
	delay_ms(1);
}	

//***********MAIN PROGRAM****************//

void main()
{	
	i = 0;
	
	TRISB = 0x00;	
	TRISCbits.TRISC3 = 0;
	TRISCbits.TRISC4 = 0;
	TRISCbits.TRISC5 = 0;
	
	initial_com();		//initialization of serial communication;
	
	for(i = 0 ; i < 80 ; i++)
	{ 
		while(PIR1bits.RCIF==0);	//wait for receive;
		MyName[i] = RCREG;			//take data from SBUF;
		if(MyName[i] == 0x0D)		
		{
			break;
		}
	}
	
	i = 0;
	
	while(MyName[i] != 0x0D)
	{ 
		TXREG = MyName[i];			//place data in SBUF;
		while(PIR1bits.TXIF==0);	//wait for transmit;
		i++;
		delay_ms(1);
	}
	
	i = 0;
	initial_lcd();		//initialization of lcd;
			
	while(MyName[i] != 0x0D)
	{
		lcd_data(MyName[i]);
		delay_ms(1);
		i++;
		if(i == 16)
		{
			lcd_cmd(0xC0);
			delay_ms(1);
		}
	}
}

/***********STOP***************/