#include "mxv-tb.h"
#include <math.h>
#include <iostream>


void mxv_golden(float *a, float *x, float *y, int n, int m) {

	for (int i = 0; i < n; i++) {
		y[i] = 0;
		for (int j = 0; j < m; j++) {
			y[i] += x[i]*a[i*m+j];
		}
	}

}

int main() {

	int status = 0;
	const int n = N;
	const int m = M;
	float a[n*m];
	float x[m];
	float y_hw[n];
	float y_sw[n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i*m+j] = rand()/RAND_MAX;
		}
	}
	for (int i = 0; i < m; i++) {
		x[i] = rand()/RAND_MAX;
	}
	for (int i = 0; i < n; i++) {
		y_hw[i] = 0;
		y_sw[i] = 0;
	}

	mxv(a, x, y_hw, n, m);
	mxv_golden(a, x, y_sw, n, m);

	for (int i = 0; i < n; i++) {
		float diff = fabs(y_hw[i]- y_sw[i]);
		if (diff != diff || diff > 0.1) {
			std::cout << "Error at  " << i << " y_hw["<<i << "] = " << y_hw[i] << " != " << " y_sw["<<i << "] = " << y_sw[i] << std::endl;
			status = -1;
	        break;
	    }
	}


	if (status == 0) {
		std::cout << "Test SUCCESS!" << std::endl;
	} else {
	    std::cout << "Test FAILED!" << std::endl;
	}



	return status;
}
