# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\anju singh\Desktop\psoc_intro\psoc_intro\Assignment1.cydsn\Assignment1.cyprj
# Date: Sun, 01 Nov 2020 06:56:08 GMT
#set_units -time ns
create_clock -name {CyILO} -period 10000 -waveform {0 5000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_clock -name {CyBUS_CLK(fixed-function)} -period 41.666666666666664 -waveform {0 20.8333333333333} [get_pins {ClockBlock/clk_bus_glb_ff}]

set_false_path -from [get_pins {__ONE__/q}]

# Component constraints for C:\Users\anju singh\Desktop\psoc_intro\psoc_intro\Assignment1.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\anju singh\Desktop\psoc_intro\psoc_intro\Assignment1.cydsn\Assignment1.cyprj
# Date: Sun, 01 Nov 2020 06:55:38 GMT
