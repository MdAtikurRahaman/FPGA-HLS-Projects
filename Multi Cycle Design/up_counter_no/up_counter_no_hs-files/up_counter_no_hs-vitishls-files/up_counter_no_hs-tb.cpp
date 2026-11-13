#include "up_counter_no_hs-tb.h"
#include <iostream>


int main() {
	int status = 0;

	bool up_count;
	ap_uint<8> seven_segment_data;
	ap_uint<4> seven_segment_enable;
	ap_uint<4> modulo = 10;;

	for (int i = 0; i < 20; i++) {
		up_count = 1;
		up_counter_no_hs(up_count, modulo, seven_segment_data, seven_segment_enable);

		up_count = 0;
		up_counter_no_hs(up_count, modulo, seven_segment_data, seven_segment_enable);
	}
	return status;
}






