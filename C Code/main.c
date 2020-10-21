#include <system.h> // to use the symbolic names
#include <altera_avalon_pio_regs.h> // to use PIO functions
#include <stdio.h> //to use LCD
#include <alt_types.h> // alt_u32 is a kind of alt_types
#include <sys/alt_irq.h> // to register interrupts
#include <string.h>
#include <stdlib.h>
#include "sys/alt_alarm.h"
#include "mode1.h"
#include "sccharts.h"
#include "fcntl.h"

// SCCharts Functions VOID and TICK
void reset() {
	_GO = 1;
	_PRE_GO = 0;
	PRE_g3 = 0;
	PRE_g6 = 0;
	PRE_g8 = 0;
	PRE_g11 = 0;
	PRE_g21 = 0;
	PRE_g24 = 0;
	PRE_g28 = 0;
	PRE_g33 = 0;
	PRE_g35 = 0;
	PRE_g46 = 0;
	PRE_g48 = 0;
	PRE_g53 = 0;
	PRE_g55 = 0;
	PRE_g60 = 0;
	PRE_g63 = 0;
	PRE_g69 = 0;
	PRE_g71 = 0;
	PRE_g76 = 0;
	PRE_g79 = 0;
	PRE_g85 = 0;
	PRE_g93 = 0;
	PRE_g104 = 0;
	PRE_g106 = 0;
	PRE_g111 = 0;
	PRE_g114 = 0;
	PRE_g116 = 0;
	PRE_g125 = 0;
	PRE_g127 = 0;
	PRE_g132 = 0;
	PRE_g135 = 0;
	PRE_g141 = 0;
	PRE_g143 = 0;
	PRE_g149 = 0;
	return;
}
void tick() {
	if (_PRE_GO == 1) {
		_GO = 0;
	}
	{
		g0 = _GO;
		g1 = g0;
		g2 = g1;
		g150 = (PRE_g149);
		g148 = g0;
		g149 = (g150 || g148);
		if (g149) {
			VPace = 0;
			APace = 0;
			LRI_start = 0;
			LRI_stop = 0;
			URI_start = 0;
			URI_stop = 0;
			VRP_start = 0;
			VRP_stop = 0;
			AVI_start = 0;
			AVI_stop = 0;
			AEI_start = 0;
			AEI_stop = 0;
			PVARP_start = 0;
			PVARP_stop = 0;
		}
		g86 = (PRE_g85);
		_cg86 = URI_ex;
		g87 = (g86 && _cg86);
		if (g87) {
			VPace = (VPace || 1);
		}
		g94 = (PRE_g93);
		_cg94 = AVI_ex;
		g95 = (g94 && _cg94);
		if (g95) {
			VPace = (VPace || 1);
		}
		g4 = (PRE_g3);
		_cg4 = VSense;
		g17 = (g4 && (!(_cg4)));
		_cg17 = VPace;
		g3 = (g2 || (g17 && (!(_cg17))));
		g5 = (g4 && _cg4);
		if (g5) {
			LRI_start = (LRI_start || 1);
		}
		g7 = (PRE_g6);
		_cg7 = VRP_ex;
		g18 = (g17 && _cg17);
		if (g18) {
			LRI_start = (LRI_start || 1);
		}
		g12 = (PRE_g11);
		g12b = g12;
		if (g12b) {
			LRI_start = (LRI_start || 1);
		}
		g6 = ((g7 && (!(_cg7))) || g18 || g5 || g12b);
		g9 = (PRE_g8);
		_cg9 = VSense;
		g13 = (g9 && (!(_cg9)));
		_cg13 = VPace;
		g15 = (g13 && (!(_cg13)));
		_cg15 = LRI_ex;
		g8 = ((g7 && _cg7) || (g15 && (!(_cg15))));
		g10 = (g9 && _cg9);
		if (g10) {
			LRI_stop = (LRI_stop || 1);
		}
		g14 = (g13 && _cg13);
		if (g14) {
			LRI_stop = (LRI_stop || 1);
		}
		g16 = (g15 && _cg15);
		if (g16) {
			VPace = (VPace || 1);
		}
		g11 = (g14 || g16 || g10);
		g20 = g1;
		g22 = (PRE_g21);
		_cg22 = VSense;
		g42 = (g22 && (!(_cg22)));
		_cg42 = VPace;
		g25 = (PRE_g24);
		_cg25 = URI_ex;
		g26 = (g25 && _cg25);
		if (g26) {
			URI_stop = (URI_stop || 1);
		}
		g29 = (PRE_g28);
		_cg29 = URI_ex;
		g30 = (g29 && _cg29);
		if (g30) {
			URI_stop = (URI_stop || 1);
		}
		g34 = (PRE_g33);
		_cg34 = VSense;
		g37 = (g34 && (!(_cg34)));
		_cg37 = URI_ex;
		g38 = (g37 && _cg37);
		if (g38) {
			URI_stop = (URI_stop || 1);
		}
		g21 = (g20 || (g42 && (!(_cg42))) || g26 || g30 || g38);
		g23 = (g22 && _cg22);
		if (g23) {
			URI_start = (URI_start || 1);
		}
		g27 = (g25 && (!(_cg25)));
		_cg27 = PVARP_ex;
		g41 = (g27 && (!(_cg27)));
		_cg41 = VRP_ex;
		g43 = (g42 && _cg42);
		if (g43) {
			URI_start = (URI_start || 1);
		}
		g36 = (PRE_g35);
		g36b = g36;
		if (g36b) {
			URI_start = (URI_start || 1);
		}
		g24 = (g23 || (g41 && (!(_cg41))) || g43 || g36b);
		g31 = (g29 && (!(_cg29)));
		_cg31 = VRP_ex;
		g39 = (g31 && (!(_cg31)));
		_cg39 = PVARP_ex;
		g28 = ((g27 && _cg27) || (g39 && (!(_cg39))) || (g41 && _cg41));
		g32 = (g31 && _cg31);
		if (g32) {
			URI_stop = (URI_stop || 1);
		}
		g40 = (g39 && _cg39);
		if (g40) {
			URI_stop = (URI_stop || 1);
		}
		g33 = ((g37 && (!(_cg37))) || g32 || g40);
		g35 = (g34 && _cg34);
		if (g35) {
			URI_stop = (URI_stop || 1);
		}
		g45 = g1;
		g49 = (PRE_g48);
		g49b = g49;
		_cg49 = LRI_stop;
		g50 = (g49b && (!(_cg49)));
		_cg50 = LRI_ex;
		g47 = (PRE_g46);
		g47b = g47;
		_cg47 = LRI_start;
		g46 =
				((g49b && _cg49) || (g50 && _cg50) || g45
						|| (g47b && (!(_cg47))));
		g48 = ((g47b && _cg47) || (g50 && (!(_cg50))));
		g52 = g1;
		g56 = (PRE_g55);
		g56b = g56;
		_cg56 = URI_stop;
		g57 = (g56b && (!(_cg56)));
		_cg57 = URI_ex;
		g54 = (PRE_g53);
		g54b = g54;
		_cg54 = URI_start;
		g53 =
				((g56b && _cg56) || (g57 && _cg57) || g52
						|| (g54b && (!(_cg54))));
		g55 = ((g54b && _cg54) || (g57 && (!(_cg57))));
		g59 = g1;
		g64 = (PRE_g63);
		_cg64 = VRP_ex;
		g61 = (PRE_g60);
		g61b = g61;
		_cg61 = VPace;
		g65 = (g61b && (!(_cg61)));
		_cg65 = VSense;
		g60 = ((g64 && _cg64) || (g65 && (!(_cg65))) || g59);
		g62 = (g61b && _cg61);
		if (g62) {
			VRP_start = (VRP_start || 1);
		}
		g66 = (g65 && _cg65);
		if (g66) {
			VRP_start = (VRP_start || 1);
		}
		g63 = ((g64 && (!(_cg64))) || g66 || g62);
		g68 = g1;
		g70 = (PRE_g69);
		g70b = g70;
		_cg70 = VRP_start;
		g72 = (PRE_g71);
		_cg72 = VRP_ex;
		g73 = (g72 && (!(_cg72)));
		_cg73 = VRP_stop;
		g69 = (g68 || (g70b && (!(_cg70))) || (g72 && _cg72) || (g73 && _cg73));
		g71 = ((g70b && _cg70) || (g73 && (!(_cg73))));
		g75 = g1;
		g96 = (g94 && (!(_cg94)));
		_cg96 = VSense;
		g97 = (g96 && _cg96);
		if (g97) {
			AVI_stop = (AVI_stop || 1);
		}
		g98 = (g96 && (!(_cg96)));
		_cg98 = VPace;
		g99 = (g98 && _cg98);
		if (g99) {
			AVI_stop = (AVI_stop || 1);
		}
		g80 = (PRE_g79);
		_cg80 = VSense;
		g81 = (g80 && _cg80);
		if (g81) {
			AVI_stop = (AVI_stop || 1);
		}
		g117 = (PRE_g116);
		_cg117 = ASense;
		g119 = (g117 && (!(_cg117)));
		_cg119 = AEI_ex;
		g120 = (g119 && _cg119);
		if (g120) {
			APace = (APace || 1);
		}
		g77 = (PRE_g76);
		_cg77 = ASense;
		g100 = (g77 && (!(_cg77)));
		_cg100 = APace;
		g88 = (g86 && (!(_cg86)));
		_cg88 = VSense;
		g90 = (g88 && (!(_cg88)));
		_cg90 = VPace;
		g91 = (g90 && _cg90);
		if (g91) {
			AVI_stop = (AVI_stop || 1);
		}
		g82 = (g80 && (!(_cg80)));
		_cg82 = VPace;
		g83 = (g82 && _cg82);
		if (g83) {
			AVI_stop = (AVI_stop || 1);
		}
		g89 = (g88 && _cg88);
		if (g89) {
			AVI_stop = (AVI_stop || 1);
		}
		g76 = (g75 || g97 || g99 || g81 || g87 || (g100 && (!(_cg100))) || g91
				|| g95 || g83 || g89);
		g78 = (g77 && _cg77);
		if (g78) {
			AVI_start = (AVI_start || 1);
		}
		g101 = (g100 && _cg100);
		if (g101) {
			AVI_start = (AVI_start || 1);
		}
		g84 = (g82 && (!(_cg82)));
		_cg84 = AVI_ex;
		g92 = (g84 && (!(_cg84)));
		_cg92 = URI_ex;
		g79 = (g101 || (g92 && (!(_cg92))) || g78);
		g85 = ((g84 && _cg84) || (g90 && (!(_cg90))));
		g93 = ((g92 && _cg92) || (g98 && (!(_cg98))));
		g103 = g1;
		g107 = (PRE_g106);
		_cg107 = AVI_ex;
		g108 = (g107 && (!(_cg107)));
		_cg108 = AVI_stop;
		g105 = (PRE_g104);
		g105b = g105;
		_cg105 = AVI_start;
		g104 = ((g108 && _cg108) || g103 || (g107 && _cg107)
				|| (g105b && (!(_cg105))));
		g106 = ((g105b && _cg105) || (g108 && (!(_cg108))));
		g110 = g1;
		g112 = (PRE_g111);
		_cg112 = VSense;
		g121 = (g112 && (!(_cg112)));
		_cg121 = VPace;
		g118 = (g117 && _cg117);
		if (g118) {
			AEI_stop = (AEI_stop || 1);
		}
		g111 = (g110 || g120 || (g121 && (!(_cg121))) || g118);
		g113 = (g112 && _cg112);
		if (g113) {
			AEI_start = (AEI_start || 1);
		}
		g122 = (g121 && _cg121);
		if (g122) {
			AEI_start = (AEI_start || 1);
		}
		g115 = (PRE_g114);
		_cg115 = PVARP_ex;
		g114 = (g113 || g122 || (g115 && (!(_cg115))));
		g116 = ((g115 && _cg115) || (g119 && (!(_cg119))));
		g124 = g1;
		g128 = (PRE_g127);
		_cg128 = AEI_ex;
		g126 = (PRE_g125);
		g126b = g126;
		_cg126 = AEI_start;
		g129 = (g128 && (!(_cg128)));
		_cg129 = AEI_stop;
		g125 = ((g128 && _cg128) || (g126b && (!(_cg126))) || (g129 && _cg129)
				|| g124);
		g127 = ((g126b && _cg126) || (g129 && (!(_cg129))));
		g131 = g1;
		g136 = (PRE_g135);
		_cg136 = PVARP_ex;
		g133 = (PRE_g132);
		_cg133 = VSense;
		g137 = (g133 && (!(_cg133)));
		_cg137 = VPace;
		g132 = ((g136 && _cg136) || g131 || (g137 && (!(_cg137))));
		g134 = (g133 && _cg133);
		if (g134) {
			PVARP_start = (PVARP_start || 1);
		}
		g138 = (g137 && _cg137);
		if (g138) {
			PVARP_start = (PVARP_start || 1);
		}
		g135 = ((g136 && (!(_cg136))) || g138 || g134);
		g140 = g1;
		g144 = (PRE_g143);
		_cg144 = PVARP_ex;
		g145 = (g144 && (!(_cg144)));
		_cg145 = PVARP_stop;
		g142 = (PRE_g141);
		g142b = g142;
		_cg142 = PVARP_start;
		g141 = ((g144 && _cg144) || g140 || (g145 && _cg145)
				|| (g142b && (!(_cg142))));
		g143 = ((g142b && _cg142) || (g145 && (!(_cg145))));
		g19_e1 = (!((g4 || g7 || g9 || g12)));
		g44_e2 = (!((g22 || g25 || g29 || g34 || g36)));
		g51_e3 = (!((g47 || g49)));
		g58_e4 = (!((g54 || g56)));
		g67_e5 = (!((g61 || g64)));
		g74_e6 = (!((g70 || g72)));
		g102_e7 = (!((g77 || g80 || g86 || g94)));
		g109_e8 = (!((g105 || g107)));
		g123_e9 = (!((g112 || g115 || g117)));
		g130_e10 = (!((g126 || g128)));
		g139_e11 = (!((g133 || g136)));
		g146_e12 = (!((g142 || g144)));
		g147_fix0 = ((g19_e1 || g19) && (g44_e2 || g44) && (g51_e3 || g51)
				&& (g58_e4 || g58));
		g147_fix1 = (g147_fix0 && (g67_e5 || g67) && (g74_e6 || g74)
				&& (g102_e7 || g102));
		g147_fix2 = (g19 || g44 || g51 || g58);
		g147_fix3 = (g147_fix2 || g67 || g74 || g102);
		g147_e1_fix_fix = (g128 || g144 || g7 || g25 || g64 || g80 || g115
				|| g136 || g9 || g117 || g29 || g86 || g12 || g94);
		g147_e1_fix = (g112 || g126 || g133 || g142 || g49 || g56 || g72 || g107
				|| g34 || g147_e1_fix_fix);
		g147_e1 = (!((g4 || g22 || g47 || g54 || g61 || g70 || g77 || g105
				|| g36 || g147_e1_fix)));
		g151_e2 = (!(g150));
	}
	PRE_g3 = g3;
	PRE_g6 = g6;
	PRE_g8 = g8;
	PRE_g11 = g11;
	PRE_g21 = g21;
	PRE_g24 = g24;
	PRE_g28 = g28;
	PRE_g33 = g33;
	PRE_g35 = g35;
	PRE_g46 = g46;
	PRE_g48 = g48;
	PRE_g53 = g53;
	PRE_g55 = g55;
	PRE_g60 = g60;
	PRE_g63 = g63;
	PRE_g69 = g69;
	PRE_g71 = g71;
	PRE_g76 = g76;
	PRE_g79 = g79;
	PRE_g85 = g85;
	PRE_g93 = g93;
	PRE_g104 = g104;
	PRE_g106 = g106;
	PRE_g111 = g111;
	PRE_g114 = g114;
	PRE_g116 = g116;
	PRE_g125 = g125;
	PRE_g127 = g127;
	PRE_g132 = g132;
	PRE_g135 = g135;
	PRE_g141 = g141;
	PRE_g143 = g143;
	PRE_g149 = g149;
	_PRE_GO = _GO;
	return;
}
// Example timeout values in milliseconds
#define AVI_VALUE 300
#define AEI_VALUE 800
#define PVARP_VALUE 50
#define VRP_VALUE 150
#define LRI_VALUE 950
#define URI_VALUE 900

// LCD Codes to Clear Screen
#define ESC 27
#define CLEAR_LCD_STRING "[2J"

// LED CONFIGS
#define APACE_LED 0x8
#define VPACE_LED 0X4
#define ASENSE_LED 0X2
#define VSENSE_LED 0x1
#define LED_TIMEOUT 50

// Global Variables
int currentMode = 0;	// Current Mode (Buttons/UART)
int prevMode = 0;		// Previous Mode (To detect Mode Change)
int buttonValue = 1;	// Value used for Polling Buttons
char *buffer;			// Buffer for character Read/Write via UART

// SCCharts Timers
alt_alarm AVI_timer;
alt_alarm AEI_timer;
alt_alarm LRI_timer;
alt_alarm URI_timer;
alt_alarm PVARP_timer;
alt_alarm VRP_timer;

// Input Flags
// Set by Button and UART Input
// Set to SCCharts signals once per tick
int VSense_flag = 0;
int ASense_flag = 0;
// Timer_ex_flags:
// Set by Interrupts
// Set to SCCharts signals once per tick
int AVI_ex_flag = 0;
int AEI_ex_flag = 0;
int LRI_ex_flag = 0;
int URI_ex_flag = 0;
int PVARP_ex_flag = 0;
int VRP_ex_flag = 0;

// Tick counts
// Used for button cool-down timer, where extra inputs are ignored
int count1;
int count2;
// Ticks per second recorded here (Ticks per 10ms)
int tps;
// UART File description
int fd;

// UART Receive
// Reads buffer and sets signals
// Based on V or A char input
void UART_receiver() {
	read(fd, buffer, 1);
	if (*buffer == 'V') {
		VSense_flag = 1;
	} else if (*buffer == 'A') {
		ASense_flag = 1;
	}
	*buffer = 0;
	return;
}

// UART Send
// Reads Signals and writes to buffer
void UART_send() {
	if (VPace == 1) {
		*buffer = 'V';
		write(fd, buffer, 1);
	} else if (APace == 1) {
		*buffer = 'A';
		write(fd, buffer, 1);
	}
	return;
}

// Timer ISRS
// Timer_ex flags set here
// Written to SCCHarts Signals before tick
alt_u32 AVI_timer_ISR(void* context) {
	AVI_ex_flag = 1;
	return 0;
}

alt_u32 AEI_timer_ISR(void* context) {
	AEI_ex_flag = 1;
	return 0;
}

alt_u32 LRI_timer_ISR(void* context) {
	LRI_ex_flag = 1;
	return 0;
}

alt_u32 URI_timer_ISR(void* context) {
	URI_ex_flag = 1;
	return 0;
}

alt_u32 PVARP_timer_ISR(void* context) {
	PVARP_ex_flag = 1;
	return 0;
}

alt_u32 VRP_timer_ISR(void* context) {
	VRP_ex_flag = 1;
	return 0;
}

// Button Polling
// Polls Button inputs
// Sets ASense and VSense flags from Inputs
// Written to SCCHarts Signals before tick
void poll_buttons() {
	unsigned int buttonValue = 0;
	// Fetch button inputs
	buttonValue = IORD_ALTERA_AVALON_PIO_DATA(BUTTONS_BASE);
	VSense_flag = !(buttonValue & (1 << 0));
	ASense_flag = !(buttonValue & (1 << 1));
	return;
}

// LCD Update
// Opens LCD Port
// Writes to LCD based on Current Mode
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

// Switch Polling
// Gets Mode based on Switch State
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

// Timer Handler
// Starts and Stops Timers based on SCCHarts Signals
int timer_handler() {
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

// Lights Handler
// Sets lights based on SCCharts Signals
int setLights() {
	if (APace) {
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, APACE_LED);
	} else if (VPace) {
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, VPACE_LED);
	} else if (ASense) {
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, ASENSE_LED);
	} else if (VSense) {
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, VSENSE_LED);
	} else {
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 0);
	}
	return 0;
}

// Flags Handler
// Writes Flags to SCCHart Signals
int setFlags() {
	// Writes Button Flags only after 10 ms have based since last button press
	count2 = alt_nticks(); // Get Current Tick Count
	if (currentMode == 1) {
		if ((count2 / tps) + 1 > (count1 / tps) + 1) {
			// Check if 10ms has passed since last press
			// Update Tick counts
			count1 = alt_nticks();
			VSense = VSense_flag;
			ASense = ASense_flag;
		}
	} else {
		VSense = VSense_flag;
		ASense = ASense_flag;
	}

	// Timer_ex_flags:
	AVI_ex = AVI_ex_flag;
	AEI_ex = AEI_ex_flag;
	LRI_ex = LRI_ex_flag;
	URI_ex = URI_ex_flag;
	PVARP_ex = PVARP_ex_flag;
	VRP_ex = VRP_ex_flag;

	// Clear Flags After SCCHarts Signals Set
	VSense_flag = 0;
	ASense_flag = 0;
	AVI_ex_flag = 0;
	AEI_ex_flag = 0;
	LRI_ex_flag = 0;
	URI_ex_flag = 0;
	PVARP_ex_flag = 0;
	VRP_ex_flag = 0;
	return 0;
}

// Clear SCCharts Signals
// Signals remain high unless cleared
// Clear all signals after tick
int clearSignals() {
	VSense = 0;
	ASense = 0;
	AVI_ex = 0;
	AEI_ex = 0;
	LRI_ex = 0;
	URI_ex = 0;
	PVARP_ex = 0;
	VRP_ex = 0;
	return 0;
}

int main(void) {
	// Initialize Values
	// Get Initial Tick Count
	count1 = alt_nticks();
	// Ticks per 10 ms
	tps = alt_ticks_per_second() / 100;
	// Open UART Port (Non blocking)
	fd = open(UART_NAME, O_NONBLOCK | O_RDWR);
	// Start SCCHarts Logic
	reset();
	tick();
	while (1) {
		//Poll Switches for Mode Change
		switch_check();
		//Poll Buttons for Input Flags
		if (currentMode == 1) {
			poll_buttons();
		}
		// UART Receive for Mode 2
		if (currentMode == 2) {
			UART_receiver();
		}
		// Update Flags in the SCCharts code
		setFlags();
		// Poll timers in SCCharts code
		timer_handler();
		// Set Lights
		setLights();
		// Tick!
		tick();
		// UART Send for Mode 2
		if (currentMode == 2) {
			UART_send();
		}
		// Clear Inputs
		clearSignals();
	}
	return 0;
}
