#include "native_pointer_casting-tb.h"
#include <iostream>


int main() {
	int status = 0;

	bool sw;
	int A[N];
	short int led;

	A[0] = 12;
	A[1] = 13;
	sw = 0;
	native_pointer_casting(sw, A, led);
	std::cout << led << std::endl;


	sw = 1;
	native_pointer_casting(sw, A, led);
	std::cout << led << std::endl;


	return status;

}
