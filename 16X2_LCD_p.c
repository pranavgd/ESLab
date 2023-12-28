#include <REG51.H>
#include <string.h>
#include <stdio.h>

sfr LCD = 0x80;

sbit EN = P2 ^ 1;
sbit RS = P2 ^ 0;

void nop(void);
void delay_1s(unsigned char t);
void initial_lcd(void);
void delay(void);
void string_to_lcd(unsigned char *s);
void write_lcd(unsigned char dat, unsigned int com);
void delay_50ms(unsigned char x);

void main()
{

    P1 = 0xff;
    P2 = 0xff;
    P3 = 0xff;
    delay_50ms(4);
    initial_lcd();
    write_lcd(0x80, 0);
    string_to_lcd("   Welcome to   ");
    write_lcd(0xc0, 0);
    string_to_lcd("Electronics Hub ");
}

void nop(void)
{

    unsigned char n;
    for (n = 0; n < 20; n++)
        ;
}

//..................delay routine.................//

void delay_1s(unsigned char t)
{

    unsigned char i, j;
    for (i = 0; i < t; i++)

    {

        for (j = 0; j < 20; j++)

        {

            TMOD = 0x01;
            TH0 = 0x3c; // for 12MHz   (12/12MHZ)=1u>per cycle operation
            TL0 = 0xb0; // 50ms delay get (50m/1u)=50000;
            TR0 = 1;    // Load value is =65536-50000=15536(=3cb0H)

            while (TF0 != 1)
                ; // wait for overflow flag
            TF0 = 0;
        }
    }
}

void initial_lcd(void)
{

    write_lcd(0x38, 0);
    write_lcd(0x0c, 0);
    write_lcd(0x01, 0);
}

void write_lcd(unsigned char dat, unsigned int com)
{

    RS = com;
    LCD = dat;
    nop();
    EN = 1;
    nop();
    EN = 0;
    nop();
}

void string_to_lcd(unsigned char *s)

{

    unsigned char i, l;
    l = strlen(s);
    for (i = 0; i < l; i++)

    {

        write_lcd(*s, 1);
        delay_50ms(1);
        s++;
    }
}

void delay_50ms(unsigned char x)
{

    unsigned char i;
    for (i = 0; i < x; i++)

    {

        TMOD = 0x01;
        TH0 = 0x3c;
        TL0 = 0xb0;
        TR0 = 1;
        while (!TF0)
            ;
        TF0 = 0;
        TR0 = 0;
    }
}

// code 2
#include <reg51.h>
#define cmdport P2
#define dataport P0

sbit rs = cmdport ^ 0; // register select pin
sbit e = cmdport ^ 1;  // enable pin

void delay(unsigned int msec) // Function to provide time delay in msec.

{

    int i, j;
    for (i = 0; i < msec; i++)
        for (j = 0; j < 1275; j++)
            ;
}

void lcdcmd(unsigned char item) // Function to send command to LCD

{

    dataport = item;
    rs = 0;
    e = 1;
    delay(1);
    e = 0;
}

void lcddata(unsigned char item) // Function to send data to LCD

{

    dataport = item;
    rs = 1;
    e = 1;
    delay(1);
    e = 0;
}

void main()

{

    lcdcmd(0x38); // for using 8-bit 2 row mode of LCD
    delay(100);
    lcdcmd(0x0C); // turn display ON and cursor OFF
    delay(100);
    lcdcmd(0x01); // clear screen
    delay(100);
    lcdcmd(0x86); // bring cursor to position 6 of line 1
    delay(100);
    lcddata('A');
}