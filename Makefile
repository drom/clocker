# export VERILATOR_ROOT

VERILATOR_FLAGS = -Wall --cc --trace src/top.sv --exe src/tb.cpp

default: verilate compile run

verilate:
	$(VERILATOR_ROOT)/bin/verilator $(VERILATOR_FLAGS)

compile:
	make -j -C obj_dir/ -f Vtop.mk Vtop

run:
	obj_dir/Vtop
