#include "array_write.h"


void array_write(int A[N]) {
#pragma HLS INTERFACE mode=ap_ctrl_hs port=return
#pragma HLS INTERFACE mode=m_axi  port=A offset=off


	for (unsigned int i = 0; i < SIZE; i++) {
#pragma HLS PIPELINE off
		A[i] = i+1;
	}
}
