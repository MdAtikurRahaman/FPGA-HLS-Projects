#include "producer_nonblocking.h"



void producer_nonblocking(
		hls::stream<unsigned short int> &dout,
		unsigned short int n) {

	for (unsigned short int i = 0; i < n; i++) {
		while(dout.full());
		dout.write_nb(i+1);
	}

}
