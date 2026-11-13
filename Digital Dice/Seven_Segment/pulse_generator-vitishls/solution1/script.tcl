############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project pulse_generator-vitishls
set_top pulse_generator
add_files pulse_generator-vitishls/pulse_generator.h
add_files pulse_generator-vitishls/pulse_generator.cpp
add_files -tb pulse_generator-vitishls/pulse_generator-tb.h -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
add_files -tb pulse_generator-vitishls/pulse_generator-tb.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution1" -flow_target vivado
set_part {xc7a35t-cpg236-1}
create_clock -period 10 -name default
config_export -format ip_catalog -rtl verilog
source "./pulse_generator-vitishls/solution1/directives.tcl"
csim_design
csynth_design
cosim_design -trace_level all
export_design -rtl verilog -format ip_catalog
