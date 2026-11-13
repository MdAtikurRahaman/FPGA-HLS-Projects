#include "producer_nonblocking-tb.h"
#include <iostream>

int main() {

	int status = 0;

	const int n = 32;
	short unsigned int data[n];
	hls::stream<unsigned short int> d;

	producer_nonblocking(d, n);

	for (int i = 0; i < n; i++) {
		data[i] = d.read();
	}


	for (int i = 0; i < n; i++) {
		if (data[i] != i+1) {
			std::cout << "Error at " << i << " data[i] = " << data[i] << " != " << i+1 << std::endl;
			status = -1;
			break;
		}
	}


	if (status == 0) {
		std::cout << " Test Passed! " << std::endl;
	} else {
		std::cout << " Test Failed! " << std::endl;
	}

	return status;
}
