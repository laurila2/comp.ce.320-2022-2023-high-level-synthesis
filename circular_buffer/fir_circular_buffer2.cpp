// Circular buffer based FIR filter function
// Santeri Laurila (274301)
// Version:  0.2
// Modified: 31.3.2023

#include "fir_circular_buffer.h"

void fir_circular_buffer(dType din, dType taps[N_REGS], dType &dout) 
{
	static dType reg[N_REGS];  // Internal register
	dType temp = 0;

    // Initialize pointers to zero when overflow, goes back to 0
    static ac_int<3, false> write_ptr = 0;

    // Write din to register
    reg[write_ptr] = din;
    // Increase write_pointer
    write_ptr++;

	MAC: for(int i = 0; i < N_REGS; i++)  // Multiply-accumulate
	{
		temp += taps[i] * reg[i];
	}
	dout = temp;
}