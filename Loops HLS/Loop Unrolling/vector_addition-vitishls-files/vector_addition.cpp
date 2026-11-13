#include "vector_addition.h"


void vector_add_core(int a[N], int b[N], int c[N]) {
#pragma HLS BIND_STORAGE variable=a type=ram_2p
#pragma HLS BIND_STORAGE variable=b type=ram_2p
#pragma HLS BIND_STORAGE variable=c type=ram_2p

#pragma HLS ARRAY_PARTITION dim=1 factor=2 type=cyclic variable=a
#pragma HLS ARRAY_PARTITION dim=1 factor=2 type=cyclic variable=b
#pragma HLS ARRAY_PARTITION dim=1 factor=2 type=cyclic variable=c

	for (int i = 0; i< N; i++) {
#pragma HLS UNROLL factor=4
#pragma HLS PIPELINE OFF
		c[i] = a[i] + b[i];
	}
}


void vector_addition(int *A_Data, int *B_Data, int *C_Data){
#pragma HLS INTERFACE mode=ap_fifo port=A_Data
#pragma HLS INTERFACE mode=ap_fifo port=B_Data
#pragma HLS INTERFACE mode=ap_fifo port=C_Data

	int a[N], b[N], c[N];


	for (int i = 0; i < N; i++) {
#pragma HLS PIPELINE OFF
		a[i] = A_Data[i];
		b[i] = B_Data[i];
	}

	vector_add_core(a, b, c);


	for (int i = 0; i < N; i++) {
#pragma HLS PIPELINE OFF
		C_Data[i] = c[i];
	}

}



