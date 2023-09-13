// Santeri Laurila
// student number: 274301
// Testbench for determinant

#include "mc_scverify.h"
#include "determinant.h"
#include "matrix_mult.h"


CCS_MAIN(int argc, char *argv[])
{
    ac_int<W,S> A[N][N] = { {1,0,10},{11,12,0},{33,55,66} };  // Determinant = 2882;
    ac_int<W,S> B[N][N] = { {2,1,5},{2,0,0},{11,55,66} };  // Determinant = 418;
    ac_int<W,S> det;

    // Write to file
    freopen("determinant_output.txt", "w", stdout);
    
    // Test 1
    CCS_DESIGN(determinant)(A, det);
    std::cout << "Test 1:" << std::endl;
    std::cout << "Det value should be 2882" << std::endl;
    std::cout << "Det value is: " << det << std::endl;
    std::cout << std::endl;

    // Test 2
    CCS_DESIGN(determinant)(B, det);
    std::cout << "Test 2:" << std::endl;
    std::cout << "Det value should be 418" << std::endl;
    std::cout << "Det value is: " << det << std::endl;

    // Close file
    fclose(stdout);

    CCS_RETURN(0);
}