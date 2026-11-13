#include "pointer_stream_good-tb.h"
#include <iostream>

int main() {

	int status = 0;

	unsigned short d_in[4]={2, 4, 6, 8};
	unsigned short d_out_hw[2] = {0, 0};
	unsigned short d_out_sw[2] = {0, 0};


	pointer_stream_good(d_out_hw, d_in);

	d_out_sw[0] = d_in[0] + d_in[1];
	d_out_sw[1] = d_in[0] + d_in[1] + d_in[2] + d_in[3];

	for (int i = 0; i < 2; i++) {
		if (d_out_hw[i]  != d_out_sw[i]) {
			status = -1;
			std::cout << "  d_out_hw[" << i << "] = " << d_out_hw[i]
					  << "  d_out_sw[" << i << "] = " << d_out_sw[i]
					  << std::endl;

			break;
		}
	}


	if (status == 0) {
		std::cout << "Test PASSED!" << std::endl;
	} else {
		std::cout << "Test FAILED!" << std::endl;
	}


	return status;
}
