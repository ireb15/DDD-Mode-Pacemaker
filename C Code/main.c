#include <system.h> // to use the symbolic names
#include <altera_avalon_pio_regs.h> // to use PIO functions
#include <stdio.h> //to use LCD
#include <alt_types.h> // alt_u32 is a kind of alt_types
#include <sys/alt_irq.h> // to register interrupts
#include <string.h>
#include <stdlib.h>
#include "sys/alt_alarm.h"
#include "mode1.h"

void reset(){
   _GO = 1;
   _PRE_GO = 0;
   PRE_g3 = 0;
   PRE_g6 = 0;
   PRE_g8 = 0;
   PRE_g11 = 0;
   PRE_g19 = 0;
   PRE_g22 = 0;
   PRE_g29 = 0;
   PRE_g31 = 0;
   PRE_g36 = 0;
   PRE_g38 = 0;
   PRE_g43 = 0;
   PRE_g46 = 0;
   PRE_g52 = 0;
   PRE_g54 = 0;
   PRE_g59 = 0;
   PRE_g61 = 0;
   PRE_g64 = 0;
   PRE_g68 = 0;
   PRE_g75 = 0;
   PRE_g77 = 0;
   PRE_g82 = 0;
   PRE_g85 = 0;
   PRE_g87 = 0;
   PRE_g96 = 0;
   PRE_g98 = 0;
   PRE_g103 = 0;
   PRE_g105 = 0;
   PRE_g108 = 0;
   PRE_g114 = 0;
   PRE_g116 = 0;
   PRE_g122 = 0;
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
      g123 =(PRE_g122);
      g121 = g0;
      g122 =(g123||g121);
      if(g122){
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
         PVARP_ex = 0;
         VRP_ex = 0;
         AEI_ex = 0;
         AVI_ex = 0;
         URI_ex = 0;
         LRI_ex = 0;
      }
      g69 =(PRE_g68);
      g69b = g69;
      _cg69 = URI_ex;
      g70 =(g69b&&_cg69);
      if(g70){
         VPace =(VPace||1);
      }
      g4 =(PRE_g3);
      _cg4 = VSense;
      g15 =(g4&&(!(_cg4)));
      _cg15 = VPace;
      g3 =(g2||(g15&&(!(_cg15))));
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
      g16 =(g15&&_cg15);
      if(g16){
         LRI_start =(LRI_start||1);
      }
      g6 =(g5||g12b||(g7b&&(!(_cg7)))||g16);
      g9 =(PRE_g8);
      _cg9 = VSense;
      g13 =(g9&&(!(_cg9)));
      _cg13 = LRI_ex;
      g8 =((g13&&(!(_cg13)))||(g7b&&_cg7));
      g10 =(g9&&_cg9);
      if(g10){
         LRI_stop =(LRI_stop||1);
      }
      g14 =(g13&&_cg13);
      if(g14){
         VPace =(VPace||1);
      }
      g11 =(g10||g14);
      g18 = g1;
      g23 =(PRE_g22);
      g23b = g23;
      _cg23 = URI_ex;
      g24 =(g23b&&_cg23);
      if(g24){
         URI_stop =(URI_stop||1);
      }
      g20 =(PRE_g19);
      _cg20 = VSense;
      g25 =(g20&&(!(_cg20)));
      _cg25 = VPace;
      g19 =(g18||g24||(g25&&(!(_cg25))));
      g21 =(g20&&_cg20);
      if(g21){
         URI_start =(URI_start||1);
      }
      g26 =(g25&&_cg25);
      if(g26){
         URI_start =(URI_start||1);
      }
      g22 =(g21||g26||(g23b&&(!(_cg23))));
      g28 = g1;
      g32 =(PRE_g31);
      g32b = g32;
      _cg32 = LRI_stop;
      g33 =(g32b&&(!(_cg32)));
      _cg33 = LRI_ex;
      g30 =(PRE_g29);
      g30b = g30;
      _cg30 = LRI_start;
      g29 =((g32b&&_cg32)||(g33&&_cg33)||(g30b&&(!(_cg30)))||g28);
      g31 =((g30b&&_cg30)||(g33&&(!(_cg33))));
      g35 = g1;
      g39 =(PRE_g38);
      g39b = g39;
      _cg39 = URI_stop;
      g40 =(g39b&&(!(_cg39)));
      _cg40 = URI_ex;
      g37 =(PRE_g36);
      g37b = g37;
      _cg37 = URI_start;
      g36 =((g40&&_cg40)||g35||(g39b&&_cg39)||(g37b&&(!(_cg37))));
      g38 =((g37b&&_cg37)||(g40&&(!(_cg40))));
      g42 = g1;
      g47 =(PRE_g46);
      g47b = g47;
      _cg47 = VRP_ex;
      g44 =(PRE_g43);
      _cg44 = VSense;
      g49 =(g44&&(!(_cg44)));
      _cg49 = VPace;
      g43 =(g42||(g47b&&_cg47)||(g49&&(!(_cg49))));
      g45 =((g44&&_cg44)||(g49&&_cg49));
      if(g45){
         VRP_start =(VRP_start||1);
      }
      g48 =(g47b&&(!(_cg47)));
      _cg48 = VSense;
      g46 =(g45||(g48&&_cg48)||(g48&&_cg48));
      g51 = g1;
      g55 =(PRE_g54);
      g55b = g55;
      _cg55 = VRP_ex;
      g53 =(PRE_g52);
      g53b = g53;
      _cg53 = VRP_start;
      g56 =(g55b&&(!(_cg55)));
      _cg56 = VRP_stop;
      g52 =((g55b&&_cg55)||(g53b&&(!(_cg53)))||g51||(g56&&_cg56));
      g54 =((g53b&&_cg53)||(g56&&(!(_cg56))));
      g58 = g1;
      g65 =(PRE_g64);
      _cg65 = VSense;
      g66 =(g65&&_cg65);
      if(g66){
         AVI_stop =(AVI_stop||1);
      }
      g60 =(PRE_g59);
      g60b = g60;
      _cg60 = PVARP_ex;
      g59 =(g70||g66||(g60b&&(!(_cg60)))||g58);
      g88 =(PRE_g87);
      _cg88 = ASense;
      g90 =(g88&&(!(_cg88)));
      _cg90 = AEI_ex;
      g91 =(g90&&_cg90);
      if(g91){
         APace =(APace||1);
      }
      g62 =(PRE_g61);
      _cg62 = ASense;
      g71 =(g62&&(!(_cg62)));
      _cg71 = APace;
      g61 =((g60b&&_cg60)||(g71&&(!(_cg71))));
      g63 =(g62&&_cg62);
      if(g63){
         AVI_start =(AVI_start||1);
      }
      g67 =(g65&&(!(_cg65)));
      _cg67 = AVI_ex;
      g72 =(g71&&_cg71);
      if(g72){
         AVI_start =(AVI_start||1);
      }
      g64 =(g63||(g67&&(!(_cg67)))||g72);
      g68 =((g67&&_cg67)||(g69b&&(!(_cg69))));
      g74 = g1;
      g78 =(PRE_g77);
      g78b = g78;
      _cg78 = AVI_ex;
      g76 =(PRE_g75);
      g76b = g76;
      _cg76 = AVI_start;
      g79 =(g78b&&(!(_cg78)));
      _cg79 = AVI_stop;
      g75 =((g78b&&_cg78)||(g76b&&(!(_cg76)))||g74||(g79&&_cg79));
      g77 =((g79&&(!(_cg79)))||(g76b&&_cg76));
      g81 = g1;
      g83 =(PRE_g82);
      _cg83 = VSense;
      g92 =(g83&&(!(_cg83)));
      _cg92 = VPace;
      g89 =(g88&&_cg88);
      if(g89){
         AEI_stop =(AEI_stop||1);
      }
      g82 =(g91||g81||(g92&&(!(_cg92)))||g89);
      g84 =(g83&&_cg83);
      if(g84){
         AEI_start =(AEI_start||1);
      }
      g86 =(PRE_g85);
      g86b = g86;
      _cg86 = PVARP_ex;
      g93 =(g92&&_cg92);
      if(g93){
         AEI_start =(AEI_start||1);
      }
      g85 =((g86b&&(!(_cg86)))||g93||g84);
      g87 =((g86b&&_cg86)||(g90&&(!(_cg90))));
      g95 = g1;
      g97 =(PRE_g96);
      g97b = g97;
      _cg97 = AEI_start;
      g99 =(PRE_g98);
      g99b = g99;
      _cg99 = AEI_ex;
      g100 =(g99b&&(!(_cg99)));
      _cg100 = AEI_stop;
      g96 =(g95||(g97b&&(!(_cg97)))||(g100&&_cg100)||(g99b&&_cg99));
      g98 =((g97b&&_cg97)||(g100&&(!(_cg100))));
      g102 = g1;
      g104 =(PRE_g103);
      g104b = g104;
      _cg104 = VRP_ex;
      g109 =(PRE_g108);
      g109b = g109;
      _cg109 = PVARP_ex;
      g103 =((g104b&&(!(_cg104)))||g102||(g109b&&_cg109));
      g106 =(PRE_g105);
      _cg106 = VSense;
      g110 =(g106&&(!(_cg106)));
      _cg110 = VPace;
      g105 =((g104b&&_cg104)||(g110&&(!(_cg110))));
      g107 =(g106&&_cg106);
      if(g107){
         PVARP_start =(PVARP_start||1);
      }
      g111 =(g110&&_cg110);
      if(g111){
         PVARP_start =(PVARP_start||1);
      }
      g108 =(g107||(g109b&&(!(_cg109)))||g111);
      g113 = g1;
      g115 =(PRE_g114);
      g115b = g115;
      _cg115 = PVARP_start;
      g117 =(PRE_g116);
      g117b = g117;
      _cg117 = PVARP_ex;
      g118 =(g117b&&(!(_cg117)));
      _cg118 = PVARP_stop;
      g114 =((g115b&&(!(_cg115)))||g113||(g117b&&_cg117)||(g118&&_cg118));
      g116 =((g115b&&_cg115)||(g118&&(!(_cg118))));
      g17_e1 =(!((g4||g7||g9||g12)));
      g27_e2 =(!((g20||g23)));
      g34_e3 =(!((g30||g32)));
      g41_e4 =(!((g37||g39)));
      g50_e5 =(!((g44||g47)));
      g57_e6 =(!((g53||g55)));
      g73_e7 =(!((g60||g62||g65||g69)));
      g80_e8 =(!((g76||g78)));
      g94_e9 =(!((g83||g86||g88)));
      g101_e10 =(!((g97||g99)));
      g112_e11 =(!((g104||g106||g109)));
      g119_e12 =(!((g115||g117)));
      g120_fix0 =((g17_e1||g17)&&(g27_e2||g27)&&(g34_e3||g34)&&(g41_e4||g41));
      g120_fix1 =(g120_fix0&&(g50_e5||g50)&&(g57_e6||g57)&&(g73_e7||g73));
      g120_fix2 =(g17||g27||g34||g41);
      g120_fix3 =(g120_fix2||g50||g57||g73);
      g120_e1_fix_fix =(g78||g99||g106||g117||g7||g23||g47||g86||g9||g65||g88||g109);
      g120_e1_fix =(g83||g97||g104||g115||g32||g39||g55||g62||g12||g120_e1_fix_fix);
      g120_e1 =(!((g4||g20||g30||g37||g44||g53||g60||g76||g69||g120_e1_fix)));
      g124_e2 =(!(g123));
   }
   PRE_g3 = g3;
   PRE_g6 = g6;
   PRE_g8 = g8;
   PRE_g11 = g11;
   PRE_g19 = g19;
   PRE_g22 = g22;
   PRE_g29 = g29;
   PRE_g31 = g31;
   PRE_g36 = g36;
   PRE_g38 = g38;
   PRE_g43 = g43;
   PRE_g46 = g46;
   PRE_g52 = g52;
   PRE_g54 = g54;
   PRE_g59 = g59;
   PRE_g61 = g61;
   PRE_g64 = g64;
   PRE_g68 = g68;
   PRE_g75 = g75;
   PRE_g77 = g77;
   PRE_g82 = g82;
   PRE_g85 = g85;
   PRE_g87 = g87;
   PRE_g96 = g96;
   PRE_g98 = g98;
   PRE_g103 = g103;
   PRE_g105 = g105;
   PRE_g108 = g108;
   PRE_g114 = g114;
   PRE_g116 = g116;
   PRE_g122 = g122;
   _PRE_GO = _GO;
   return;
}

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
int LED_timer_flag = 0;
int VSense_flag = 0;
int ASense_flag = 0;

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

void buttons_isr(void* context, alt_u32 id) {
	unsigned int temp = IORD_ALTERA_AVALON_PIO_EDGE_CAP(BUTTONS_BASE);
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(BUTTONS_BASE, 0);
	if (temp == 1) {
		VSense = 1;
	} else if (temp == 2) {
		ASense = 1;
	} else {
		VSense = 0;
		ASense = 0;
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
	}
	else if (VPace) {
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, VPACE_LED);
		printf("VPace\n");
	}
	else if (ASense) {
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, ASENSE_LED);
		printf("ASense\n");
		ASense = 0;
	}
	else if (VSense) {
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, VSENSE_LED);
		printf("VSense\n");
		VSense = 0;
	}
	else {
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
	init_buttons_pio();
	reset();
	while (1) {
		switch_check();
		//poll_buttons();
		//Poll timers in SCCharts code
		timer_handler();
		//Set Lights
		setLights();
		// Update VSense and ASense in the SCCharts code
		/*VSense = VSense_flag;
		if (VSense = 1) {
			printf("VSense\n");
		}
		ASense = ASense_flag;
		if (ASense = 1) {
			printf("ASense\n");
		}*/
		tick();
	}
	return 0;
}
