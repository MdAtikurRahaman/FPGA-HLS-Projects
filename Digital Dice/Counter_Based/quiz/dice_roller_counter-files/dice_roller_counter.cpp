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

#include "dice_roller_counter.h"

ap_uint<3> get_rand()
{

	ap_uint<3> r;
	static ap_uint<3> count = 0;

	if (count == 6)
		count = 1;
	else
		count++;

	r = count;

	return r;
}


void dice_roller_counter(
		bool         roll,
		ap_uint<8>  &seven_segment_data,
		ap_uint<4>  &seven_segment_enable) {
#pragma HLS INTERFACE ap_none port=roll
#pragma HLS INTERFACE ap_none port=seven_segment_data
#pragma HLS INTERFACE ap_none port=seven_segment_enable
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS PIPELINE

	static ap_uint<3> rand_number = 0;

	ap_uint<3> r = get_rand();
	if (roll == 1)
		rand_number = r;

	seven_segment_data = svn_sg_code[rand_number];
	seven_segment_enable = 0b1110;

}
