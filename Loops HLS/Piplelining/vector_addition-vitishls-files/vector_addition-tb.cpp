#include "vector_addition-tb.h"
#include <iostream>

int main() {
	int status = 0;

	int A_Data[N];
	int B_Data[N];
	int C_Data[N];

	for (int i = 0; i < N; i++) {
		A_Data[i] = rand();
		B_Data[i] = rand();
		C_Data[i] = 0;
	}

	vector_addition(A_Data, B_Data, C_Data);

	for (int i = 0; i < N; i++) {
		int t = A_Data[i] + B_Data[i];
		if (C_Data[i] != t) {
			std::cout << " Error at i = " << i
					  << "Software result = " << t
					  << " Hardware result = " << C_Data[i]
					  << std::endl;
			status = -1;
			break;
		}
	}


	if (status == 0) {
		std::cout << "Test PASSED!" << std::endl;
	} else {
		std::cout << "Test FAILED!" << std::endl;
	}

	return status;
}
