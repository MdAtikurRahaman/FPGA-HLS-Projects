#include "stepper_motor_driver-tb.h"
#include <iostream>
#include <bitset>




int main() {
	int status = 0;

	bool       motor_clk_rate;
	ap_uint<4> motor_signal;

	motor_clk_rate = 0;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 5; j++) {
			stepper_motor_driver ( motor_clk_rate, motor_signal);
			motor_clk_rate = 0;
			std::cout << "motor_signal = " << std::setfill ('0') << std::setw (4) << (std::bitset<4>)motor_signal << std::endl;
		}
		motor_clk_rate = 1;
	}




	return status;
}
