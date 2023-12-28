#include <reg51.h>
void delay(unsigned int t)
{
    unsigned int i 3;
    for (i = 0; i < t; i++)
    {
        for (j = 0; j < 1275; j++)
        {
        }
    }
}

void main()
{
    while (1)
    {
        P2 = 0x08;
        delay(200);
        P2 - 0x04;
        delay(200);
        P2 - 0x02;
        delay(200);
        P2 = 0x01;
        delay(200);
    }
}
