#include "data_streaming_modules-tb.h"
#include <iostream>

void scaled_addition_sw(int *a, int *b, int *c, unsigned int n)
{
	for (unsigned int i = 0; i < n; i++)
		c[i] = 12*(a[i]+b[i]);
}


int main() {

	int status = 0;

	int *a;
	int *b;
	int *c_hw, *c_sw;
	unsigned int n;

	n = 256;
	a = new int[n];
	b = new int[n];
	c_hw = new int[n];
	c_sw = new int[n];

	for (int i = 0; i < n; i++) {
		a[i] = rand();
		b[i] = rand();
		c_hw[i] = rand();
		c_sw[i] = rand();
	}


	scaled_addition_sw(a, b, c_sw, n);
	data_streaming_modules(a, b, c_hw, n);


	for (int i = 0; i < n; i++) {
		if (c_hw[i] !=c_sw[i]) {
			std::cout << " Error at " << i << " c_hw = " << c_hw[i] << " != c_sw =" << c_sw[i] << std::endl;
			status = 1;
			break;
		}
	}

	if (status == 0) {
		std::cout << " Test PASSED! " << std::endl;
	} else {
		std::cout << " Test FAILED! " << std::endl;
	}


	return status;
}
