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

void reset(){
   _GO = 1;
   _PRE_GO = 0;
   PRE_g3 = 0;
   PRE_g6 = 0;
   PRE_g8 = 0;
   PRE_g11 = 0;
   PRE_g17 = 0;
   PRE_g20 = 0;
   PRE_g25 = 0;
   PRE_g27 = 0;
   PRE_g32 = 0;
   PRE_g34 = 0;
   PRE_g39 = 0;
   PRE_g42 = 0;
   PRE_g48 = 0;
   PRE_g50 = 0;
   PRE_g55 = 0;
   PRE_g58 = 0;
   PRE_g62 = 0;
   PRE_g67 = 0;
   PRE_g69 = 0;
   PRE_g74 = 0;
   PRE_g77 = 0;
   PRE_g80 = 0;
   PRE_g86 = 0;
   PRE_g88 = 0;
   PRE_g93 = 0;
   PRE_g96 = 0;
   PRE_g102 = 0;
   PRE_g104 = 0;
   PRE_g110 = 0;
   return;
}
void tick(){
   if(_PRE_GO == 1){
      _GO = 0;
   }
   {
      g0 = _GO;
      g1 = g0;
      g2 = g1;
      g4 =(PRE_g3);
      _cg4 = VSense;
      g3 =((g4&&(!(_cg4)))||g2);
      g111 =(PRE_g110);
      g109 = g0;
      g110 =(g111||g109);
      if(g110){
         VPace = 0;
         APace = 0;
         LRI_start = 0;
         LRI_ex = 0;
         LRI_stop = 0;
         URI_start = 0;
         URI_ex = 0;
         URI_stop = 0;
         VRP_start = 0;
         VRP_stop = 0;
         VRP_ex = 0;
         AVI_start = 0;
         AVI_stop = 0;
         AVI_ex = 0;
         AEI_start = 0;
         AEI_stop = 0;
         AEI_ex = 0;
         PVARP_start = 0;
         PVARP_stop = 0;
         PVARP_ex = 0;
      }
      g5 =(g4&&_cg4);
      if(g5){
         LRI_start =(LRI_start||1);
      }
      g12 =(PRE_g11);
      g12b = g12;
      if(g12b){
         LRI_start =(LRI_start||1);
      }
      g7 =(PRE_g6);
      g7b = g7;
      _cg7 = VRP_ex;
      g6 =(g5||g12b||(g7b&&(!(_cg7))));
      g9 =(PRE_g8);
      _cg9 = VSense;
      g13 =(g9&&(!(_cg9)));
      _cg13 = LRI_ex;
      g8 =((g7b&&_cg7)||(g13&&(!(_cg13))));
      g10 =(g9&&_cg9);
      if(g10){
         LRI_stop =(LRI_stop||1);
      }
      g14 =(g13&&_cg13);
      if(g14){
         VPace =(VPace||1);
      }
      g11 =(g14||g10);
      g16 = g1;
      g18 =(PRE_g17);
      _cg18 = VSense;
      g21 =(PRE_g20);
      g21b = g21;
      _cg21 = URI_ex;
      g22 =(g21b&&_cg21);
      if(g22){
         URI_stop =(URI_stop||1);
      }
      g17 =((g18&&(!(_cg18)))||g16||g22);
      g19 =(g18&&_cg18);
      if(g19){
         URI_start =(URI_start||1);
      }
      g20 =((g21b&&(!(_cg21)))||g19);
      g24 = g1;
      g28 =(PRE_g27);
      g28b = g28;
      _cg28 = LRI_stop;
      g29 =(g28b&&(!(_cg28)));
      _cg29 = LRI_ex;
      g26 =(PRE_g25);
      g26b = g26;
      _cg26 = LRI_start;
      g25 =((g29&&_cg29)||(g26b&&(!(_cg26)))||(g28b&&_cg28)||g24);
      g27 =((g29&&(!(_cg29)))||(g26b&&_cg26));
      g31 = g1;
      g35 =(PRE_g34);
      g35b = g35;
      _cg35 = URI_stop;
      g36 =(g35b&&(!(_cg35)));
      _cg36 = URI_ex;
      g33 =(PRE_g32);
      g33b = g33;
      _cg33 = URI_start;
      g32 =(g31||(g35b&&_cg35)||(g36&&_cg36)||(g33b&&(!(_cg33))));
      g34 =((g33b&&_cg33)||(g36&&(!(_cg36))));
      g38 = g1;
      g43 =(PRE_g42);
      g43b = g43;
      _cg43 = VRP_ex;
      g63 =(PRE_g62);
      g63b = g63;
      _cg63 = URI_ex;
      g64 =(g63b&&_cg63);
      if(g64){
         VPace =(VPace||1);
      }
      g40 =(PRE_g39);
      _cg40 = VSense;
      g45 =(g40&&(!(_cg40)));
      _cg45 = VPace;
      g39 =(g38||(g43b&&_cg43)||(g45&&(!(_cg45))));
      g41 =((g45&&_cg45)||(g40&&_cg40));
      if(g41){
         VRP_start =(VRP_start||1);
      }
      g44 =(g43b&&(!(_cg43)));
      _cg44 = VSense;
      g42 =(g41||(g44&&_cg44)||(g44&&_cg44));
      g47 = g1;
      g51 =(PRE_g50);
      g51b = g51;
      _cg51 = VRP_ex;
      g52 =(g51b&&(!(_cg51)));
      _cg52 = VRP_stop;
      g49 =(PRE_g48);
      g49b = g49;
      _cg49 = VRP_start;
      g48 =((g52&&_cg52)||g47||(g49b&&(!(_cg49)))||(g51b&&_cg51));
      g50 =((g52&&(!(_cg52)))||(g49b&&_cg49));
      g54 = g1;
      g56 =(PRE_g55);
      _cg56 = ASense;
      g59 =(PRE_g58);
      _cg59 = VSense;
      g60 =(g59&&_cg59);
      if(g60){
         AVI_stop =(AVI_stop||1);
      }
      g55 =((g56&&(!(_cg56)))||g54||g60||g64);
      g57 =(g56&&_cg56);
      if(g57){
         AVI_start =(AVI_start||1);
      }
      g61 =(g59&&(!(_cg59)));
      _cg61 = AVI_ex;
      g58 =(g57||(g61&&(!(_cg61))));
      g62 =((g63b&&(!(_cg63)))||(g61&&_cg61));
      g66 = g1;
      g68 =(PRE_g67);
      g68b = g68;
      _cg68 = AVI_start;
      g78 =(PRE_g77);
      _cg78 = ASense;
      g79 =(g78&&_cg78);
      if(g79){
         AVI_stop =(AVI_stop||1);
      }
      g70 =(PRE_g69);
      g70b = g70;
      _cg70 = AVI_ex;
      g71 =(g70b&&(!(_cg70)));
      _cg71 = AVI_stop;
      g67 =((g68b&&(!(_cg68)))||g66||(g71&&_cg71)||(g70b&&_cg70));
      g69 =((g68b&&_cg68)||(g71&&(!(_cg71))));
      g73 = g1;
      g81 =(PRE_g80);
      g81b = g81;
      _cg81 = PVARP_ex;
      g75 =(PRE_g74);
      _cg75 = VSense;
      g74 =((g81b&&_cg81)||(g75&&(!(_cg75)))||g73);
      g76 =(g75&&_cg75);
      if(g76){
         AEI_start =(AEI_start||1);
      }
      g82 =(g78&&(!(_cg78)));
      _cg82 = AEI_ex;
      g77 =((g82&&(!(_cg82)))||g76);
      g83 =(g82&&_cg82);
      if(g83){
         APace =(APace||1);
      }
      g80 =(g79||g83||(g81b&&(!(_cg81))));
      g85 = g1;
      g89 =(PRE_g88);
      g89b = g89;
      _cg89 = AEI_ex;
      g90 =(g89b&&(!(_cg89)));
      _cg90 = AEI_stop;
      g87 =(PRE_g86);
      g87b = g87;
      _cg87 = AEI_start;
      g86 =((g89b&&_cg89)||(g90&&_cg90)||(g87b&&(!(_cg87)))||g85);
      g88 =((g87b&&_cg87)||(g90&&(!(_cg90))));
      g92 = g1;
      g97 =(PRE_g96);
      g97b = g97;
      _cg97 = PVARP_ex;
      g94 =(PRE_g93);
      _cg94 = VSense;
      g98 =(g94&&(!(_cg94)));
      _cg98 = VPace;
      g93 =(g92||(g97b&&_cg97)||(g98&&(!(_cg98))));
      g95 =(g94&&_cg94);
      if(g95){
         PVARP_start =(PVARP_start||1);
      }
      g99 =(g98&&_cg98);
      if(g99){
         PVARP_start =(PVARP_start||1);
      }
      g96 =(g99||g95||(g97b&&(!(_cg97))));
      g101 = g1;
      g105 =(PRE_g104);
      g105b = g105;
      _cg105 = PVARP_ex;
      g106 =(g105b&&(!(_cg105)));
      _cg106 = PVARP_stop;
      g103 =(PRE_g102);
      g103b = g103;
      _cg103 = PVARP_start;
      g102 =((g106&&_cg106)||g101||(g103b&&(!(_cg103)))||(g105b&&_cg105));
      g104 =((g103b&&_cg103)||(g106&&(!(_cg106))));
      g15_e1 =(!((g4||g7||g9||g12)));
      g23_e2 =(!((g18||g21)));
      g30_e3 =(!((g26||g28)));
      g37_e4 =(!((g33||g35)));
      g46_e5 =(!((g40||g43)));
      g53_e6 =(!((g49||g51)));
      g65_e7 =(!((g56||g59||g63)));
      g72_e8 =(!((g68||g70)));
      g84_e9 =(!((g75||g78||g81)));
      g91_e10 =(!((g87||g89)));
      g100_e11 =(!((g94||g97)));
      g107_e12 =(!((g103||g105)));
      g108_fix0 =((g15_e1||g15)&&(g23_e2||g23)&&(g30_e3||g30)&&(g37_e4||g37));
      g108_fix1 =(g108_fix0&&(g46_e5||g46)&&(g53_e6||g53)&&(g65_e7||g65));
      g108_fix2 =(g15||g23||g30||g37);
      g108_fix3 =(g108_fix2||g46||g53||g65);
      g108_e1_fix_fix =(g89||g105||g7||g21||g43||g59||g78||g97||g9||g63);
      g108_e1_fix =(g75||g87||g94||g103||g28||g35||g51||g70||g81||g108_e1_fix_fix);
      g108_e1 =(!((g4||g18||g26||g33||g40||g49||g56||g68||g12||g108_e1_fix)));
      g112_e2 =(!(g111));
   }
   PRE_g3 = g3;
   PRE_g6 = g6;
   PRE_g8 = g8;
   PRE_g11 = g11;
   PRE_g17 = g17;
   PRE_g20 = g20;
   PRE_g25 = g25;
   PRE_g27 = g27;
   PRE_g32 = g32;
   PRE_g34 = g34;
   PRE_g39 = g39;
   PRE_g42 = g42;
   PRE_g48 = g48;
   PRE_g50 = g50;
   PRE_g55 = g55;
   PRE_g58 = g58;
   PRE_g62 = g62;
   PRE_g67 = g67;
   PRE_g69 = g69;
   PRE_g74 = g74;
   PRE_g77 = g77;
   PRE_g80 = g80;
   PRE_g86 = g86;
   PRE_g88 = g88;
   PRE_g93 = g93;
   PRE_g96 = g96;
   PRE_g102 = g102;
   PRE_g104 = g104;
   PRE_g110 = g110;
   _PRE_GO = _GO;
   return;
}


// Example timeout values in milliseconds
#define AVI_VALUE 3000
#define AEI_VALUE 8000
#define PVARP_VALUE 500
#define VRP_VALUE 1500
#define LRI_VALUE 9500
#define URI_VALUE 9000

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
int LED_timer_flag = 0;

//Timers
alt_alarm AVI_timer;
alt_alarm AEI_timer;
alt_alarm LRI_timer;
alt_alarm URI_timer;
alt_alarm PVARP_timer;
alt_alarm VRP_timer;
alt_alarm LED_timer;

//Input Flags
//So Inputs won't change mid-tick
int VSense_flag = 0;
int ASense_flag = 0;

alt_u32 LED_timer_ISR(void* context) {
	IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 0);
	LED_timer_flag = 0;
	return 0;
}

alt_u32 AVI_timer_ISR(void* context) {
	AVI_ex = 1;
	printf("AVI expired\n");
	return 0;
}

alt_u32 AEI_timer_ISR(void* context) {
	AEI_ex = 1;
	printf("AEI expired\n");
	return 0;
}

alt_u32 LRI_timer_ISR(void* context) {
	LRI_ex = 1;
	printf("LRI expired\n");
	return 0;
}

alt_u32 URI_timer_ISR(void* context) {
	URI_ex = 1;
	printf("URI expired\n");
	return 0;
}

alt_u32 PVARP_timer_ISR(void* context) {
	PVARP_ex = 1;
	printf("PVARP expired\n");
	return 0;
}

alt_u32 VRP_timer_ISR(void* context) {
	VRP_ex = 1;
	printf("VRP expired\n");
	return 0;
}

/*void buttons_isr(void* context, alt_u32 id) {
	unsigned int temp = IORD_ALTERA_AVALON_PIO_EDGE_CAP(BUTTONS_BASE);
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(BUTTONS_BASE, 0);
	if (temp == 1) {
		VSense_flag = 1;
	} else if (temp == 2) {
		ASense_flag = 1;
	}
	return;
}*/

void poll_buttons() {
	unsigned int buttonValue = 0;
	// Fetch button inputs
	buttonValue = IORD_ALTERA_AVALON_PIO_DATA(BUTTONS_BASE);
	VSense_flag = !(buttonValue & (1 << 0));
	ASense_flag = !(buttonValue & (1 << 1));
	return;
}

/*void init_buttons_pio() {
	void* context_to_be_passed = (void*) &buttonValue;
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(BUTTONS_BASE, 0);
	IOWR_ALTERA_AVALON_PIO_IRQ_MASK(BUTTONS_BASE, 0x7);
	alt_irq_register(BUTTONS_IRQ, context_to_be_passed, buttons_isr);
	return;
}*/

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
		//Start AVI timer interrupt
		alt_alarm_start(&AVI_timer, AVI_VALUE, AVI_timer_ISR, NULL);
		printf("AVI start ");

	}
	if (PVARP_start) {
		//Start PVARP timer interrupt
		alt_alarm_start(&PVARP_timer, PVARP_VALUE, PVARP_timer_ISR, NULL);
		printf("PVARP start ");
	}
	if (AEI_start) {
		//Start AEI timer interrupt
		alt_alarm_start(&AEI_timer, AEI_VALUE, AEI_timer_ISR, NULL);
		printf("AEI start ");
	}
	if (VRP_start) {
		//Start PVARP timer interrupt
		alt_alarm_start(&VRP_timer, VRP_VALUE, VRP_timer_ISR, NULL);
		printf("VRP start ");
	}
	if (LRI_start) {
		//Start LRI timer interrupt
		alt_alarm_start(&LRI_timer, LRI_VALUE, LRI_timer_ISR, NULL);
		printf("LRI start ");
	}
	if (URI_start) {
		//Start PVARP timer interrupt
		alt_alarm_start(&URI_timer, URI_VALUE, URI_timer_ISR, NULL);
		printf("URI start ");
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
	if (APace) {
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, APACE_LED);
		printf("APace\n");
	} else if (VPace) {
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, VPACE_LED);
		printf("VPace\n");
	} else if (ASense) {
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, ASENSE_LED);
		printf("ASense\n");
	} else if (VSense) {
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, VSENSE_LED);
		printf("VSense\n");
	} else {
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 0);
	}
	// Keep LEDs on for 50ms
	/*if (LED_timer_flag = 0) {
	 alt_alarm_start(&LED_timer, LED_TIMEOUT, LED_timer_ISR, NULL);
	 LED_timer_flag = 1;
	 }*/
	return 0;
}

int main(void) {
	//init_buttons_pio();
	reset();
	while (1) {
		//Poll Switches for Mode Change
		switch_check();
		//Poll Buttons for Input Flags
		poll_buttons();
		// Update VSense and ASense in the SCCharts code
		VSense = VSense_flag;
		ASense = ASense_flag;
		// Poll timers in SCCharts code
		timer_handler();
		// Set Lights
		setLights();
		tick();
		// Clear Inputs
		VSense = 0;
		ASense = 0;
		VSense_flag = 0;
		ASense_flag = 0;
		// Need to Clear flags but only if VSense and ASense were just raised

	}
	return 0;
}
