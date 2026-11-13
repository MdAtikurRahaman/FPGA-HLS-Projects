#include <iostream>
#include "array_read-tb.h"



int main() {

	unsigned char A[N];
	unsigned char B;

	for (unsigned char i = 0; i < SIZE; i++) {
		A[i] = i+1;
	}

	array_read(A, B	);

	for (int i = 0; i < SIZE; i++) {
		std::cout << "A[" << i << "] = " << (int)A[i] << std::endl;
	}
	std::cout << "B = " << (int)B << std::endl;


	return 0;
}

