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
   PRE_g27 = 0;
   PRE_g29 = 0;
   PRE_g34 = 0;
   PRE_g36 = 0;
   PRE_g41 = 0;
   PRE_g44 = 0;
   PRE_g50 = 0;
   PRE_g52 = 0;
   PRE_g57 = 0;
   PRE_g60 = 0;
   PRE_g66 = 0;
   PRE_g74 = 0;
   PRE_g85 = 0;
   PRE_g87 = 0;
   PRE_g92 = 0;
   PRE_g95 = 0;
   PRE_g98 = 0;
   PRE_g106 = 0;
   PRE_g108 = 0;
   PRE_g113 = 0;
   PRE_g116 = 0;
   PRE_g122 = 0;
   PRE_g124 = 0;
   PRE_g130 = 0;
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
      g131 =(PRE_g130);
      g129 = g0;
      g130 =(g131||g129);
      if(g130){
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
      g5 =(g4&&_cg4);
      if(g5){
         LRI_start =(LRI_start||1);
      }
      g7 =(PRE_g6);
      _cg7 = VRP_ex;
      g12 =(PRE_g11);
      g12b = g12;
      if(g12b){
         LRI_start =(LRI_start||1);
      }
      g6 =((g7&&(!(_cg7)))||g5||g12b);
      g9 =(PRE_g8);
      _cg9 = VSense;
      g13 =(g9&&(!(_cg9)));
      _cg13 = LRI_ex;
      g8 =((g13&&(!(_cg13)))||(g7&&_cg7));
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
      g67 =(PRE_g66);
      _cg67 = URI_ex;
      g68 =(g67&&_cg67);
      if(g68){
         VPace =(VPace||1);
      }
      g75 =(PRE_g74);
      _cg75 = AVI_ex;
      g76 =(g75&&_cg75);
      if(g76){
         VPace =(VPace||1);
      }
      g18 =(PRE_g17);
      _cg18 = VSense;
      g23 =(g18&&(!(_cg18)));
      _cg23 = VPace;
      g21 =(PRE_g20);
      _cg21 = URI_ex;
      g22 =(g21&&_cg21);
      if(g22){
         URI_stop =(URI_stop||1);
      }
      g17 =((g23&&(!(_cg23)))||g22||g16);
      g19 =(g18&&_cg18);
      if(g19){
         URI_start =(URI_start||1);
      }
      g24 =(g23&&_cg23);
      if(g24){
         URI_start =(URI_start||1);
      }
      g20 =((g21&&(!(_cg21)))||g24||g19);
      g26 = g1;
      g28 =(PRE_g27);
      g28b = g28;
      _cg28 = LRI_start;
      g30 =(PRE_g29);
      g30b = g30;
      _cg30 = LRI_stop;
      g31 =(g30b&&(!(_cg30)));
      _cg31 = LRI_ex;
      g27 =((g28b&&(!(_cg28)))||g26||(g30b&&_cg30)||(g31&&_cg31));
      g29 =((g28b&&_cg28)||(g31&&(!(_cg31))));
      g33 = g1;
      g37 =(PRE_g36);
      g37b = g37;
      _cg37 = URI_stop;
      g38 =(g37b&&(!(_cg37)));
      _cg38 = URI_ex;
      g35 =(PRE_g34);
      g35b = g35;
      _cg35 = URI_start;
      g34 =(g33||(g38&&_cg38)||(g35b&&(!(_cg35)))||(g37b&&_cg37));
      g36 =((g35b&&_cg35)||(g38&&(!(_cg38))));
      g40 = g1;
      g45 =(PRE_g44);
      _cg45 = VRP_ex;
      g42 =(PRE_g41);
      g42b = g42;
      _cg42 = VPace;
      g46 =(g42b&&(!(_cg42)));
      _cg46 = VSense;
      g41 =((g45&&_cg45)||(g46&&(!(_cg46)))||g40);
      g43 =(g42b&&_cg42);
      if(g43){
         VRP_start =(VRP_start||1);
      }
      g47 =(g46&&_cg46);
      if(g47){
         VRP_start =(VRP_start||1);
      }
      g44 =(g43||(g45&&(!(_cg45)))||g47);
      g49 = g1;
      g53 =(PRE_g52);
      _cg53 = VRP_ex;
      g54 =(g53&&(!(_cg53)));
      _cg54 = VRP_stop;
      g51 =(PRE_g50);
      g51b = g51;
      _cg51 = VRP_start;
      g50 =((g53&&_cg53)||(g54&&_cg54)||g49||(g51b&&(!(_cg51))));
      g52 =((g51b&&_cg51)||(g54&&(!(_cg54))));
      g56 = g1;
      g61 =(PRE_g60);
      _cg61 = VSense;
      g63 =(g61&&(!(_cg61)));
      _cg63 = VPace;
      g64 =(g63&&_cg63);
      if(g64){
         AVI_stop =(AVI_stop||1);
      }
      g96 =(PRE_g95);
      _cg96 = ASense;
      g100 =(g96&&(!(_cg96)));
      _cg100 = AEI_ex;
      g101 =(g100&&_cg100);
      if(g101){
         APace =(APace||1);
      }
      g58 =(PRE_g57);
      _cg58 = ASense;
      g81 =(g58&&(!(_cg58)));
      _cg81 = APace;
      g77 =(g75&&(!(_cg75)));
      _cg77 = VSense;
      g78 =(g77&&_cg77);
      if(g78){
         AVI_stop =(AVI_stop||1);
      }
      g69 =(g67&&(!(_cg67)));
      _cg69 = VSense;
      g71 =(g69&&(!(_cg69)));
      _cg71 = VPace;
      g72 =(g71&&_cg71);
      if(g72){
         AVI_stop =(AVI_stop||1);
      }
      g62 =(g61&&_cg61);
      if(g62){
         AVI_stop =(AVI_stop||1);
      }
      g70 =(g69&&_cg69);
      if(g70){
         AVI_stop =(AVI_stop||1);
      }
      g79 =(g77&&(!(_cg77)));
      _cg79 = VPace;
      g80 =(g79&&_cg79);
      if(g80){
         AVI_stop =(AVI_stop||1);
      }
      g57 =(g64||(g81&&(!(_cg81)))||g76||g78||g68||g72||g56||g62||g70||g80);
      g59 =(g58&&_cg58);
      if(g59){
         AVI_start =(AVI_start||1);
      }
      g65 =(g63&&(!(_cg63)));
      _cg65 = AVI_ex;
      g73 =(g65&&(!(_cg65)));
      _cg73 = URI_ex;
      g82 =(g81&&_cg81);
      if(g82){
         AVI_start =(AVI_start||1);
      }
      g60 =(g59||(g73&&(!(_cg73)))||g82);
      g66 =((g71&&(!(_cg71)))||(g65&&_cg65));
      g74 =((g79&&(!(_cg79)))||(g73&&_cg73));
      g84 = g1;
      g86 =(PRE_g85);
      g86b = g86;
      _cg86 = AVI_start;
      g88 =(PRE_g87);
      _cg88 = AVI_ex;
      g89 =(g88&&(!(_cg88)));
      _cg89 = AVI_stop;
      g85 =(g84||(g86b&&(!(_cg86)))||(g89&&_cg89)||(g88&&_cg88));
      g87 =((g89&&(!(_cg89)))||(g86b&&_cg86));
      g91 = g1;
      g93 =(PRE_g92);
      _cg93 = VSense;
      g102 =(g93&&(!(_cg93)));
      _cg102 = VPace;
      g99 =(PRE_g98);
      _cg99 = PVARP_ex;
      g92 =((g102&&(!(_cg102)))||(g99&&_cg99)||g91);
      g94 =(g93&&_cg93);
      if(g94){
         AEI_start =(AEI_start||1);
      }
      g103 =(g102&&_cg102);
      if(g103){
         AEI_start =(AEI_start||1);
      }
      g95 =(g94||(g100&&(!(_cg100)))||g103);
      g97 =(g96&&_cg96);
      if(g97){
         AEI_stop =(AEI_stop||1);
      }
      g98 =(g97||(g99&&(!(_cg99)))||g101);
      g105 = g1;
      g109 =(PRE_g108);
      _cg109 = AEI_ex;
      g110 =(g109&&(!(_cg109)));
      _cg110 = AEI_stop;
      g107 =(PRE_g106);
      g107b = g107;
      _cg107 = AEI_start;
      g106 =(g105||(g110&&_cg110)||(g107b&&(!(_cg107)))||(g109&&_cg109));
      g108 =((g107b&&_cg107)||(g110&&(!(_cg110))));
      g112 = g1;
      g117 =(PRE_g116);
      _cg117 = PVARP_ex;
      g114 =(PRE_g113);
      _cg114 = VSense;
      g118 =(g114&&(!(_cg114)));
      _cg118 = VPace;
      g113 =((g117&&_cg117)||g112||(g118&&(!(_cg118))));
      g115 =(g114&&_cg114);
      if(g115){
         PVARP_start =(PVARP_start||1);
      }
      g119 =(g118&&_cg118);
      if(g119){
         PVARP_start =(PVARP_start||1);
      }
      g116 =(g119||g115||(g117&&(!(_cg117))));
      g121 = g1;
      g125 =(PRE_g124);
      _cg125 = PVARP_ex;
      g123 =(PRE_g122);
      g123b = g123;
      _cg123 = PVARP_start;
      g126 =(g125&&(!(_cg125)));
      _cg126 = PVARP_stop;
      g122 =(g121||(g125&&_cg125)||(g123b&&(!(_cg123)))||(g126&&_cg126));
      g124 =((g123b&&_cg123)||(g126&&(!(_cg126))));
      g15_e1 =(!((g4||g7||g9||g12)));
      g25_e2 =(!((g18||g21)));
      g32_e3 =(!((g28||g30)));
      g39_e4 =(!((g35||g37)));
      g48_e5 =(!((g42||g45)));
      g55_e6 =(!((g51||g53)));
      g83_e7 =(!((g58||g61||g67||g75)));
      g90_e8 =(!((g86||g88)));
      g104_e9 =(!((g93||g96||g99)));
      g111_e10 =(!((g107||g109)));
      g120_e11 =(!((g114||g117)));
      g127_e12 =(!((g123||g125)));
      g128_fix0 =((g15_e1||g15)&&(g25_e2||g25)&&(g32_e3||g32)&&(g39_e4||g39));
      g128_fix1 =(g128_fix0&&(g48_e5||g48)&&(g55_e6||g55)&&(g83_e7||g83));
      g128_fix2 =(g15||g25||g32||g39);
      g128_fix3 =(g128_fix2||g48||g55||g83);
      g128_e1_fix_fix =(g109||g125||g7||g21||g45||g61||g96||g117||g9||g99||g67);
      g128_e1_fix =(g93||g107||g114||g123||g30||g37||g53||g88||g12||g128_e1_fix_fix);
      g128_e1 =(!((g4||g18||g28||g35||g42||g51||g58||g86||g75||g128_e1_fix)));
      g132_e2 =(!(g131));
   }
   PRE_g3 = g3;
   PRE_g6 = g6;
   PRE_g8 = g8;
   PRE_g11 = g11;
   PRE_g17 = g17;
   PRE_g20 = g20;
   PRE_g27 = g27;
   PRE_g29 = g29;
   PRE_g34 = g34;
   PRE_g36 = g36;
   PRE_g41 = g41;
   PRE_g44 = g44;
   PRE_g50 = g50;
   PRE_g52 = g52;
   PRE_g57 = g57;
   PRE_g60 = g60;
   PRE_g66 = g66;
   PRE_g74 = g74;
   PRE_g85 = g85;
   PRE_g87 = g87;
   PRE_g92 = g92;
   PRE_g95 = g95;
   PRE_g98 = g98;
   PRE_g106 = g106;
   PRE_g108 = g108;
   PRE_g113 = g113;
   PRE_g116 = g116;
   PRE_g122 = g122;
   PRE_g124 = g124;
   PRE_g130 = g130;
   _PRE_GO = _GO;
   return;
}

// Example timeout values in milliseconds
#define AVI_VALUE 600
#define AEI_VALUE 1600
#define PVARP_VALUE 100
#define VRP_VALUE 300
#define LRI_VALUE 1900
#define URI_VALUE 1800

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
//Timer_ex_flag:
int AVI_ex_flag = 0;
int AEI_ex_flag = 0;
int LRI_ex_flag = 0;
int URI_ex_flag = 0;
int PVARP_ex_flag = 0;
int VRP_ex_flag = 0;

alt_u32 LED_timer_ISR(void* context) {
	IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 0);
	LED_timer_flag = 0;
	return 0;
}

alt_u32 AVI_timer_ISR(void* context) {
	AVI_ex_flag = 1;
	printf("AVI expired\n");
	return 0;
}

alt_u32 AEI_timer_ISR(void* context) {
	AEI_ex_flag = 1;
	printf("AEI expired\n");
	return 0;
}

alt_u32 LRI_timer_ISR(void* context) {
	LRI_ex_flag = 1;
	printf("LRI expired\n");
	return 0;
}

alt_u32 URI_timer_ISR(void* context) {
	URI_ex_flag = 1;
	printf("URI expired\n");
	return 0;
}

alt_u32 PVARP_timer_ISR(void* context) {
	PVARP_ex_flag = 1;
	printf("PVARP expired\n");
	return 0;
}

alt_u32 VRP_timer_ISR(void* context) {
	VRP_ex_flag = 1;
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
		printf("AVI start\n");

	}
	if (PVARP_start) {
		//Start PVARP timer interrupt
		alt_alarm_start(&PVARP_timer, PVARP_VALUE, PVARP_timer_ISR, NULL);
		printf("PVARP start\n");
	}
	if (AEI_start) {
		//Start AEI timer interrupt
		alt_alarm_start(&AEI_timer, AEI_VALUE, AEI_timer_ISR, NULL);
		printf("AEI start\n");
	}
	if (VRP_start) {
		//Start PVARP timer interrupt
		alt_alarm_start(&VRP_timer, VRP_VALUE, VRP_timer_ISR, NULL);
		printf("VRP start\n");
	}
	if (LRI_start) {
		//Start LRI timer interrupt
		alt_alarm_start(&LRI_timer, LRI_VALUE, LRI_timer_ISR, NULL);
		printf("LRI start\n");
	}
	if (URI_start) {
		//Start PVARP timer interrupt
		alt_alarm_start(&URI_timer, URI_VALUE, URI_timer_ISR, NULL);
		printf("URI start\n");
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
		printf("APace\n\n");
	} else if (VPace) {
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, VPACE_LED);
		printf("VPace\n\n");
	} else if (ASense) {
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, ASENSE_LED);
		printf("ASense\n\n");
	} else if (VSense) {
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, VSENSE_LED);
		printf("VSense\n\n");
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

int setFlags() {
	VSense = VSense_flag;
	ASense = ASense_flag;
	//Timer_ex_flag:
	AVI_ex = AVI_ex_flag;
	AEI_ex = AEI_ex_flag;
	LRI_ex = LRI_ex_flag;
	URI_ex = URI_ex_flag;
	PVARP_ex = PVARP_ex_flag;
	VRP_ex = VRP_ex_flag;
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
int clearFlags() {
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
	//init_buttons_pio();
	reset();
	while (1) {
		//Poll Switches for Mode Change
		switch_check();
		//Poll Buttons for Input Flags
		poll_buttons();
		// Update Flags in the SCCharts code
		setFlags();
		// Poll timers in SCCharts code
		timer_handler();
		// Set Lights
		setLights();
		// Tick!
		tick();
		// Clear Inputs
		clearFlags();
	}
	return 0;
}
