#ifndef MODE1_H_
#define MODE1_H_

// Functions
void reset();
void tick();

// Inputs
 char VSense;
 char ASense;
 char init_var;

// Timer Signals
 char AVI_ex;
 char AVI_start;
 char AVI_stop;
 char VRP_ex;
 char VRP_start;
 char VRP_stop;
 char LRI_ex;
 char LRI_start;
 char LRI_stop;
 char VRP_ex;
 char VRP_start;
 char VRP_stop;
 char PVARP_ex;
 char PVARP_start;
 char PVARP_stop;
 char AEI_ex;
 char AEI_start;
 char AEI_stop;
 char URI_ex;
 char URI_start;
 char URI_stop;



// Outputs
 char VPace;
 char APace;

#endif/* MODE1_H_ */
