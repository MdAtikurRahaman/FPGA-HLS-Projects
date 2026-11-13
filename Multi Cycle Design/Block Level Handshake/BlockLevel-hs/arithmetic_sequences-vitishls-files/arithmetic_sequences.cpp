#include "arithmetic_sequences.h"

void arithmetic_sequences(
		ap_uint<4> first_item,
		ap_uint<4> common_difference,
		ap_uint<8> n,
		unsigned int &nth_term
		)
{
#pragma HLS INTERFACE mode=ap_none port=first_item
#pragma HLS INTERFACE mode=ap_none port=common_difference
#pragma HLS INTERFACE mode=ap_none port=n
#pragma HLS INTERFACE mode=ap_none port=nth_term


	unsigned int a[N];
	a[0] = first_item;

	for (int i = 1; i < N; i++) {
#pragma HLS PIPELINE OFF
		a[i] = a[i-1] +  common_difference;
	}

	nth_term = a[n-1];
}
