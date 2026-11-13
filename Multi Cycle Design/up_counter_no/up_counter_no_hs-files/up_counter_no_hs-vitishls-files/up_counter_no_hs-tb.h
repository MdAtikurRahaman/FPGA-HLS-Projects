#pragma once
#include "up_counter_no_hs.h"





void up_counter_no_hs(
		bool up_count,
		ap_uint<4> modulo,
		ap_uint<8> &seven_segment_data,
		ap_uint<4> &seven_segment_enable
		);
