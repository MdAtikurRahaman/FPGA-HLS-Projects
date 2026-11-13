#include "array_write-tb.h"
#include <iostream>

int main() {

	int A[N] = {0};

	array_write(A);

	for (int i = 0; i < SIZE; i++) {
		std::cout << "A[" << i << "] = " << A[i] << std::endl;
	}


	return 0;
}
