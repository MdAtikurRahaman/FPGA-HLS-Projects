#pragma once

#include "seven_segment_driver.h"


void seven_segment_driver(
		bool       refresh_signal,

		unsigned int a,

		ap_uint<8> &seven_segment_data,
		ap_uint<4> &seven_segment_enable);
