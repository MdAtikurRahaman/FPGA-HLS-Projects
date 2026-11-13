#include "pointer_stream_bad.h"


void pointer_stream_bad(unsigned short *d_out, unsigned short *d_in) {
#pragma HLS INTERFACE mode=ap_fifo depth=2 port=d_out
#pragma HLS INTERFACE mode=ap_fifo depth=4 port=d_in
	int acc = 0;

	acc += *d_in;
	acc += *d_in;
	*d_out = acc;

	acc += *d_in;
	acc += *d_in;
	*d_out = acc;
}
