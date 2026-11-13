
log_wave -r /
set designtopgroup [add_wave_group "Design Top Signals"]
set coutputgroup [add_wave_group "C Outputs" -into $designtopgroup]
set pulse_group [add_wave_group pulse(wire) -into $coutputgroup]
add_wave /apatb_pulse_generator_top/AESL_inst_pulse_generator/pulse -into $pulse_group -radix hex
set cinputgroup [add_wave_group "C Inputs" -into $designtopgroup]
set input_group [add_wave_group input(wire) -into $cinputgroup]
add_wave /apatb_pulse_generator_top/AESL_inst_pulse_generator/input_r -into $input_group -radix hex
set resetgroup [add_wave_group "Reset" -into $designtopgroup]
add_wave /apatb_pulse_generator_top/AESL_inst_pulse_generator/ap_rst -into $resetgroup
set clockgroup [add_wave_group "Clock" -into $designtopgroup]
add_wave /apatb_pulse_generator_top/AESL_inst_pulse_generator/ap_clk -into $clockgroup
set testbenchgroup [add_wave_group "Test Bench Signals"]
set tbinternalsiggroup [add_wave_group "Internal Signals" -into $testbenchgroup]
set tb_simstatus_group [add_wave_group "Simulation Status" -into $tbinternalsiggroup]
set tb_portdepth_group [add_wave_group "Port Depth" -into $tbinternalsiggroup]
add_wave /apatb_pulse_generator_top/AUTOTB_TRANSACTION_NUM -into $tb_simstatus_group -radix hex
add_wave /apatb_pulse_generator_top/ready_cnt -into $tb_simstatus_group -radix hex
add_wave /apatb_pulse_generator_top/done_cnt -into $tb_simstatus_group -radix hex
add_wave /apatb_pulse_generator_top/LENGTH_input_r -into $tb_portdepth_group -radix hex
add_wave /apatb_pulse_generator_top/LENGTH_pulse -into $tb_portdepth_group -radix hex
set tbcoutputgroup [add_wave_group "C Outputs" -into $testbenchgroup]
set tb_pulse_group [add_wave_group pulse(wire) -into $tbcoutputgroup]
add_wave /apatb_pulse_generator_top/pulse -into $tb_pulse_group -radix hex
set tbcinputgroup [add_wave_group "C Inputs" -into $testbenchgroup]
set tb_input_group [add_wave_group input(wire) -into $tbcinputgroup]
add_wave /apatb_pulse_generator_top/input_r -into $tb_input_group -radix hex
save_wave_config pulse_generator.wcfg
run all
quit

