#include <iostream>
#include "waveform_generator-tb.h"


int main() {

	int status = 0;
	bool x[4*N];

	waveform_generator(&x[0*N]);
	waveform_generator(&x[1*N]);
	waveform_generator(&x[2*N]);
	waveform_generator(&x[3*N]);

	std::cout << std::endl;
	for (int i = 0; i < 4*N; i++) {
		std::cout << x[i];
	}
	std::cout << std::endl;

	return status;
}
