// Santeri Laurila
// student number: 274301

// Matrix multiplication for HLS
// Version 1.1
// updated: 22.2.2023

#include "matrix_mult.h"
#include <ac_assert.h>


#pragma design top
void matrixMultHLS(hls_data_t A[N][M], hls_data_t B[N][M], hls_result_t C[N][M], hls_transpose_t transpose)
{
    // Check that transpose has legal value
    assert(transpose >= 0 && transpose < 4);

    ROW: for (int i = 0; i < N; i++)
    {
        COLUMN: for (int j = 0; j < N; j++)
        {
            hls_result_t C_temp = 0;
            RESULT: for (int k = 0; k < N; k++)
            {
                if (transpose == 3) {  // Transpose both A and B before multiplication
                    C_temp += A[k][i] * B[j][k];
                    //C_temp += A[k+1][i] * B[j][k+1];
                }
                if (transpose == 2) {  // Transpose B before multiplication
                    C_temp += A[i][k] * B[j][k];
                    //C_temp += A[i][k+1] * B[j][k+1];
                }
                if (transpose == 1) {  // Transpose A before multiplication
                    C_temp += A[k][i] * B[k][j];
                    //C_temp += A[k+1][i] * B[k+1][j];
                }
                if (transpose == 0) {  // Transpose both A and B before multiplication
                    C_temp += A[i][k] * B[k][j];
                    //C_temp += A[i][k+1] * B[k+1][j];
                }                                           
            }
            C[i][j] = C_temp;
        }
    }
}
