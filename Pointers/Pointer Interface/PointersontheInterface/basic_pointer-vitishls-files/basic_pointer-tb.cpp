#include "basic_pointer-tb.h"
#include <iostream>

int main() {
	int status = 0;
	ap_uint<16> d;
	ap_uint<16> d_in;

	d_in=d = 2;
	basic_pointer(&d);

	std::cout << " d_in = " << d_in << " d_out = " << d << std::endl;

	d_in=d = 23;
	basic_pointer(&d);

	std::cout << " d_in = " << d_in << " d_out = " << d << std::endl;


	return status;

}

