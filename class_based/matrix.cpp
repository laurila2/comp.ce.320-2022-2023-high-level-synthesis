#ifndef MATRIX_H
#define MATRIX_H

#include <ac_int.h>
#include <ac_assert.h>

#include "matrix_mult.h"


template <typename element_t, int N>
class Matrix
{
    private:
        element_t A1[N][N];
    
    public:
        Matrix();
        Matrix(element_t input_vals[N][N]);
        void setElement(ac_int<ac::nbits<N>::val, true> i, ac_int<ac::nbits<N>::val, true> j, element_t val);
        element_t getElement(ac_int<ac::nbits<N>::val, true> i, ac_int<ac::nbits<N>::val, true> j) const;
        void transpose();
        typedef Matrix<hls_result_t, N> mult_result_t;
        mult_result_t operator * (const Matrix& param);
};

template <typename element_t, int N>
Matrix<element_t, N>::Matrix() {
    for (int i = 0; i < N ; i++) {
        for (int j = 0; j < N; j++) {
            A1[i][j] = 0;
        }
    }
}

template <typename element_t, int N>
Matrix<element_t, N>::Matrix(element_t A[N][N]) {
    for (int i = 0; i < N ; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = A1[i][j];
        }
    }
}

template <typename element_t, int N>
void Matrix<element_t, N>::setElement(ac_int<ac::nbits<N>::val, true> i, ac_int<ac::nbits<N>::val, true> j, element_t val) {
    A1[i][j] = val;
}

template <typename element_t, int N>
element_t Matrix<element_t, N>::getElement(ac_int<ac::nbits<N>::val, true> i, ac_int<ac::nbits<N>::val, true> j) const {
    return A1[i][j];
}

template <typename element_t, int N>
void Matrix<element_t, N>::transpose() {
    element_t temp[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[i][j] = A1[j][i];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A1[i][j] = temp[i][j];
        }
    }
}

template <typename element_t, int N>
typename Matrix<element_t, N>::mult_result_t Matrix<element_t, N>::operator * (const Matrix& B) {
    Matrix::mult_result_t C_temp; // Matrix-object

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            hls_result_t value = 0;

            for (int k = 0; k < N; k++)
            {
                value += getElement(i, k) * B.getElement(k, j);
                C_temp.setElement(i, j, value);
            }
        }
    }
    return C_temp;
}

#endif
