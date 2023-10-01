#include <LPC17xx.h>
unsigned int i,j,k,c=1;

 

int main(void)
{
  LPC_PINCON->PINSEL0 &= 0xFF0000FF; //pin 0.4-0.11 as gpio function
  LPC_PINCON->PINSEL4 &= 0xFCFFFFFF; //for pin 2.12 gpio2 as switch
  LPC_GPIO0->FIODIR |= 0x00000FF0; //config as output pin
  LPC_GPIO2->FIODIR &= 0xFFFFEFFF; //pin 12 is made to be 0 since i/p
  while(1)
  {
    k = LPC_GPIO2->FIOPIN >> 12;
    k&=0x00000001; //reads switch press
    if(k==0)
    //{
    LPC_GPIO0->FIOPIN=c<<4;
    for(i=0;i<10000;i++);
    if(c==0x80)
      c=1;
    else
      c<<=1;
  }
}
