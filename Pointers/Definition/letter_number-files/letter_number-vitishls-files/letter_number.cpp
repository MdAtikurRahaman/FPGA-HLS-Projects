#include "letter_number.h"

void letter_number(
		bool       sel,
		ap_uint<4> index,
		ap_uint<8> &seven_segment_data,
		ap_uint<4> &seven_segment_enable)
{
#pragma HLS INTERFACE mode=ap_ctrl_none port=return
#pragma HLS INTERFACE mode=ap_none port=sel
#pragma HLS INTERFACE mode=ap_none port=index
#pragma HLS INTERFACE mode=ap_none port=seven_segment_data
#pragma HLS INTERFACE mode=ap_none port=seven_segment_enable

#pragma HLS pipeline
	ap_uint<8> number[10] = { 0b11000000,  // 0
							  0b11111001,  // 1
							  0b10100100,  // 2
							  0b10110000,  // 3
							  0b10011001,  // 4
							  0b10010010,  // 5
							  0b10000010,  // 6
							  0b11111000,  // 7
							  0b10000000,  // 8
							  0b10010000   // 9
							};
	ap_uint<8> letter[10] = { 0b11000000,  // o
							  0b10100000,  // a
							  0b10000011,  // b
							  0b11000110,  // c
							  0b10100001,  // d
							  0b10000100,  // e
							  0b10001110,  // f
							  0b10010000,  // g
							  0b10001011,  // h
							  0b11000111,  // L
							};


	ap_uint<8> * ptr;

	if (sel) {
		ptr = letter;
	} else {
		ptr = number;
	}

	ap_uint<8> data;
	ap_uint<4> enable;

	if (index < 10)
		data = *(ptr+index);
	else
		data = 0b10000110; //E: Error

	enable = 0b1110;

	seven_segment_data   = data;
	seven_segment_enable = enable;

}
