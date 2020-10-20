#include<p18f4520.h>
#define mybit PORTBbits.RB4
#define sw    PORTBbits.RB7
void T0delay(unsigned char c)
{ 

        T0CON=0X05;     // prescaler 64
      if (c==0)
        {
        TMR0H = 0xFF;
		TMR0L = 0xD9;
        }
      else
        {
        TMR0H = 0xFF;
		TMR0L = 0xE6;
        }
		T0CONbits.TMR0ON = 1;	//enable timer0;
		while(INTCONbits.TMR0IF == 0);

		T0CONbits.TMR0ON = 0;	//disable timer0;
		INTCONbits.TMR0IF = 0;	//clear IF flag;	

}
void main ()
{
   TRISBbits.TRISB4=0;
   TRISBbits.TRISB7=1;
   sw=1;
   while(1)
       {    if(sw==0)
           {
 			mybit=0;
			T0delay(0);
            mybit=1;
            T0delay(0); 
           }
           else
           {
 			mybit=0;
			T0delay(1);
            mybit=1;
            T0delay(1); 
           }
       }

}