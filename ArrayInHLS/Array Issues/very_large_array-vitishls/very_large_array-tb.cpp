#include <iostream>
#include "very_large_array.h"

void very_large_array(int *A, long int& sum, int n);


int main() {
	int status = 0;


	int *A= (int*)malloc(N*sizeof(int));

	for (int i = 0; i< N; i++) {
		A[i] = i;
	}

	long int sum;

	very_large_array(A, sum, N);

	std::cout << " sum = " << sum << std::endl;

	if (sum != (N-1)*N/2) {
		std::cout << " Test Failed " << std::endl;
		status = -1;
	} else {
		std::cout << " Test Passed " << std::endl;
	}


	return status;
}
