#ifndef MODE1_H_ 
#define MODE1_H_ 

// Functions
void reset(); 
void tick(); 

// Inputs
extern char VSense; 
extern char ASense;

// Timer Signals
extern char AVI_ex;
extern char AVI_start;
extern char AVI_stop;
extern char VRP_ex;
extern char VRP_start;
extern char VRP_stop;
extern char LRI_ex;
extern char LRI_start;
extern char LRI_stop;
extern char VRP_ex;
extern char VRP_start;
extern char VRP_stop;
extern char PVARP_ex;
extern char PVARP_start;
extern char PVARP_stop;
extern char AEI_ex;
extern char AEI_start;
extern char AEI_stop;
extern char URI_ex;
extern char URI_start;
extern char URI_stop;



// Outputs
extern char VPace;
extern char APace; 

#endif/* MODE1_H_ */
