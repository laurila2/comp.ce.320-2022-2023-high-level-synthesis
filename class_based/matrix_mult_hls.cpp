// Santeri Laurila
// student number: 274301

// Matrix multiplication for HLS
// Class-based exercise
// Version 1.4
// updated: 10.3.2023

#include "matrix_mult.h"
#include "matrix.cpp"

#pragma design top
void matrixMultHLS(hls_data_t A[N][N], hls_data_t B[N][N], hls_result_t C[N][N], hls_transpose_t transpose)
{
    // Initialize matrix-objects
    Matrix<hls_data_t, N> A_temp;
    Matrix<hls_data_t, N> B_temp;
    Matrix<hls_result_t, N>::mult_result_t C_temp;

    // Put data to matrices from input
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            A_temp.setElement(i, j, A[i][j]);
            B_temp.setElement(i, j, B[i][j]);
        }
    }

    if (transpose == 3) {  // Transpose both A and B before multiplication
        A_temp.transpose();
        B_temp.transpose();
        C_temp = A_temp * B_temp;
    }
    if (transpose == 2) {  // Transpose B before multiplication
        B_temp.transpose();
        C_temp = A_temp * B_temp;
    }
    if (transpose == 1) {  // Transpose A before multiplication
        A_temp.transpose();
        C_temp = A_temp * B_temp;
    }
    if (transpose == 0) {  // No transposition
        C_temp = A_temp * B_temp;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        { 
            C[i][j] =  C_temp.getElement(i, j);
        }
    }
}
