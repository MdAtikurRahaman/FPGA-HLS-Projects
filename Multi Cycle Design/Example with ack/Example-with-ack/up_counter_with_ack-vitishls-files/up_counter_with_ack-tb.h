#pragma once
#include "up_counter_with_ack.h"





void up_counter_with_ack(
		bool up_count,
		ap_uint<4> modulo,
		ap_uint<8> &seven_segment_data,
		ap_uint<4> &seven_segment_enable
		);
