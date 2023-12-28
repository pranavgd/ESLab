#include<reg51.h>

char col [5]={0x01,0x02,0x04,0x08,0x10};
char row_a [5]={0x81,0xEE,0x0EE,0xEE,0x81};
char row_S[5] = {0xB0, 0xB6, 0xB6, 0xB6, 0x86};
char row_r[5] = {0x80, 0xf6, 0xe6, 0xd6, 0xb0};
void delay(){
	unsigned int i,j;
	for(i=0 ; i<1 ; i++){
		for(j=0 ; j<500 ; j++);
	}
}

void main(){
	unsigned int l;
	P2=0x00;
	P3=0x00;
	while(1){
		for(l=0 ; l<5 ; l++){
			P2=col[l];
			P3=row_r[l];
			delay();
		}
	}
}