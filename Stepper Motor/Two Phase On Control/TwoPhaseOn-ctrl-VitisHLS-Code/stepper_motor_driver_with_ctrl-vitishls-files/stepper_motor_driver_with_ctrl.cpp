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
#include "stepper_motor_driver_with_ctrl.h"



typedef enum {s0, s1, s2, s3} stepper_motor_state;

void stepper_motor_driver_with_ctrl ( ap_uint<16> steps, bool load, bool motor_clk_rate, ap_uint<4> &motor_signal) {
#pragma HLS PIPELINE

#pragma HLS INTERFACE ap_none port=motor_signal
#pragma HLS INTERFACE ap_none port=steps
#pragma HLS INTERFACE ap_none port=load
#pragma HLS INTERFACE ap_none port=motor_clk_rate
#pragma HLS INTERFACE ap_ctrl_none port=return

	static stepper_motor_state state=s0;
	static unsigned int steps_counter=0;

	stepper_motor_state next_state=state;
	unsigned int next_steps_counter=steps_counter;
	ap_uint<4> motor_signal_tmp;


	if (load == 1) {
		next_steps_counter = steps;
	}

	//------------------------------------------------------------------
	switch (state) {
		case s0:
			if (motor_clk_rate == 1 && steps_counter != 0) {
				next_state = s1;
				next_steps_counter = steps_counter - 1;
			} else {
				next_state = s0;
			}
			motor_signal_tmp = 0b1100;
			break;
			case s1:
				if (motor_clk_rate == 1 && steps_counter != 0) {
					next_state = s2;
					next_steps_counter = steps_counter - 1;
				} else {
					next_state = s1;
				}
				motor_signal_tmp = 0b0110;

				break;
			case s2:
				if (motor_clk_rate == 1 && steps_counter != 0) {
					next_state = s3;
					next_steps_counter = steps_counter - 1;
				} else {
					next_state = s2;
				}
				motor_signal_tmp = 0b0011;

				break;
			case s3:
				if (motor_clk_rate == 1 && steps_counter != 0) {
					next_state = s0;
					next_steps_counter = steps_counter - 1;
				} else {
					next_state = s3;
				}
				motor_signal_tmp = 0b1001;

				break;


			default:
				break;
		}
	state = next_state;
	steps_counter = next_steps_counter;
	motor_signal = motor_signal_tmp;
}
