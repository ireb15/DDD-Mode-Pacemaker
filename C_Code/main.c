#include <system.h> // to use the symbolic names
#include <altera_avalon_pio_regs.h> // to use PIO functions
#include <stdio.h> //to use LCD
#include <alt_types.h> // alt_u32 is a kind of alt_types
#include <sys/alt_irq.h> // to register interrupts
#include <string.h>
#include <stdlib.h>
#include "sys/alt_alarm.h"
#include "mode1.h"
#include "mode1.c"

// Example timeout values in milliseconds
#define AVI_VALUE 1000
#define AEI_VALUE 1000
#define PVARP_VALUE 1000
#define VRP_VALUE 1000
#define LRI_VALUE 1000
#define URI_VALUE 1000

#define ESC 27
#define CLEAR_LCD_STRING "[2J"

//LED CONFIG
#define APACE_LED 0x8
#define VPACE_LED 0X4
#define ASENSE_LED 0X2
#define VSENSE_LED 0x1
#define LED_TIMEOUT 50

//Global Variables
int currentMode = 0;
int prevMode = 0;
int AVI_ticks = 0;
int buttonValue = 1;

//Timers
alt_alarm AVI_timer;
alt_alarm AEI_timer;
alt_alarm LRI_timer;
alt_alarm URI_timer;
alt_alarm PVARP_timer;
alt_alarm VRP_timer;
alt_alarm LED_timer;

alt_u32 LED_timer_ISR(void* context) {
	IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 0);
	return 0;
}

alt_u32 AVI_timer_ISR(void* context) {
	printf("AVI_Expired\n");
	AVI_ex = 1;
	return 0;
}

alt_u32 AEI_timer_ISR(void* context) {
	printf("AEI_Expired\n");
	AEI_ex = 1;
	return 0;
}

alt_u32 LRI_timer_ISR(void* context) {
	printf("LRI_Expired\n");
	LRI_ex = 1;
	return 0;
}

alt_u32 URI_timer_ISR(void* context) {
	printf("URI_Expired\n");
	URI_ex = 1;
	return 0;
}

alt_u32 PVARP_timer_ISR(void* context) {
	printf("PVARP_Expired\n");
	PVARP_ex = 1;
	return 0;
}

alt_u32 VRP_timer_ISR(void* context) {
	printf("VRP_Expired\n");
	VRP_ex = 1;
	return 0;
}

void buttons_isr(void* context, alt_u32 id) {
	printf("Button");
	unsigned int temp = IORD_ALTERA_AVALON_PIO_EDGE_CAP(BUTTONS_BASE);
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(BUTTONS_BASE, 0);
	if (temp == 1) {
		VSense = 1;
	}
	if (temp == 2) {
		ASense = 1;
	}
	return;
}

void init_buttons_pio() {
	void* context_to_be_passed = (void*) &buttonValue;
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(BUTTONS_BASE, 0);
	IOWR_ALTERA_AVALON_PIO_IRQ_MASK(BUTTONS_BASE, 0x7);
	alt_irq_register(BUTTONS_IRQ, context_to_be_passed, buttons_isr);
	return;
}

int lcd_update(int mode) {
	FILE *lcd;
	lcd = fopen(LCD_NAME, "w");
	fprintf(lcd, "%c%s", ESC, CLEAR_LCD_STRING);
	if (mode == 2)
	fprintf(lcd, "Current Mode: 2\n Using UART");
	else if (mode == 1)
	fprintf(lcd, "Current Mode: 1\n Using Buttons");
	fclose(lcd);
	return 0;
}

int switch_check() {
	/* Checks State of Switches and Updates Modes Accordingly */
	int mode = IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE);
	//Mode Check
	if (mode & (1 << 0)) {
		currentMode = 2;
	} else {
		currentMode = 1;
	}
	//Reset SCCharts if mode has changed
	if (currentMode != prevMode) {
		lcd_update(currentMode);
		prevMode = currentMode;
		reset();
	}
	return 0;
}


int timer_handler() {
		if (AVI_start) {
			printf("AVI_start\n");
			//Start AVI timer interrupt
			alt_alarm_start(&AVI_timer, AVI_VALUE, AVI_timer_ISR, NULL);
		}
		if (PVARP_start) {
			printf("PVARP_start\n");
			//Start PVARP timer interrupt
			alt_alarm_start(&PVARP_timer, PVARP_VALUE, PVARP_timer_ISR, NULL);
		}
		if (AEI_start) {
			printf("AEI_start\n");
			//Start AEI timer interrupt
			alt_alarm_start(&AEI_timer, AEI_VALUE, AEI_timer_ISR, NULL);
		}
		if (VRP_start) {
			printf("VRP_start\n");
			//Start PVARP timer interrupt
			alt_alarm_start(&VRP_timer, VRP_VALUE, VRP_timer_ISR, NULL);
		}
		if (LRI_start) {
			printf("LRI_start\n");
			//Start LRI timer interrupt
			alt_alarm_start(&LRI_timer, LRI_VALUE, LRI_timer_ISR, NULL);
		}
		if (URI_start) {
			printf("URI_start\n");
			//Start PVARP timer interrupt
			alt_alarm_start(&URI_timer, URI_VALUE, URI_timer_ISR, NULL);
		}

		//Check Stop
		if (AVI_stop) {
			printf("AVI_Stop\n");
			//Start AVI timer interrupt
			alt_alarm_stop(&AVI_timer);
		}
		if (PVARP_stop) {
			printf("PVARP_Stop\n");
			//Start PVARP timer interrupt
			alt_alarm_stop(&PVARP_timer);
		}
		if (AEI_stop) {
			printf("AEI_Stop\n");
			//Start AEI timer interrupt
			alt_alarm_stop(&AEI_timer);
		}
		if (VRP_stop) {
			printf("VRP_Stop\n");
			//Start VRP timer interrupt
			alt_alarm_stop(&VRP_timer);
		}
		if (LRI_stop) {
			printf("LRI_Stop\n");
			//Start LRI timer interrupt
			alt_alarm_stop(&LRI_timer);
		}
		if (URI_stop) {
			printf("URI_Stop\n");
			//Start PVARP timer interrupt
			alt_alarm_stop(&URI_timer);
		}
		printf("Finished timer handler\n");
		return 0;
}

int setLights() {
	//Thinking about adding a timer to handle extending LED on duration
	if (APace) {
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, APACE_LED);
		printf("APace\n");
	}
	else if (VPace) {
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, VPACE_LED);
		printf("VPace\n");
	}
	else if (ASense) {
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, ASENSE_LED);
		printf("ASense\n");
	}
	else if (VSense) {
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, VSENSE_LED);
		printf("VSense\n");
	}
	// Keep LEDs on for 50ms
	alt_alarm_start(&LED_timer, LED_TIMEOUT, LED_timer_ISR, NULL);
	return 0;
}

int main(void) {
	tick();
	//Initialize with AVI timer
	reset();
	VSense = 1;
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
