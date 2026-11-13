#include "consumer_nonblocking.h"

void consumer_nonblocking(hls::stream<unsigned short int> &din,
		           unsigned short int &sout,
				   unsigned short int n) {

	unsigned short int s = 0;

	for (int i = 0; i < n; i++) {
		unsigned short int t;
		while(din.empty());
		din.read_nb(t);
		s += t;
	}

	sout = s;
}
