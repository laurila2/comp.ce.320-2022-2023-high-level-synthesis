#ifndef _determinant
#define _determinant

#include <ac_int.h>

const int N = 5; // Matrix size (MxM)
const int W = 17; // Width. This may have to be increased with some test cases.
const int S = 1;  // Signedness (signed)

void determinant(ac_int<W,S> input[N][N], ac_int<W,S> &result);

#endif
