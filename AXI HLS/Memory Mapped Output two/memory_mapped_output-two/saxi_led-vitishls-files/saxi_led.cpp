
void saxi_led(unsigned short int axiled, unsigned short int &led) {
#pragma HLS INTERFACE mode=ap_none port=led
#pragma HLS INTERFACE mode=s_axilite port=axiled
#pragma HLS INTERFACE mode=ap_ctrl_none port=return


	led = axiled;

}
