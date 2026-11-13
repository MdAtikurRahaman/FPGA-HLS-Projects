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



typedef enum {clockwise, anticlockwise} stepper_motor_direction;

typedef enum {s0, s1, s2, s3, s4, s5, s6, s7} stepper_motor_state;

void stepper_motor_driver ( bool direction, bool motor_clk_rate, ap_uint<4> &motor_signal) {
#pragma HLS INTERFACE ap_none port=direction
#pragma HLS INTERFACE ap_none port=motor_signal
#pragma HLS INTERFACE ap_none port=motor_clk_rate
#pragma HLS INTERFACE ap_ctrl_none port=return

	static stepper_motor_direction direction_state = clockwise;
	stepper_motor_direction next_direction_state = direction_state;

	static stepper_motor_state state=s0;

	switch (direction_state) {
	case clockwise:
		if (direction == 1)
			next_direction_state = anticlockwise;
		else
			next_direction_state = clockwise;
		break;
	case anticlockwise:
		if (direction == 1)
			next_direction_state = clockwise;
		else
			next_direction_state = anticlockwise;
		break;
	default:
		break;

	}
	stepper_motor_state next_state=state;
	ap_uint<4> motor_signal_tmp;

	switch (state) {
		case s0:
			if (motor_clk_rate == 1) {
				if (direction_state == clockwise)
					next_state = s1;
				else
					next_state = s7;
			} else {
				next_state = s0;
			}
			motor_signal_tmp = 0b1000;
			break;
		case s1:
			if (motor_clk_rate == 1) {
				if (direction_state == clockwise)
					next_state = s2;
				else
					next_state = s0;
			} else {
				next_state = s1;
			}
			motor_signal_tmp = 0b1001;

			break;
		case s2:
			if (motor_clk_rate == 1) {
				if (direction_state == clockwise)
					next_state = s3;
				else
					next_state = s1;
			} else {
				next_state = s2;
			}
			motor_signal_tmp = 0b0001;

			break;
		case s3:
			if (motor_clk_rate == 1) {
				if (direction_state == clockwise)
					next_state = s4;
				else
					next_state = s2;
			} else {
				next_state = s3;
			}
			motor_signal_tmp = 0b0011;

			break;
		case s4:
			if (motor_clk_rate == 1) {
				if (direction_state == clockwise)
					next_state = s5;
				else
					next_state = s3;
			} else {
				next_state = s4;
			}
			motor_signal_tmp = 0b0010;

			break;
		case s5:
			if (motor_clk_rate == 1) {
				if (direction_state == clockwise)
					next_state = s6;
				else
					next_state = s4;
			} else {
				next_state = s5;
			}
			motor_signal_tmp = 0b0110;

			break;
		case s6:
			if (motor_clk_rate == 1) {
				if (direction_state == clockwise)
					next_state = s7;
				else
					next_state = s5;
			} else {
				next_state = s6;
			}
			motor_signal_tmp = 0b0100;

			break;
		case s7:
			if (motor_clk_rate == 1) {
				if (direction_state == clockwise)
					next_state = s0;
				else
					next_state = s6;
			} else {
				next_state = s7;
			}
			motor_signal_tmp = 0b1100;
			break;

		default:
			break;
	}

	direction_state = next_direction_state;
	state = next_state;
	motor_signal = motor_signal_tmp;
}
