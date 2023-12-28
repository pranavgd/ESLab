#include <reg51.h>
sbit button Pl ^ 0;
sbit relay = P3 ^ 0;
void main()
{
    button = 1;
    relay = 0;
    while (1)
    {
        while (button == 0)
        {
            relay = 1;
        }
        relay = 0;
    }
}