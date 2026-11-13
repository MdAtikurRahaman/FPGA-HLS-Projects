#include "pointer_stream_better.h"



void pointer_stream_better(volatile unsigned short *d_out, volatile unsigned short *d_in) {
#pragma HLS INTERFACE mode=ap_fifo depth=2 port=d_out
#pragma HLS INTERFACE mode=ap_fifo depth=4 port=d_in


	unsigned short acc = 0;

	acc += *d_in;
	acc += *d_in;
	*d_out = acc;

	acc += *d_in;
	acc += *d_in;
	*d_out = acc;
}
