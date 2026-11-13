#include "up_counter_with_ack.h"


void up_counter_with_ack (
		bool       up_count,
		ap_uint<4> max_count,
		ap_uint<8> &seven_segment_data,
		ap_uint<4> &seven_segment_enable
		) {


#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE mode=ap_ack port=up_count
#pragma HLS INTERFACE ap_none port=max_count
#pragma HLS INTERFACE ap_none port=seven_segment_data
#pragma HLS INTERFACE ap_none port=seven_segment_enable

	static unsigned int  counter = 0;


	if (up_count == 1) {
		counter = counter + 1;
		counter = counter%max_count;
	}


	seven_segment_data = seven_segment_code[counter];
	seven_segment_enable = 0b1110;


}
