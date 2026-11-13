#include "waveform_generator.h"


void waveform_generator(bool *x) {

#pragma HLS INTERFACE mode=ap_fifo depth=N port=x
#pragma HLS INTERFACE mode=ap_ctrl_hs port=return


  const bool a[N] = {0, 1, 0, 0, 0, 1, 1, 1};


  for (int i = 0; i <N; i++) {
#pragma HLS PIPELINE rewind

    *(x+i) = a[i];
  }

}
