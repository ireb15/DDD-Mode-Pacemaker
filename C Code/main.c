#include <system.h> // to use the symbolic names
#include <altera_avalon_pio_regs.h> // to use PIO functions
#include <stdio.h> //to use LCD
#include <alt_types.h> // alt_u32 is a kind of alt_types
#include <sys/alt_irq.h> // to register interrupts
#include <string.h>
#include <stdlib.h>
#include "sys/alt_alarm.h"

// Example timeout values in milliseconds 
#define AVI_VALUE 300 
#define AEI_VALUE 800 
#define PVARP_VALUE 50 
#define VRP_VALUE 150 
#define LRI_VALUE 950 
#define URI_VALUE 900

//Global Variables
int currentMode = 0;

int switch_check() {
	/* Checks State of Switches and Updates Modes Accordingly
	 * Also updates LCD */ 
	// Open LCD to Write
	FILE *lcd;
	lcd = fopen(LCD_NAME, "w");
	// Clear LCD
	fprintf(lcd, "%c%s", ESC, CLEAR_LCD_STRING);
	// Get Switch Values
	int mode = IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE);
	//Mode Change Can Only Happen in Safe State
	if (currentState == R1_STATE || currentState == R2_STATE) {
		//Mode Check
		if (mode & (1 << 0)) {
			fprintf(lcd, "Current Mode: 2\n Using UART\n", mode);
			currentMode = 2;
		} else {
			fprintf(lcd, "Current Mode: 1\n Using Buttons\n", mode);
			currentMode = 1;
		}
	}
	// Close LCD
	fclose lcd;
	return 0;
}

int main(void) {
	while (1) {
		switch_check();
	}
	return 0;
}