

#include "stepper_motor_clkpulse.h"



#define PULSE_PERIOD 1000000

typedef enum{zero, one} states_type;
void stepper_motor_clkpulse(bool &clkpulse) {
#pragma HLS INTERFACE ap_none port=clkpulse
#pragma HLS INTERFACE ap_ctrl_none port=return


	static states_type state = zero;
	static unsigned int counter = PULSE_PERIOD-1;


	states_type next_state;
	unsigned int          next_counter;

	bool clkpulse_local;

	switch(state) {
	case zero:
		if (counter == 0) {
			next_counter           = PULSE_PERIOD-1;
			next_state             = one;
			clkpulse_local = 1;
		} else {
			next_counter           = counter-1;
			next_state             = zero;
			clkpulse_local = 0;
		}
		break;
	case one:
		next_counter           = counter-1;
		next_state             = zero;
		clkpulse_local       = 0;



		break;
	default:
		break;
	}

	state = next_state;
	counter = next_counter;
	clkpulse = clkpulse_local;
}

