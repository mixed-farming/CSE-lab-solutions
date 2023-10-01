#include<LPC17xx.h>
unsigned int seg[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
int d[4],i,j;
void timer()
{
    LPC_TIM0->CTCR=0X0; // making it a timer
    LPC_TIM0->TCR=0X2; //RESETTING IT
    LPC_TIM0->PR=2999;
    LPC_TIM0->TCR=0X1; //ENABLE
    while(LPC_TIM0->TC <= 100); // ONE SECOND DELAY
    LPC_TIM0->TCR=0X0; //DISABLE
}
int main(void)
{
    LPC_PINCON->PINSEL0&=0XFF0000FF; // OUTPUT TO 7 SEG 0.4-0.11
    LPC_PINCON->PINSEL3=0X0; // DECODER TO ENABLE 1.23-1.26
    LPC_GPIO0->FIODIR=0X00000FF0; //SETTING OUTPUUT PINS
    LPC_GPIO1->FIODIR|=0X07800000; // SETTING OUTPUT PINS
    LPC_PINCON->PINSEL1=0x0;
    while(1)
    {
        unsigned int k=LPC_GPIO0->FIOPIN>>21; k&=1;
        if(k==0)
        {
            for(d[3]=0;d[3]<=0;d[3]++)
            {
                for(d[2]=0;d[2]<=0;d[2]++)
                {
                    for(d[1]=0;d[1]<10;d[1]++)
                    {
                        for(d[0]=0;d[0]<10;d[0]++)
                        {
                            for(i=0;i<4;i++)
                            {
                                LPC_GPIO1->FIOPIN=i<<23;
                                LPC_GPIO0->FIOPIN=seg[d[i]]<<4;
                                for(j=0;j<10000;j++);
                            }
                            timer(); LPC_GPIO0->FIOCLR = 0X00000FF0;
                        }
                    }
                }
            }
        }
        else
        {
            for(d[3]=0;d[3]>=0;d[3]--)
            {
                for(d[2]=0;d[2]>=0;d[2]--)
                {
                    for(d[1]=9;d[1]>=0;d[1]--)
                    {
                        for(d[0]=9;d[0]>=0;d[0]--)
                        {
                            for(i=3;i>=0;i--)
                            {
                                LPC_GPIO1->FIOPIN=i<<23;
                                LPC_GPIO0->FIOPIN=seg[d[i]]<<4;
                                 for(j=0;j<10000;j++);
                            }
                            timer(); LPC_GPIO0->FIOCLR = 0X00000FF0;
                        }
                    }
                }
            }
        }
    }
}
