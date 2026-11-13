#include "data_streaming_modules.h"
#include <hls_stream.h>

	void read_data(
			int a[N],
			int b[N],
			hls::stream<int> &a_fifo,
			hls::stream<int> &b_fifo,
			unsigned int n
	) {
		for (unsigned int i = 0; i < n; i++) {
			a_fifo.write(a[i]);
			b_fifo.write(b[i]);
		}
	}

	void add(
			hls::stream<int> &a_fifo,
			hls::stream<int> &b_fifo,
			hls::stream<int> &c1_fifo,
			unsigned int n
	) {

		for (unsigned int i = 0; i < n; i++) {
			int a_local, b_local;
			a_local = a_fifo.read();
			b_local = b_fifo.read();
			c1_fifo.write(a_local+b_local);
		}
	}

	void mult(
			hls::stream<int> &c1_fifo,
			hls::stream<int> &c2_fifo,
			unsigned int n
	) {
		for (unsigned int i = 0; i < n; i++) {
			int c1_local;
			c1_local = c1_fifo.read();
			c2_fifo.write(12*c1_local);
		}
	}

	void write_data(
			int c[N],
			hls::stream<int> &c2_fifo,
			unsigned int n
	) {
		for (unsigned int i = 0; i < n; i++) {
			c[i] = c2_fifo.read();
		}
	}

void data_streaming_modules(int a[N], int b[N], int c[N], unsigned short int n)
{
#pragma HLS INTERFACE mode=ap_memory port=a storage_type=ram_1p
#pragma HLS INTERFACE mode=ap_memory port=b storage_type=ram_1p
#pragma HLS INTERFACE mode=ap_memory port=c storage_type=ram_1p

#pragma HLS DATAFLOW
	hls::stream<int> a_fifo;
	hls::stream<int> b_fifo;
	hls::stream<int> c1_fifo;
	hls::stream<int> c2_fifo;

	read_data(a, b, a_fifo, b_fifo, n);

	add(a_fifo, b_fifo, c1_fifo, n);

	mult(c1_fifo, c2_fifo, n);

	write_data(c, c2_fifo, n);

}

