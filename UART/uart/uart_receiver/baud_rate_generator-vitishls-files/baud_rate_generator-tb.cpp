#include "baud_rate_generator-tb.h"



int main() {

	int status = 0;

	bool baud_rate_signal;

	for (int i = 0; i < 50; i++) {
		baud_rate_generator(baud_rate_signal);
	}


	return status;
}


