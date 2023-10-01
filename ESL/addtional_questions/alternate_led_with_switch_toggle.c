#include<LPC17xx.h>
unsigned int i,j,led;
int main(void)
{
SystemInit();
SystemCoreClockUpdate(); 
     LPC_GPIO0->FIODIR |= 0X00000FF0;
LPC_GPIO2->FIODIR &= 0XFFFFFEFF;
while(1){
if(LPC_GPIO2->FIOPIN & 1<<12)
     { led=0x00000020;
             for(i=0;i<4;i++)
     {
            LPC_GPIO0->FIOCLR=led;
             for(j=0;j<1000;j++);
             led=led<<2;
     }
         led=0x00000010;
     for(i=0;i<4;i++)
     {
            LPC_GPIO0->FIOSET=led;
             for(j=0;j<1000;j++);
             led=led<<2;
     }
     }
         else
         { led=0x00000010;
             for(i=0;i<4;i++)
     {
            LPC_GPIO0->FIOCLR=led;
             for(j=0;j<1000;j++);
             led=led<<2;
     }
         led=0x00000020;
         for(i=0;i<4;i++)
     {
            LPC_GPIO0->FIOSET=led;
             for(j=0;j<1000;j++);
             led=led<<2;
     }
         }
}
}
