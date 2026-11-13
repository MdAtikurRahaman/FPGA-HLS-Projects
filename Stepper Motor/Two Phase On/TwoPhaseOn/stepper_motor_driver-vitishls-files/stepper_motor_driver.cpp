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
				motor_signal_tmp = 0b1100;
				break;
			case s1:
				if (motor_clk_rate == 1) {
					next_state = s2;
				} else {
					next_state = s1;
				}
				motor_signal_tmp = 0b1001;

				break;
			case s2:
				if (motor_clk_rate == 1) {
					next_state = s3;
				} else {
					next_state = s2;
				}
				motor_signal_tmp = 0b0011;

				break;
			case s3:
				if (motor_clk_rate == 1) {
					next_state = s0;
				} else {
					next_state = s3;
				}
				motor_signal_tmp = 0b0110;

				break;

			default:
				break;
		}
	state = next_state;
	motor_signal = motor_signal_tmp;
}
