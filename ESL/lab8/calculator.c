#include <LPC17xx.h>
#include "lcd.h"
void scan(void);

unsigned long int i,var1,temp,temp1,temp2,temp3;
unsigned char row,var,flag,key;
unsigned char scan_code[16]={0x11,0x21,0x41,0x81,0x12,0x22,0x42,0x82,0x14,0x24,0x44,0x84,0x18,0x28,0x48,0x88};
unsigned char ascii_code[16]={'0','1','2','3','4','5','6','7','8','9','A','B','+','-','*','/'};
int idx=1, ans=1 , a=0,b=0,count=0;
char op;
unsigned char finans[3]={'0','0','\0'};

int main(void)
{
SystemInit();
SystemCoreClockUpdate();
LPC_GPIO2->FIODIR |= 0x3C00;
    LPC_GPIO1->FIODIR &= 0xF87FFFFF;
/*LPC_GPIO0->FIODIR |= 0x0F<<23 | 1<<27 | 1<<28 ;
    clear_ports();
    delay_lcd(3200);*/
    
    lcd_init();
     temp1=0x80;
    lcd_com();
    delay_lcd(800);
    while(count<3)
    {
while(1)
{
for(row=1;row<5;row++)
{
if(row == 1)
var1 = 0x00000400;
else if(row == 2)
var1 = 0x00000800;
else if(row == 3)
var1 = 0x00001000;
else if(row == 4)
var1 = 0x00002000;
temp = var1;
LPC_GPIO2->FIOCLR = 0x00003C00;
LPC_GPIO2->FIOSET = var1;
flag = 0;
scan();
if(flag == 1)
{
    count ++;
break;
}} //end for(row=1;row<5;row++)
if(flag == 1)
break;
} //2nd while(1)
for(i=1;i<=16;i++)
{
    if(key==scan_code[i])
    {
        key=ascii_code[i];
        lcd_puts(&key);
        delay_lcd(150000);
        if(count==1)
        {
            a=key-48;
        }
        else if(count==2)
        {
            op=key;
        }
        else if(count==3)
        {
            b=key-48;
        }
        break;
    }
}}
temp2=0xC0;
lcd_com();
delay_lcd(800);
switch(op)
{
    case '+' : ans=a+b;
                            break;
    
    case '-' : ans=a-b;
                            break;
    
    case '*' : ans=a*b;
                            break;
    
    case '/' : ans=a/b;
                            break;
}
while(ans!=0)
{
    finans[idx--]=(ans%10)+48;
    ans=ans/10;}
lcd_puts(&finans[0]);
}

void scan(void)
{
    temp3=LPC_GPIO1->FIOPIN;
    temp3 &= 0xF << 23;
    if(temp3 !=0)
    {
flag =1 ;
temp3 = temp3 >> 19;    
temp =temp >>10;
key=temp3 |temp ;
}
    }
