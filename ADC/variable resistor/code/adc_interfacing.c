

//***********************************//

//***********START****************//

#include<p18f4520.h>
#include"lcd.h"
#include"adc.h"

int i;

char sensor1[] = "sensor1:";
char sensor2[] = "sensor2:";
char sensor3[] = "sensor3:";


//************MAIN PROGRAM***********//


void main()
{
	 TRISB = 0X00;				//PORTB configure as output port;
	 TRISC = 0X00;				//PORTC configure as output port;
	 TRISAbits.TRISA0 = 1;		//pin A.0 make as input;
	 TRISAbits.TRISA1 = 1;		//pin A.1 make as input;
	 TRISAbits.TRISA5 = 1;		//pin A.5 make as input;
	 
	 initial_lcd();				//initialization of lcd;
	 i = 0;
	 
	 while(sensor1[i] != '\0')	//display sensor1 on lcd;
	 {
		lcd_data(sensor1[i]);
		delay_ms(1);
		i++;
	 }
	 
	 lcd_cmd(0xC0);				//fource cursor to beginning of 2nd line,with 0 position;
	 
	 i = 0;
	 while(sensor2[i] != '\0')	//display sensor2 on lcd;
	 {
		lcd_data(sensor2[i]);
		delay_ms(1);
		i++;
	 }
	 
	 lcd_cmd(0x90);				//fource cursor to beginning of 3rd line,with 0 position;
	 
	 i = 0;
	 while(sensor3[i] != '\0')	//display sensor3 on lcd;
	 {
		lcd_data(sensor3[i]);
		delay_ms(1);
		i++;
	 }
	 
 	 while(1)
	 {
		 
		ADCON0 = 0X01;			//select channel 1,enable ADCON0;
	 	ADCON1 = 0X3E;			//select voltage reference,make AN0 as analog pin;
	 	ADCON2 = 0X86;			//select right justified,select conversion clock;
	 	
  		lcd_cmd(0x89);			//fource cursor to beginning of 1st line,with 9 position;
  		
  		ADC_value();
  		
  		ADCON0 = 0X05;			//select channel 2,enable ADCON0;
 		ADCON1 = 0X3B;			//select voltage reference,make AN0 and AN1 as analog pin;
 		ADCON2 = 0X86;			//select right justified,select conversion clock;
 		
 		lcd_cmd(0xC9);			//fource cursor to beginning of 2nd line,with 9 position;
 		
 		ADC_value();
 		
 		ADCON0 = 0X11;			//select channel 4,enable ADCON0;
 		ADCON1 = 0X3A;			//select voltage reference,make AN0,AN1 and AN4 as analog pin;
 		ADCON2 = 0X86;			//select right justified,select conversion clock;
 		
 		lcd_cmd(0x99);			//fource cursor to beginning of 3rd line,with 9 position;
 		
 		ADC_value();
 	}
}

/************STOP***********/

 