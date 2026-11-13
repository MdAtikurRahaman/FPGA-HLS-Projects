/************************************************
Copyright (c) 2021, Mohammad Hosseinabady
	mohammad@highlevel-synthesis.com.
	https://highlevel-synthesis.com/

All rights reserved.
Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software
without specific prior written permission.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. // Copyright (c) 2020, Mohammad Hosseinabady.
************************************************/
#include "dice_roller_lfsr-tb.h"
#include <iostream>
#include <map>
#include <time.h>

std::map<ap_uint<8>, int> svnsg_number = {
		{0b11000000,   0},
		{0b11111001,   1},
		{0b10100100,   2},
		{0b10110000,   3},
		{0b10011001,   4},
		{0b10010010,   5},
		{0b10000010,   6},
		{0b11111000,   7},
		{0b10000000,   8},
		{0b10010000,   9} };


int main() {

	int status = 0;

	bool          roll;
	ap_uint<8>   seven_segment_data;
	ap_uint<4>   seven_segment_enable;

	srand (time(NULL));

	roll = 1;
	dice_roller_lfsr(roll, seven_segment_data, seven_segment_enable);
	std::cout << " rand number = " << svnsg_number[seven_segment_data] << std::endl;



	for (int i = 0; i < 200; i++) {
		int r =rand()%1024;
		for (int j = 0; j < r; j++) {
			roll = 0;
			dice_roller_lfsr(roll, seven_segment_data, seven_segment_enable);
		}
		roll = 1;
		dice_roller_lfsr(roll, seven_segment_data, seven_segment_enable);
		std::cout << " rand number = " << svnsg_number[seven_segment_data] << std::endl;
	}

	return status;


}


