#include "baud_rate_generator.h"


//9600 buad rate --> BAUD_RATE_NUMBER = (1s/9600)/10ns = (1000000000/9600)/10 = 10416
#define BAUD_RATE_NUMBER 10416

//for simulation
//#define BAUD_RATE_NUMBER 20

typedef enum{zero, one} baud_rate_states_type;
void baud_rate_generator(bool &baud_rate_signal) {
#pragma HLS INTERFACE ap_none port=baud_rate_signal
#pragma HLS INTERFACE ap_ctrl_none port=return


	static baud_rate_states_type state = zero;
	static unsigned int counter = BAUD_RATE_NUMBER-1;


	baud_rate_states_type next_state;
	unsigned int          next_counter;

	bool baud_rate_signal_local;

	switch(state) {
	case zero:
		if (counter == 1) {
			next_counter           = counter-1;
			next_state             = one;
		} else {
			next_counter           = counter-1;
			next_state             = zero;
		}
		baud_rate_signal_local = 0;
		break;
	case one:
		next_counter           = BAUD_RATE_NUMBER-1;
		next_state             = zero;
		baud_rate_signal_local = 1;

		break;
	default:
		break;
	}

	state = next_state;
	counter = next_counter;
	baud_rate_signal = baud_rate_signal_local;
}

