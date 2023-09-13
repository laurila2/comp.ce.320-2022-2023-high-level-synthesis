// Santeri Laurila (274301)
// Determinant exercise
// Last modified: 19.3.2023
// Version: 0.4

#include "determinant.h"
#include "matrix.h"

#include <ac_assert.h>
#include <ac_int.h>

template<int N_det>
constexpr auto determinant_helper()
{	
    static_assert(N_det <= 10, "N_det size is too large!");

    if constexpr (N_det == 1) {
        return [](auto a) { return a.getElement(0, 0); };
    }
    else {
        return [](auto a) {
            ac_int<W,S> det = 0;
            Matrix<ac_int<W,S>, N_det-1> minor;

            // Popularize minor matrix
            // Iterate for each element of first row
            for (int i = 0; i < N_det; i++) {
                for (int j = 1; j < N_det; j++) {
                    for (int k = 0; k < N_det-1; k++) {
                        if (k >= i) {
                            minor.setElement(j-1, k, a.getElement(j, k+1));
                        }
                        else {
                            minor.setElement(j-1, k, a.getElement(j, k));
                        }
                    }   
                }
            // Add to det with sign and call recursion
            if (i % 2 == 0) {
                det += a.getElement(0, i) * determinant_helper<N_det-1>()(minor);
                }
            else {
                det -= a.getElement(0, i) * determinant_helper<N_det-1>()(minor);
                }
            }
            return det;
        };
    }
}

// Top-level function. No modifications needed
#pragma hls_design top
void determinant(ac_int<W,S> input_1[N][N], ac_int<W,S> &result) {
    Matrix<ac_int<W,S>, N> input_mat(input_1);
    result = determinant_helper<N>()(input_mat);
}
