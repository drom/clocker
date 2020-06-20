#include "Vtop.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "clocker.h"

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    Vtop top;
    VerilatedVcdC tfp;

    unsigned char* clks [3] = {&top.clk0, &top.clk1, &top.clk2};
    int clk_counters [3] = {0, 0, 0};
    const int clk_periods [3] = {17, 23, 37};
    Clocker clk(3, clk_counters, clk_periods, clks);

    // init trace dump
    Verilated::traceEverOn(true);

    top.trace (&tfp, 99);
    tfp.open ("top.vcd");

    top.reset_n = 0;

    int time = 0;
    while (time < 500) {
        top.reset_n = (time > 100);
        tfp.dump (time);
        time += clk.tick();
        top.eval ();
        if (Verilated::gotFinish()) exit(0);
    }

    tfp.close();
    exit(0);
}
