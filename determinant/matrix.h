// Name: Petri Sydänmaa
// Student number: 273002

#include "matrix_mult.h"

template<typename element_t, int N>
class Matrix
{
    private:
        element_t matrix[N][N] = {0};
        bool transposed;
    public:
        // Return type for * operator
        typedef Matrix<hls_result_t, N> mult_result_t;

        // Default constructor. Matrix is set to zero in declaration.
        Matrix()
        {
            transposed = false;
        }

        // Construct the matrix with given input values.
        Matrix(element_t input_vals[N][N])
        {
            transposed = false;
            INPUT_LOOP : for (ac_int<ac::nbits<N>::val, false> i = 0; i < N; i++)
            {
                for (ac_int<ac::nbits<N>::val, false> j = 0; j < N; j++)
                {
                    setElement(i, j, input_vals[i][j]);
                }
            }
        }

        // Put the given element to the given place in the matrix
        void setElement(ac_int<ac::nbits<N>::val, false> i, ac_int<ac::nbits<N>::val, false> j, element_t val)
        {
            matrix[i][j] = val;
        }

        // Get the matrix element from the given place
        element_t getElement(ac_int<ac::nbits<N>::val, false> i, ac_int<ac::nbits<N>::val, false> j) const
        {
            element_t tmp;
            if (transposed)
            {
                tmp = matrix[j][i];
            }
            else
            {
                tmp = matrix[i][j];
            }
            return tmp;
        }

        void transpose()
        {
            transposed = true;
        }

        // Matrix multiplication of this * param
        mult_result_t operator * (const Matrix& param)
        {
            mult_result_t result_matrix;

            MATRIX_MULT_LOOP : for (ac_int<ac::nbits<N>::val, false> i = 0; i < N; i++)
            {
                for (ac_int<ac::nbits<N>::val, false> j = 0; j < N; j++)
                {
                    hls_result_t tmp = 0;
                    for (ac_int<ac::nbits<N>::val, false> k = 0; k < N; k++)
                    {
                        tmp += getElement(i, k) * param.getElement(k, j);
                    }
                    result_matrix.setElement(i, j, tmp);
                }
            }
            return result_matrix;  
        }
};