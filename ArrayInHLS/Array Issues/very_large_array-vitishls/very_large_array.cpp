#include "very_large_array.h"
#include <cstdlib>

void very_large_array(int *A, long int& sum, int n) {
	long int s = 0;


	int a[N];


	for (int i=0 ; i < n; i++) {
		a[i] = *(A+i);
	}

	for (int i=0 ; i < n; i++) {
		s = s + a[i];
	}



	sum = s;
}
