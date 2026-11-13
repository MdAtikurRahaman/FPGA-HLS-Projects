#include "data_consumer.h"


void data_consumer(hls::stream<unsigned short int> &din,
		           unsigned short int &sout,
				   unsigned short int n) {

	unsigned short int s = 0;

	for (int i = 0; i < n; i++) {
		s += din.read();
	}

	sout = s;
}
