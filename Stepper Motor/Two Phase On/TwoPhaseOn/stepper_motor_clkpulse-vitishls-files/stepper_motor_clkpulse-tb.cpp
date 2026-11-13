#include "stepper_motor_clkpulse-tb.h"
#include <iostream>


int main() {

	int status = 0;

	bool clkpulse_local;

	for (int i = 0; i < 100; i++) {
		stepper_motor_clkpulse(clkpulse_local);
		std::cout << clkpulse_local ;
	}

	std::cout <<  std::endl;
	std::cout <<  std::endl;
	std::cout <<  std::endl;

	return status;
}


