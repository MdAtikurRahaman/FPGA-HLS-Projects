#include "arithmetic_sequences-tb.h"
#include <iostream>


int main() {
	int status = 0;

	ap_uint<4> first_item;
	ap_uint<4> common_difference;
	ap_uint<8> n;
	unsigned int nth_item;

	first_item = 3;
	common_difference = 4;
	n = 5;
	nth_item = 0;

	arithmetic_sequences(first_item, common_difference, n, nth_item);

	if (nth_item != first_item+common_difference*(n-1)) {
		status = -1;
		std::cout << "Error! Hardware nth_term = "
				  << nth_item << " != Software nth_term = "
				  << first_item+common_difference*(n-1)
				  << std::endl;
	}


	if (status == 0) {
		std::cout << "Test PASSED!" << std::endl;
	} else {
		std::cout << "Test FAILED" << std::endl;
	}


	return status;
}
