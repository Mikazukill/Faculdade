if {[file isdirectory work]} { vdel -all -lib work }
vlib work
vmap work work

vlog -work work  controle_acesso.sv
 

vsim -voptargs=+acc -t ns work.tb_controle_acesso

set StdArithNoWarnings 1
set StdVitalGlitchNoWarnings 1 

add wave sim:/*
add wave -divider sinais_internos
add wave sim:/dut/*

run 2 us

