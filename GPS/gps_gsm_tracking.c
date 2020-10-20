
//***********************************//

//***********START****************//
#include <p18F4520.h>
#include"lcd.h"
#define LED7 PORTCbits.RC7
#define LED6 PORTCbits.RC6
#define LED5 PORTCbits.RC5
#define LED1 PORTCbits.RC1


char test[6] = {'$','G','P','G','G','A'};
char str[80];
char t,w;
char k;
/****************Interrupt module *****************/
void chk_isr(void);
char RC_ISR(void);
void gps_string(void);

#pragma code My_HiPrio_Int=0x08
void My_HiPrio_Int (void)
{
	_asm
		GOTO chk_isr
	_endasm
}

#pragma code

#pragma interrupt chk_isr

void chk_isr(void)
{
	if(PIR1bits.RCIF==1)
	{
		RC_ISR();
	}
}

void Delay_ms(unsigned int time)
{
	unsigned int i,j;
	for(i=0;i<time;i++)
	{	
		for(j=0;j<165;j++);
	} 
}

void TX(const rom char *buffer)	// Function to display string on LCD
{
	int i=0;
	while(*buffer !='\0')
	{
 	  	TXREG=*buffer;
   		while(PIR1bits.TXIF==0);
   		delay_ms(10);
 	  	buffer++;					  				
   	}
	return; 
}

void TX2(unsigned char dat)	// Function to display string on LCD
{
	  TXREG = dat;
	while(PIR1bits.TXIF==0);							  				
    return; 
}

void initial_com(void)
{
	TXSTA = 0x20;
	SPBRG = 17;
	RCSTA = 0x90;
}

void main()
{	
	TRISCbits.TRISC7 = 1;
	TRISD = 0x00;
	TRISA = 0x00;
	TRISB = 0x00;

	PIE1bits.RCIE = 1;
	INTCONbits.PEIE = 1;
	INTCONbits.GIE = 1;
	initial_lcd();
	initial_com();
	LED7 = 0;
	LED6 = 0;
	while(1)
	{
		if(t >= 65)
		{		
			gps_string();
		}
	}
}

/************* Recive subroutine *********/
char RC_ISR()
{
	
	str[t++] = RCREG;
	w = RCREG;
	if(t<7)
	{
		if(str[t-1] != test[t -1])
		{
			t = 0;
		}	
	}
	PIR1bits.RCIF = 0;
	
}

/**************** gps STRING *******/
void gps_string()
{
	char z;
	int p = 0;
//	PIE1bits.RCIE = 0;
//	INTCONbits.PEIE = 0;
//	INTCONbits.GIE = 0;
	do
	{
		z = str[p];	
		p++;
	}while(z != ',');
    LED6 = ~LED6;
    do
	{
		z = str[p];	
		p++;
	}while(z != ',');
	
	LED7 = ~LED7;
	lcd_cmd(0x80);
	do
	{
		z = str[p];	
		lcd_data(z);
		Delay_ms(10);
		p++;
	}while(z != 'N');
	p++;
	lcd_cmd(0xC0);
	do
	{
		z = str[p];	
		lcd_data(z);
		Delay_ms(10);
		p++;
	}while(z != 'E');
	

	for(k=0;k<65;k++)
	{
		str[k] = 0x00;
	}


	
	t = 0;
	
//	INTCONbits.GIE = 1;
//	PIE1bits.RCIE = 1;
//	INTCONbits.PEIE = 1;
	return ;
}
