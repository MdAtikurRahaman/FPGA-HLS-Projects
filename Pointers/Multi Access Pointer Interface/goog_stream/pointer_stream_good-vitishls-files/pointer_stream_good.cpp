#include "pointer_stream_good.h"


void pointer_stream_good( unsigned short *d_out, unsigned short *d_in) {

#pragma HLS INTERFACE mode=ap_fifo depth=1024 port=d_out
#pragma HLS INTERFACE mode=ap_fifo depth=1024 port=d_in
	unsigned short acc = 0;
	acc += *d_in;
	acc += *(d_in+1);
	*d_out = acc;

	acc += *(d_in+2);
	acc += *(d_in+3);
	*(d_out+1) = acc;

}


