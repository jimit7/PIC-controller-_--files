#include<p18f4520.h>


int k,l,m,n;
unsigned int x,y,value;


//************HEX TO BCD CONVERSION***********//

void HexToBcd(unsigned int j)
{
	k = j/100;
  	l = j%100;
  	m = l/10;
  	n = l%10;		
}

//************BCD TO ASCII CONVERSION***********//

void BcdToAscii()
{
	k = k | 0x30;
  	m = m | 0x30;
  	n = n | 0x30;	
}

//************DISPLAY SENSOR VALUE***********//

void DisplayValue()
{
	lcd_data(k);
  	lcd_data(m);
  	lcd_data(n);
}

//************ANALOG TO DIGITAL CONVERSION***********//

void ADC_value()
{
	ADCON0bits.GO = 1;
  	while(ADCON0bits.DONE == 1);
  	
	x = ADRESL;
  	y = ADRESH;
  		
  	value = x | (y << 8);
	value = value/4;
		
	HexToBcd(value);
  		
  	BcdToAscii();
  	
  	DisplayValue();
  		
  	delay_ms(100);
  	return; 			
}

