#include "vector_addition.h"


void vector_add_core(int a[N], int b[N], int c[N]) {

	LC: for (int i = 0; i< N; i++) {
#pragma HLS PIPELINE
		c[i] = a[i] + b[i];
	}
}


void vector_addition(int *A_Data, int *B_Data, int *C_Data){
#pragma HLS INTERFACE mode=ap_fifo port=A_Data
#pragma HLS INTERFACE mode=ap_fifo port=B_Data
#pragma HLS INTERFACE mode=ap_fifo port=C_Data

	int a[N], b[N], c[N];

	LR: for (int i = 0; i < N; i++) {
		a[i] = A_Data[i];
		b[i] = B_Data[i];
	}

	vector_add_core(a, b, c);


	LW: for (int i = 0; i < N; i++) {
		C_Data[i] = c[i];
	}

}



