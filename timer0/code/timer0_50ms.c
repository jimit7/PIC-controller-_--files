
//#pragma config OSC=XT
#include<p18f4520.h>
#define mybit PORTBbits.RB4


void T0delay()
{ 
  //int i;
  //for (i=0;i<20;i++)
//{
        T0CON=0X08;
        TMR0H = 0x85;
		TMR0L = 0xEE;

		T0CONbits.TMR0ON = 1;	//enable timer0;
		while(INTCONbits.TMR0IF == 0);

		T0CONbits.TMR0ON = 0;	//disable timer0;
		INTCONbits.TMR0IF = 0;	//clear IF flag;	
//}
}
void main ()
{  
   
   TRISBbits.RB4=0;
   mybit=0;
while(1)
       {
 			mybit=0;
			T0delay();
            mybit=1;
            T0delay(); 
       }

}