# Switches
set_property PACKAGE_PIN V17 [get_ports {sw[0]}]
	set_property IOSTANDARD LVCMOS33 [get_ports {sw[0]}]
set_property PACKAGE_PIN V16 [get_ports {sw[1]}]
	set_property IOSTANDARD LVCMOS33 [get_ports {sw[1]}]
set_property PACKAGE_PIN W16 [get_ports {sw[2]}]
	set_property IOSTANDARD LVCMOS33 [get_ports {sw[2]}]
set_property PACKAGE_PIN W17 [get_ports {sw[3]}]
	set_property IOSTANDARD LVCMOS33 [get_ports {sw[3]}]
	
#7 segment display
set_property PACKAGE_PIN W7 [get_ports {seven_segment_data[0]}]
	set_property IOSTANDARD LVCMOS33 [get_ports {seven_segment_data[0]}]
set_property PACKAGE_PIN W6 [get_ports {seven_segment_data[1]}]
	set_property IOSTANDARD LVCMOS33 [get_ports {seven_segment_data[1]}]
set_property PACKAGE_PIN U8 [get_ports {seven_segment_data[2]}]
	set_property IOSTANDARD LVCMOS33 [get_ports {seven_segment_data[2]}]
set_property PACKAGE_PIN V8 [get_ports {seven_segment_data[3]}]
	set_property IOSTANDARD LVCMOS33 [get_ports {seven_segment_data[3]}]
set_property PACKAGE_PIN U5 [get_ports {seven_segment_data[4]}]
	set_property IOSTANDARD LVCMOS33 [get_ports {seven_segment_data[4]}]
set_property PACKAGE_PIN V5 [get_ports {seven_segment_data[5]}]
	set_property IOSTANDARD LVCMOS33 [get_ports {seven_segment_data[5]}]
set_property PACKAGE_PIN U7 [get_ports {seven_segment_data[6]}]
	set_property IOSTANDARD LVCMOS33 [get_ports {seven_segment_data[6]}]

set_property PACKAGE_PIN V7 [get_ports seven_segment_data[7]]
	set_property IOSTANDARD LVCMOS33 [get_ports seven_segment_data[7]]

set_property PACKAGE_PIN U2 [get_ports {seven_segment_enable[0]}]
	set_property IOSTANDARD LVCMOS33 [get_ports {seven_segment_enable[0]}]
set_property PACKAGE_PIN U4 [get_ports {seven_segment_enable[1]}]
	set_property IOSTANDARD LVCMOS33 [get_ports {seven_segment_enable[1]}]
set_property PACKAGE_PIN V4 [get_ports {seven_segment_enable[2]}]
	set_property IOSTANDARD LVCMOS33 [get_ports {seven_segment_enable[2]}]
set_property PACKAGE_PIN W4 [get_ports {seven_segment_enable[3]}]
	set_property IOSTANDARD LVCMOS33 [get_ports {seven_segment_enable[3]}]
	
	
#Buttons
set_property PACKAGE_PIN T18 [get_ports up_count]
	set_property IOSTANDARD LVCMOS33 [get_ports up_count]	