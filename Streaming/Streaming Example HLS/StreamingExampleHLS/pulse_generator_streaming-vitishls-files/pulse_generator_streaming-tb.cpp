#include "pulse_generator_streaming-tb.h"
#include <iostream>




int main() {

	int status = 0;

	bool pulse;

	std::cout << " pulse = " ;
	for (int i = 0; i < 5; i++) {
		 pulse_generator_streaming(0, &pulse);
		std::cout << " " << pulse ;
	}

	for (int i = 0; i < 5; i++) {
		pulse_generator_streaming(1, &pulse);
		std::cout << " " << pulse ;
	}

	for (int i = 0; i < 5; i++) {
		pulse_generator_streaming(0, &pulse);
		std::cout << " " << pulse ;
	}

	std::cout << std::endl ;
	return status;
}
