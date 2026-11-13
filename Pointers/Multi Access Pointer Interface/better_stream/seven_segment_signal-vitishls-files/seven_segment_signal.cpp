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
#include "seven_segment_signal.h"




void seven_segment_signal(bool &out_signal) {
#pragma HLS INTERFACE ap_none port=out_signal
#pragma HLS INTERFACE ap_ctrl_none port=return


	static int count = SIGNAL_PERIOD-1;

	int next_count = count;

	bool next_out_signal;

	if (count == 0) {
		next_out_signal = 1;
		next_count = SIGNAL_PERIOD-1;
	} else {
		next_out_signal = 0;
		next_count = count-1;
	}

	count = next_count;
	out_signal= next_out_signal;
}
