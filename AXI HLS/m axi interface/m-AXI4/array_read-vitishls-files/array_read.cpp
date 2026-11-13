#include "array_read.h"

void array_read(
		int A[N],
		short int &B) {
#pragma HLS INTERFACE mode=ap_ctrl_hs port=return
#pragma HLS INTERFACE mode=m_axi depth=1 port=A offset=off
#pragma HLS INTERFACE mode=ap_none port=B


	short  int t = 0;
	for (unsigned int i = 0; i < SIZE; i++) {
#pragma HLS PIPELINE off
		t += A[i];
	}

	B = t;


}
