#include <iostream>
#include "array_read-tb.h"

int main() {

	int A[N];
	short int B;


	for (unsigned char i = 0; i < SIZE; i++) {
		A[i] = i+1;
	}

	array_read(A, B	);

	for (int i = 0; i < SIZE; i++) {
		std::cout << "A[" << i << "] = " << A[i] << std::endl;
	}

	std::cout << "B = " << B << std::endl;

	return 0;
}
