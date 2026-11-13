/************************************************
Copyright (c) 2021, Mohammad Hosseinabady
	mohammad@highlevel-synthesis.com.
	https://highlevel-synthesis.com/

All rights reserved.
Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software
without specific prior written permission.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. // Copyright (c) 2020, Mohammad Hosseinabady.
************************************************/

#include "stepper_motor_clkpulse.h"



#define PULSE_PERIOD_100HZ 1000000
#define PULSE_PERIOD_50HZ  2000000
#define PULSE_PERIOD_25HZ  4000000

typedef enum{slow, medium, fast} speed_type;

typedef enum{zero, one} states_type;
void stepper_motor_clkpulse(bool speed_select, bool &clkpulse) {
#pragma HLS INTERFACE ap_none port=clkpulse
#pragma HLS INTERFACE ap_none port=speed_select
#pragma HLS INTERFACE ap_ctrl_none port=return


	static speed_type speed_state = slow;
	speed_type        next_speed_state = speed_state;

	switch (speed_state) {
	case slow:
		if (speed_select == 1) {
			next_speed_state = medium;
		} else {
			next_speed_state = slow;
		}
		break;
	case medium:
		if (speed_select == 1) {
			next_speed_state = fast;
		} else {
			next_speed_state = medium;
		}
		break;
	case fast:
		if (speed_select == 1) {
			next_speed_state = slow;
		} else {
			next_speed_state = fast;
		}
		break;
	default:
		break;
	}

	static states_type state    = zero;
	static unsigned int counter = PULSE_PERIOD_25HZ-1;


	states_type next_state;
	unsigned int          next_counter;

	bool clkpulse_local;

	switch(state) {
	case zero:
		if (counter == 0) {
			if (speed_state == slow) {
				next_counter           = PULSE_PERIOD_25HZ-1;
			} else if (speed_state == medium) {
				next_counter           = PULSE_PERIOD_50HZ-1;
			} else {
				next_counter           = PULSE_PERIOD_100HZ-1;
			}
			next_state             = one;
			clkpulse_local         = 1;
		} else {
			next_counter           = counter-1;
			next_state             = zero;
			clkpulse_local         = 0;
		}
		break;
	case one:
		next_counter           = counter-1;
		next_state             = zero;
		clkpulse_local         = 0;



		break;
	default:
		break;
	}

	speed_state = next_speed_state;
	state = next_state;
	counter = next_counter;
	clkpulse = clkpulse_local;
}

