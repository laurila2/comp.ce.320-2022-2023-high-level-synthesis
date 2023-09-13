// Circular buffer based FIR filter function header
// Santeri Laurila (274301)
// Version:  0.2
// Modified: 31.3.2023

#ifndef __fir_circ__
#define __fir_circ__

#include <ac_int.h>

const int WIDTH = 8;
typedef ac_int<WIDTH,false> dType;

const int N_REGS = 8;

void fir_circular_buffer(dType din, dType taps[N_REGS], dType &dout);

#endif
