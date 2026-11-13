


void memory_mapped_output(unsigned short int *mled) {
#pragma HLS INTERFACE mode=m_axi port=mled offset=off
#pragma HLS INTERFACE mode=ap_ctrl_hs port=return


	*(mled+0x10/2) = 0xFFFF;


}
