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
#include "stepper_motor_driver.h"



typedef enum {s0, s1, s2, s3} stepper_motor_state;

void stepper_motor_driver ( bool motor_clk_rate, ap_uint<4> &motor_signal) {
#pragma HLS INTERFACE ap_none port=motor_signal
#pragma HLS INTERFACE ap_none port=motor_clk_rate
#pragma HLS INTERFACE ap_ctrl_none port=return

	static stepper_motor_state state=s0;

	stepper_motor_state next_state=state;
	ap_uint<4> motor_signal_tmp;

	switch (state) {
			case s0:
				if (motor_clk_rate == 1) {
					next_state = s1;
				} else {
					next_state = s0;
				}
				motor_signal_tmp = 0b1000;
				break;
			case s1:
				if (motor_clk_rate == 1) {
					next_state = s2;
				} else {
					next_state = s1;
				}
				motor_signal_tmp = 0b0100;

				break;
			case s2:
				if (motor_clk_rate == 1) {
					next_state = s3;
				} else {
					next_state = s2;
				}
				motor_signal_tmp = 0b0010;

				break;
			case s3:
				if (motor_clk_rate == 1) {
					next_state = s0;
				} else {
					next_state = s3;
				}
				motor_signal_tmp = 0b0001;

				break;


			default:
				break;
		}
	state = next_state;
	motor_signal = motor_signal_tmp;
}
