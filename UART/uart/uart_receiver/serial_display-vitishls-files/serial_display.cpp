#include "serial_display.h"


void ascii27segment(
		ap_uint<8> ascii_data,
		ap_uint<8> &seven_segment_data)
{
	ap_uint<8> data_index;
	if (ascii_data >47 && ascii_data < 57) {
		data_index = ascii_data - 48;
	} else if (ascii_data >64 && ascii_data < 71) {
		data_index = (ascii_data - 65) + 10;
	} else {
		data_index = 16;
	}

	seven_segment_data = seven_segment_code[data_index];
}


void serial_display(
		ap_uint<8> ascii_data,
		bool data_valid,
		ap_uint<8> &seven_segment_data,
		ap_uint<4> &seven_segment_enable )
{
#pragma HLS PIPELINE
#pragma HLS INTERFACE ap_none port=ascii_data
#pragma HLS INTERFACE ap_none port=data_valid
#pragma HLS INTERFACE ap_none port=seven_segment_data
#pragma HLS INTERFACE ap_none port=seven_segment_enable
#pragma HLS INTERFACE ap_ctrl_none port=return

	static ap_uint<8> ascii_data_local = 71;
	ap_uint<8> seven_segment_data_local;
	if (data_valid == 1) {
		ascii_data_local = ascii_data;
	}
	ascii27segment(ascii_data, seven_segment_data_local);

	seven_segment_data   = seven_segment_data_local;
	seven_segment_enable = 0b1110;



}
