#include <reg51.h>

// Define port for 7-segment display
sbit segA = P2^0;
sbit segB = P2^1;
sbit segC = P2^2;
sbit segD = P2^3;
sbit segE = P2^4;
sbit segF = P2^5;
sbit segG = P2^6;
sbit segDP = P2^7;

// Function to display a digit on the 7-segment display
void displayDigit(unsigned char digit) {
    // Define the 7-segment patterns for digits 0-9
    unsigned char patterns[] = {
        0xC0,  // 0
        0xF9,  // 1
        0xA4,  // 2
        0xB0,  // 3
        0x99,  // 4
        0x92,  // 5
        0x82,  // 6
        0xF8,  // 7
        0x80,  // 8
        0x90   // 9
    };
    
    // Display the appropriate pattern for the given digit
    P1 = 0xFF - patterns[digit];		//Common Cathode
		//P1 = patterns[digit];					//Common Anode
}


void delay(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 112; j++) {
            // Adjust the values based on your clock frequency
        }
    }
}

void main() {
		int digit;
    while (1) {
        // Display digits 0 to 9 on the 7-segment display
        for ( digit = 0; digit < 10; digit++) {
            displayDigit(digit);
            delay(1000);  // Delay to control the display speed
        }
    }
}
