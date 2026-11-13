#include "mxv.h"


void mxv(float *a, float *x, float *y, int n, int m) {
#pragma HLS INTERFACE mode=ap_fifo  	port=a
#pragma HLS INTERFACE mode=ap_fifo 		port=x
#pragma HLS INTERFACE mode=ap_fifo 		port=y

	float A[N][M];
	float X[N];
	float Y[N];

	L1: for (int i = 0; i < n; i++) {
		L2: for (int j = 0; j < m; j++) {
#pragma HLS PIPELINE
			A[i][j] = *(a+i*m+j);
		}
	}
	L3: for (int i = 0; i < m; i++) {
#pragma HLS PIPELINE
		X[i] = *(x+i);
	}

	L4: for (int i = 0; i < n; i++) {
		float t = 0;
		L5: for (int j = 0; j < m; j++) {
#pragma HLS PIPELINE
			t = t + X[i]*A[i][j];
		}
		Y[i] = t;
	}

	L6: for (int i = 0; i < n; i++) {
#pragma HLS PIPELINE
		*(y+i) = Y[i];
	}

}
