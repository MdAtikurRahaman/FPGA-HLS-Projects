#include "data_generator.h"


void data_generator(hls::stream<unsigned short int> &dout,
		            unsigned short int n) {

	for (unsigned short int i = 0; i < n; i++) {
		dout << i+1;
	}

}
