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
{
    for(i=0;i<256;i++)
    {
    LPC_GPIO0->FIOPIN=i<<4;
        for(j=0;j<10000;j++);
    }
}
else
{
for(i=256;i>0;i--)
    {
    LPC_GPIO0->FIOPIN=i<<4;
        for(j=0;j<10000;j++);
    }
}
    
}
}
