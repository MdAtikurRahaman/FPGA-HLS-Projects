#define N 1024

void array_ram_rom(int *A, int *B) {

	int coeff[N];

	for (int i = 0; i < N; i++) {
		coeff[i] = i;
	}


	for (int i = 0; i < N; i++) {
		B[i] = A[i] * coeff[i];
	}


}
