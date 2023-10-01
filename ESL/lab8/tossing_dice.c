#include<lpc17xx.h>
#include<stdlib.h>
unsigned int r;
void delay_lcd(unsigned int r1) { for (r=0;r<r1;r++); }
void clear_ports(void)
{
    LPC_GPIO0->FIOCLR = 0x0F<<23; //Clearing data lines
    LPC_GPIO0->FIOCLR = 1<<27; //Clearing RS line
    LPC_GPIO0->FIOCLR = 1<<28; //Clearing Enable line
    return;
}
void write(int temp2, int type) //write to command/data reg
{
    clear_ports(); LPC_GPIO0->FIOPIN = temp2; // Assign the value to the data lines
    if(type==0) LPC_GPIO0->FIOCLR = 1<<27; // clear bit RS for Command
    else LPC_GPIO0->FIOSET = 1<<27; // set bit RS for Data
    LPC_GPIO0->FIOSET = 1<<28; // EN=1
    delay_lcd(25);
    LPC_GPIO0->FIOCLR = 1<<28; // EN =0
    return;
}
void lcd_comdata(int temp1, int type)
{
    int temp2 = temp1 & 0xf0; temp2 = temp2 << 19;
    write(temp2, type); temp2 = temp1 & 0x0f;
    temp2 = temp2 << 23; write(temp2, type);
    delay_lcd(1000); return;
}
void lcd_init()
{
    LPC_PINCON->PINSEL1 &= 0xFC003FFF; //P0.23 to P0.28
    LPC_GPIO0->FIODIR |= 0x0F<<23 | 1<<27 | 1<<28;
    clear_ports(); delay_lcd(3200); lcd_comdata(0x33, 0);
    delay_lcd(30000); lcd_comdata(0x32, 0);
    delay_lcd(30000); lcd_comdata(0x28, 0); //function set
    delay_lcd(30000); lcd_comdata(0x0c, 0);//display on cursor off
    delay_lcd(800); lcd_comdata(0x06, 0); //entry mode set increment cursor right
    delay_lcd(800); lcd_comdata(0x01, 0); //display clear
    delay_lcd(10000); return;
}
void lcd_puts(unsigned char *buf1)
{
    unsigned int i=0,temp3;
    while(buf1[i]!='\0')
    {
        temp3 = buf1[i++];
        lcd_comdata(temp3, 1);
        if(i==16) lcd_comdata(0xc0, 0);
    }
    return;
}
int main(void)
{
    unsigned char Msg[1]; unsigned int k; srand(rand());
    SystemInit(); SystemCoreClockUpdate(); lcd_init();
    LPC_PINCON->PINSEL4&=0xFCFFFFFF;
    LPC_GPIO2->FIODIR|=0x00000000;
    while(1)
    {
        k=(LPC_GPIO2->FIOPIN)>>12; k&=1;
        if (k==0)
        {
            lcd_comdata(0x80,0); delay_lcd(800);
            Msg[0]=(rand()%6+1)+'0'; lcd_puts(&Msg[0]);
        }
    }
}
