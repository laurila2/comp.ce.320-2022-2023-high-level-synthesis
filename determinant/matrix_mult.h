/*
Multiplies two NxN matrices A and B of type int and puts the product in matrix C.
Allows transposition of A and/or B before multiplication.

transpose = 0: Use A and B as is
transpose = 1: Transpose A before multiplication
transpose = 2: Transpose B before multiplication
transpose = 3: Transpose A and B before multiplication
*/

#include <ac_int.h>

#ifndef _matrix_mult
#define _matrix_mult

typedef int data_t;
typedef int result_t;

// Matrix size NxN
// const int N = 8;

// Range of element
const int RANGE = 31;

// Bit-accurate value for transpose
const int CONTROL = 3;

/*
// Return number of bits required to represent RANGE
// WIDTH = ac::nbits<RANGE>::val;

// Returns the number of bits required to index "N" elements
// INDEX = ac::log2_ceil<N>::val;

// RESULT_WIDTH = (2*WIDTH) + INDEX;
*/

const int WIDTH = ac::nbits<RANGE>::val;
const int RESULT_WIDTH = ((2 * ac::nbits<RANGE>::val)) + ac::log2_ceil<N>::val;
const int TRANSPOSE_WIDTH = ac::nbits<CONTROL>::val;

typedef ac_int<WIDTH, true> hls_data_t;  // true = signed
typedef ac_int<RESULT_WIDTH, true> hls_result_t;
typedef ac_int<CONTROL, true> hls_transpose_t;

// Golden reference implementation
void matrixMult(data_t A[N][N], data_t B[N][N], result_t C[N][N], int transpose);

// HLS implementation
void matrixMultHLS(hls_data_t A[N][N], hls_data_t B[N][N], hls_result_t C[N][N], hls_transpose_t transpose);

#endif
