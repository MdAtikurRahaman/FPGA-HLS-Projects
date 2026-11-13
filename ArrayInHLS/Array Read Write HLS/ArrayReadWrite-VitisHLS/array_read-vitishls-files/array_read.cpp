#include "array_read.h"



void array_read(
		unsigned char A[N],
		unsigned char &B) {
#pragma HLS INTERFACE mode=ap_ctrl_hs port=return
#pragma HLS INTERFACE mode=ap_memory port=A
#pragma HLS INTERFACE mode=ap_none port=B


	unsigned char t = 0;
	for (unsigned char i = 0; i < SIZE; i++) {
#pragma HLS PIPELINE off
		t += A[i];
	}

	B = t;
}
