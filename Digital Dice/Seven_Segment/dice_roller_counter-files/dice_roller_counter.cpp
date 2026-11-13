#include "dice_roller_counter.h"

unsigned int get_rand()
{


	static unsigned int count = 0;

	unsigned int r;
	count++;
	r = count%6+1;

	return r;
}


void dice_roller_counter(
		bool         roll,
		ap_uint<4>  &first_random_number,
		ap_uint<4>  &second_random_number) {
#pragma HLS INTERFACE ap_none port=roll
#pragma HLS INTERFACE ap_none port=first_random_number
#pragma HLS INTERFACE ap_none port=second_random_number
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS PIPELINE

	static bool random_number_index = 0;
	static unsigned int rand_number_1 = 0;
	static unsigned int rand_number_2 = 0;

	unsigned int r = get_rand();
	if (roll == 1) {
		if (random_number_index == 0) {
			rand_number_1 = r;
			random_number_index = 1;
		} else {
			random_number_index = 0;
			rand_number_2 = r;
		}
	}


	first_random_number  = rand_number_1;
	second_random_number = rand_number_2;

}
