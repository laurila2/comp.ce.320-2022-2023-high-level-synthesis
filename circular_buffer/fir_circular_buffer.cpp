// Circular buffer based FIR filter function
// Santeri Laurila (274301)
// Version:  0.2
// Modified: 31.3.2023

#include "fir_circular_buffer.h"

void fir_circular_buffer(dType din, dType taps[N_REGS], dType &dout) 
{	
	static dType buffer[N_REGS];  // Circular buffer
	static int bufferIndex = 0;  // Buffer index
	dType temp = 0;
	
	// Add new input sample to circular buffer
	buffer[bufferIndex] = din;
	
	// Multiply-accumulate
	for(int i = 0; i < N_REGS; i++) 
    {
		int bufferOffset = (bufferIndex + N_REGS - i) % N_REGS;  // Circular buffer offset
		temp += taps[i] * buffer[bufferOffset];
	}
	
	// Update output and buffer index
	dout = temp;
	bufferIndex = (bufferIndex + 1) % N_REGS;
}
