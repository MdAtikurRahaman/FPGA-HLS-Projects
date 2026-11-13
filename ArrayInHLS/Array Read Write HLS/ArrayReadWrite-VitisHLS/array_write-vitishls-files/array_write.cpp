#include "array_write.h"



void array_write(unsigned char A[N]) {
#pragma HLS INTERFACE mode=ap_ctrl_hs port=return
#pragma HLS INTERFACE mode=ap_memory port=A


	for (unsigned char i = 0; i < SIZE; i++) {
#pragma HLS PIPELINE off
		A[i] = i+1;
	}
}
