#include "data_consumer-tb.h"
#include <iostream>

int main() {

	int status = 0;

	const int n = 7;
	unsigned short int s;
	hls::stream<unsigned short int> data;

	for (int i = 0; i < n; i++) {
		data << i+1;
	}

	data_consumer(data, s, n);

	if (s != n*(n+1)/2) {
		std::cout << "Error " << " s = " << s << " != " << n*(n+1)/2 << std::endl;
		status = -1;
	} else {
		std::cout <<  " s = " << s <<  std::endl;
	}

	if (status == 0) {
		std::cout << " Test Passed! " << std::endl;
	} else {
		std::cout << " Test Failed! " << std::endl;
	}

	return status;
}
