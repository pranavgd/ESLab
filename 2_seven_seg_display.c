#include "reg51.h"
sbit firstbit = P3^0;  //First bit control
sbit secondbit = P3^1;  //second bit control

void DELAY_ms(unsigned int ms_Count)
{
    unsigned int i,j;
    for(i=0;i< ms_Count;i++)
    {
        for(j=0;j< 100;j++);
    }
}


int main()
{
   char hexvalue[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
   char cnt=99;
   int i;
   while(1)
    {	   
	    for(i=0;i<=cnt;i++)	 // loop to display 0-99
			
		 {
			 for (i = 0; i < 1000; i++){
		 DELAY_ms(200);;  //add delay of 1sec delay	
		 P2 = hexvalue[cnt];	 // Send the segment_code of number to be displayed	 
     firstbit  = 1;  //  set second digit high
		 secondbit  = 0;  //  set first digit low
     P2 = hexvalue[i%10u];
     DELAY_ms(60);;  //add delay of 60ms delay
     secondbit  = 1;  //  set secod digit high
		 firstbit  = 0;  //  set firstdigit low
     P2 = hexvalue[(i/10)%10u];
     DELAY_ms(60);;  //add delay of  60ms delay	
		 }
	 }
	}												  
}	