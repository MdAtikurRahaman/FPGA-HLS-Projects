void memory_mapped_input_output(unsigned short int *sw, unsigned short int *led) {

#pragma HLS INTERFACE mode=m_axi port=sw offset=off
#pragma HLS INTERFACE mode=m_axi port=led offset=off
#pragma HLS INTERFACE mode=ap_ctrl_hs port=return


	*(led + 0x010000/sizeof(unsigned short int)) = *sw;


}
