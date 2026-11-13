#include "native_pointer_casting.h"

void native_pointer_casting(bool sw, int A[N], short int &led) {
#pragma HLS INTERFACE mode=ap_memory port=A storage_type=ram_1p
#pragma HLS INTERFACE mode=ap_none port=sw
#pragma HLS INTERFACE mode=ap_none port=led

	short int t;
	int *p = A;

	if (sw == 0) {
		t = *p + *(p+1);
	} else {
		short int *p1 = (short int *)A;
		t = *p1 + *(p1+1);
	}

	led = t;
}

