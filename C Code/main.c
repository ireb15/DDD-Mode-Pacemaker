#include <system.h> // to use the symbolic names
#include <altera_avalon_pio_regs.h> // to use PIO functions
#include <stdio.h> //to use LCD
#include <alt_types.h> // alt_u32 is a kind of alt_types
#include <sys/alt_irq.h> // to register interrupts
#include <string.h>
#include <stdlib.h>
#include "sys/alt_alarm.h"
#include "Mode1.c"

// Example timeout values in milliseconds 
#define AVI_VALUE 300 
#define AEI_VALUE 800 
#define PVARP_VALUE 50 
#define VRP_VALUE 150 
#define LRI_VALUE 950 
#define URI_VALUE 900

//LED CONFIG
#define APACE_LED 0x8
#define VPACE_LED 0X4
#define ASENSE_LED 0X2
#define VSENSE_LED 0x1

//Global Variables
int currentMode = 0;
int prevMode = 0;
int ticks_per_second = alt_ticks_per_second();
int AVI_ticks = 0;

//Timers
alt_alarm AVI_timer;
alt_alarm AEI_timer;
alt_alarm LRI_timer;
alt_alarm URI_timer;
alt_alarm PVARP_timer;
alt_alarm VRP_timer;

alt_u32 AVI_timer_ISR(void* context) {
	AVI_ex = 1;
	return 0;
}

alt_u32 AEI_timer_ISR(void* context) {
	AEI_ex = 1;
	return 0;
}

alt_u32 LRI_timer_ISR(void* context) {
	LRI_ex = 1;
	return 0;
}

alt_u32 URI_timer_ISR(void* context) {
	URI_ex = 1;
	return 0;
}

alt_u32 PVARP_timer_ISR(void* context) {
	PVARP_ex = 1;
	return 0;
}

alt_u32 VRP_timer_ISR(void* context) {
	VRP_ex = 1;
	return 0;
}

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
	if (mode == R1_STATE || mode == R2_STATE) {
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
	//Reset SCCharts if mode has changed
	if (currentMode != prevMode) {
		prevMode = currentMode;
		reset();
	}
	return 0;
}

int timer_handler() {
		//Check Start
		if (AVI_start) {
			//Start AVI timer interrupt
			alt_alarm_start(&AVI_timer, AVI_VALUE, AVI_timer_ISR, NULL);
		}
		if (PVARP_start) {
			//Start PVARP timer interrupt
			alt_alarm_start(&PVARP_timer, PVARP_VALUE, PVARP_timer_ISR, NULL);
		}
		if (AEI_start) {
			//Start AEI timer interrupt
			alt_alarm_start(&AEI_timer, AEI_VALUE, AEI_timer_ISR, NULL);
		}
		if (VRP_start) {
			//Start PVARP timer interrupt
			alt_alarm_start(&VRP_timer, VRP_VALUE, VRP_timer_ISR, NULL);
		}
		if (LRI_start) {
			//Start LRI timer interrupt
			alt_alarm_start(&LRI_timer, LRI_VALUE, LRI_timer_ISR, NULL);
		}
		if (URI_start) {
			//Start PVARP timer interrupt
			alt_alarm_start(&URI_timer, URI_VALUE, URI_timer_ISR, NULL);
		}
		
		//Check Stop
		if (AVI_stop) {
			//Start AVI timer interrupt
			alt_alarm_stop(&AVI_timer);
		}
		if (PVARP_stop) {
			//Start PVARP timer interrupt
			alt_alarm_stop(&PVARP_timer);
		}
		if (AEI_stop) {
			//Start AEI timer interrupt
			alt_alarm_stop(&AEI_timer);
		}
		if (VRP_stop) {
			//Start VRP timer interrupt
			alt_alarm_stop(&VRP_timer);
		}
		if (LRI_stop) {
			//Start LRI timer interrupt
			alt_alarm_stop(&LRI_timer);
		}
		if (URI_stop) {
			//Start PVARP timer interrupt
			alt_alarm_stop(&URI_timer);
		}
		return 0;
}

int setLights() {
	//Thinking about adding a timer to handle extending LED on duration
	if (APace)
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, APACE_LED);
	else if (VPace)
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, VPACE_LED);
	else if (ASense)
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, ASENSE_LED);
	else if (VSense)
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, VSENSE_LED);
	else
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 0);
	return 0;
}

int main(void) {
	//Initialize with AVI timer
	AVI_ex = 1;
	while (1) {
		tick();
		switch_check();
		//Poll timers in SCCharts code
		timer_handler();
		//Set Lights
		setLights();
	}
	return 0;
}
