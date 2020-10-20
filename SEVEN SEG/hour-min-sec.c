#include <p18f4550.h>
#define E1 PORTCbits.RC0
#define E2 PORTCbits.RC1
#define E3 PORTCbits.RC2
#define E4 PORTCbits.RC4
#define E5 PORTCbits.RC5
#define E6 PORTCbits.RC6
void delay_ms(unsigned int time);

   

void main()
 {
char a[]={0xC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};
 int i,j,k,l,m,n,p;
TRISD=0X00;
TRISC=0X00;

while(1)
{
for(i=0;i<6;i++)
{
 for(j=0;j<10;j++)
 {
  for(k=0;k<6;k++)
  {         
   for(l=0;l<10;l++)
   {
	for(m=0;m<6;m++)
	{
	 for(n=0;n<10;n++)
	 {	
    for(p=0;p<166;p++)
     {
	     
      E1=1;
      LATD=a[i];
      delay_ms(1);
      E1=0;
      
      E2=1;
      LATD=a[j];
      delay_ms(1);
      E2=0;
      
      E3=1;
      LATD=a[k];
      delay_ms(1);
      E3=0;
      
      E4=1;
      LATD=a[l];
      delay_ms(1);
      E4=0;
      
      E5=1;
      LATD=a[m];
      delay_ms(1);
      E5=0;
      
      E6=1;
      LATD=a[n];
      delay_ms(1);
      E6=0;
        
    }
    }
    }
    }
    }
    }
    }
}
}
void delay_ms(unsigned int time)
{

  unsigned int n;
  unsigned char o;
  for(n=0;n<time;n++)
{
   for(o=0;o<165;o++);
}
}