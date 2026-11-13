#include "data_streaming_modules.h"
#include <hls_stream.h>




void data_streaming_modules(int a[N], int b[N], int c[N], unsigned int n)
{

	hls::stream<int> a_fifo;
	hls::stream<int> b_fifo;
	hls::stream<int> c1_fifo;
	hls::stream<int> c2_fifo;

	for (unsigned int i = 0; i < n; i++) {
		a_fifo.write(a[i]);
		b_fifo.write(b[i]);
	}

	for (unsigned int i = 0; i < n; i++) {
		int a_local, b_local;
		a_local = a_fifo.read();
		b_local = b_fifo.read();
		c1_fifo.write(a_local+b_local);
	}

	for (unsigned int i = 0; i < n; i++) {
		int c1_local;
		c1_local = c1_fifo.read();
		c2_fifo.write(12*c1_local);
	}

	for (unsigned int i = 0; i < n; i++) {
		c[i] = c2_fifo.read();
	}
}

