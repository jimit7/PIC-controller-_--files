//************************************//

//TITLE:  DIGITAL CLOCK DISPLAY(SET TIME AND READ TIME) USING RTC
//DATE:   14/04/2014

//***********************************//

//***********START****************//

#include<p18f4520.h>
#include"lcd.h"

#define  SCL PORTCbits.RC3 
#define  SDA PORTCbits.RC4 

#define SEC 0x00
#define MIN 0x01
#define HOUR 0x02
#define DAY 0x03
#define DATE 0x04
#define MONTH 0x05
#define YEAR 0x06

void start();
void Aknowledge();
void stop();
void send_byte(unsigned int value);
unsigned int read_byte();
unsigned int RTC_get(unsigned char addr);
void set_time(unsigned int HH, unsigned int MM, unsigned int SS);
void initial_lcd();

	  



//bit ACK;
unsigned int send,read,ref,limit;
unsigned int p,q,r,s;
unsigned int sec,minute,hour,date,month,year,day;


//********DELAY LOOP***********//


void delay_us(unsigned int d)
{	
	unsigned int i;
	limit = (d*11.0592)/60;
	for(i = 0; i < limit; i++)
	{
	}	
}

//************DISPLAY DAY ON LCD************//


//void display_day()
//{
//	switch(day)
//	{
//		case 0:
//		lcd_display("SUN");
//		break;
//		case 1:
//		lcd_display("MON");
//		break;
//		case 2:
//		lcd_display("TUE");
//		break;
//		case 3:
//		lcd_display("WED");
//		break;
//		case 4:
//		lcd_display("THU");
//		break;
//		case 5:
//		lcd_display("FRI");
//		break;
//		case 6:
//		lcd_display("SAT");
//		break;
//		default:
//		lcd_display("");
//	 }
//
//}
//
//************START FUNCTION FOR RTC************//

void start()
{	
	TRISCbits.TRISC3 = 0;
	TRISCbits.TRISC4 = 0;

	SDA = 1;
	SCL = 1;
	delay_us(1000);
	SDA = 0;
	delay_us(1000);
	SCL = 0;
}

//************STOP FUNCTION FOR RTC************//

void stop()
{	
//	TRISCbits.TRISC3 = 0;
//	TRISCbits.TRISC4 = 0;
	SDA=0;
	SCL=1;
	delay_us(1000);
	SDA=1;
	delay_us(1000);
	SCL=0;
}

//************AKNOWLEDGE FUNCTION(CLOCK PULSE) FOR RTC************//

void Aknowledge()
{	
	TRISCbits.TRISC3 = 0;
	TRISCbits.TRISC4 = 0;
//	SDA = 0;
	delay_us(1000);
	SCL = 1;
	delay_us(1000);
	SCL = 0;
}

//************WRITE SINGLE DATA BYTE FUNCTION FOR RTC************//

void send_byte(unsigned int value)
{
	unsigned int k;
	send = value;
	for(k=0;k<8;k++)
	{
		SDA = send/128;
		send = send<<1;
		SCL = 1;
		delay_us(1000);
		SCL = 0;
	
	}
//	ACK = SDA;
	SDA = 0;		
}

//************READ SINGLE DATA BYTE FUNCTION FOR RTC************//

unsigned int read_byte()
{
	unsigned int b;
	SDA = 1;
	TRISCbits.TRISC4 = 1;
	
	read = 0;
	for(b=0;b<8;b++)
	{
		read = read<<1;
		SCL = 1;
//		delay_us(1000);
		if(SDA == 1)
		{
			read++;
		}
		SCL = 0;

		
		
	}


//	TRISCbits.TRISC4 = 0;
//	SDA = 0;
	return read;
}

//************READ DATA FROM RTC************//


unsigned int RTC_get(unsigned char addr)
{

	start();
	send_byte(0xD0);
	Aknowledge();
	send_byte(addr);
	Aknowledge();
	start();
	send_byte(0xD1);
	Aknowledge();
	ref = read_byte();	
	//Aknowledge();
	stop();
	return ref;
}

//************SET TIME ON RTC(HH:MM:DD:DAY)************//

void set_time(unsigned int HH, unsigned int MM, unsigned int SS)
{
	start();
	send_byte(0xD0);
	Aknowledge();
	send_byte(SEC);
	Aknowledge();
	send_byte(SS);	 
	Aknowledge();
	send_byte(MM);	 
	Aknowledge();
	send_byte(HH);	 
	Aknowledge();
	
	stop();
	return;
}

//************SET DATE ON RTC(DD/MM/YY)************//


void set_date(unsigned int DD, unsigned int MM, unsigned int YY)
{
	start();
	send_byte(0xD0);
	Aknowledge();
	send_byte(0x04);
	Aknowledge();
	send_byte(DD);	 
	Aknowledge();
	send_byte(MM);	 
	Aknowledge();
	send_byte(YY);	 
	Aknowledge();
	stop();
	return;
}

//************MAIN PROGRAM***********//

void main()
{
	TRISB = 0X00;
	TRISD = 0X00;
	TRISC = 0X00;
	initial_lcd();	   //initialization for lcd;
	lcd_display("TIME:");

	lcd_cmd(0xC0);
	lcd_display("DATE:");

	delay_ms(300);

	set_time(0x03,0x08,0x09);
	set_date(0x03,0x07,0x03);
	
   	while(1)
	{
		sec   = RTC_get(SEC);
		minute  = RTC_get(MIN);	
		hour  = RTC_get(HOUR);	
		date  = RTC_get(DATE);
		month = RTC_get(MONTH);
		year  = RTC_get(YEAR);
		
		lcd_cmd(0x85);
//		delay_ms(3);
		send2lcd(hour);
		lcd_data(':');

		
//		delay_ms(1);
		send2lcd(minute);
//		delay_ms(100);
		lcd_data(':');

		
//		delay_ms(1);
		send2lcd(sec);
	//	delay_ms(5000);
	//	lcd_cmd(0x8D);
	//	delay_ms(1);
	//	display_day();
	

		lcd_cmd(0xC5);
		send2lcd(date);
		lcd_data('/');
//		delay_ms(1);
		send2lcd(month);

		lcd_data('/');

		
//		delay_ms(1);
		send2lcd(year);
//		delay_ms(1);
	}	
// while(1);
}

/************STOP***********/	