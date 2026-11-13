#include "basic_pointer.h"


void basic_pointer(ap_uint<16> *d1, ap_uint<16> *d2) {
#pragma HLS INTERFACE mode=ap_fifo port=d1
#pragma HLS INTERFACE mode=ap_fifo port=d2
#pragma HLS INTERFACE mode=ap_ctrl_none port=return

	ap_uint<16> a = *d1;
	*d2 = 7*a;
}

