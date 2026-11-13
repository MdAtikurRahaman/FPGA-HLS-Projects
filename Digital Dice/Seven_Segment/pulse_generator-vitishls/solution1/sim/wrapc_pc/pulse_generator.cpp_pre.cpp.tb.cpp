// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
# 1 "D:/labs/HLSLDSeq/P02S05-Utilities/pulse_generator/pulse_generator-vitishls/pulse_generator.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "D:/labs/HLSLDSeq/P02S05-Utilities/pulse_generator/pulse_generator-vitishls/pulse_generator.cpp"
# 1 "D:/labs/HLSLDSeq/P02S05-Utilities/pulse_generator/pulse_generator-vitishls/pulse_generator.h" 1
       
# 2 "D:/labs/HLSLDSeq/P02S05-Utilities/pulse_generator/pulse_generator-vitishls/pulse_generator.cpp" 2

typedef enum{w1, w0} pulse_gen_states_type;

void pulse_generator(bool input, bool &pulse) {
#pragma HLS INTERFACE ap_none port=input
#pragma HLS INTERFACE ap_none port=pulse
#pragma HLS INTERFACE ap_ctrl_none port=return


 static pulse_gen_states_type state = w1;


 pulse_gen_states_type next_state;
 bool next_pulse;

 switch(state) {
 case w1:
  if (input == 1) {
   next_state = w0;
   next_pulse = 1;
  } else {
   next_state = w1;
   next_pulse = 0;
  }
  break;
 case w0:
  if (input == 1) {
   next_state = w0;
   next_pulse = 0;
  } else {
   next_state = w1;
   next_pulse = 0;
  }
  break;
 default:

  break;
 }

 state = next_state;
 pulse = next_pulse;

}
#ifndef HLS_FASTSIM
#ifdef __cplusplus
extern "C"
#endif
void apatb_pulse_generator_ir(bool, bool &);
#ifdef __cplusplus
extern "C"
#endif
void pulse_generator_hw_stub(bool input, bool &pulse){
pulse_generator(input, pulse);
return ;
}
#ifdef __cplusplus
extern "C"
#endif
void apatb_pulse_generator_sw(bool input, bool &pulse){
apatb_pulse_generator_ir(input, pulse);
return ;
}
#endif
# 44 "D:/labs/HLSLDSeq/P02S05-Utilities/pulse_generator/pulse_generator-vitishls/pulse_generator.cpp"

