// Santeri Laurila
// student number: 274301

// Testbench for matrix multiplication for HLS course

// updated: 1.3.2023
// last change: i-j and i+j tests and inputs
// Version 1.2

#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h>

#include "mc_scverify.h"
#include "matrix_mult.h"

using namespace std;


int print_matrix(data_t A[N][N])
// Prints matrix to standard output
{
  PRINT_I: for(int i=0; i<8; i++) {
      PRINT_J: for(int j=0; j<8; j++) {
          std::cout << std::setfill(' ') << std::setw(12);
          std::cout << A[i][j] << " ";
      }
      std::cout << std::endl;
  }
  std::cout << std::endl;
  return 0;
}

int print_matrix(hls_data_t A[N][N])
// Prints matrix to standard output
{
  PRINT_I: for(int i=0; i<8; i++) {
      PRINT_J: for(int j=0; j<8; j++) {
          std::cout << std::setfill(' ') << std::setw(12);
          std::cout << A[i][j] << " ";
      }
      std::cout << std::endl;
  }
  std::cout << std::endl;
  return 0;
}

int print_matrix(hls_result_t A[N][N])
// Prints matrix to standard output
{
  PRINT_I: for(int i=0; i<8; i++) {
      PRINT_J: for(int j=0; j<8; j++) {
          std::cout << std::setfill(' ') << std::setw(12);
          std::cout << A[i][j] << " ";
      }
      std::cout << std::endl;
  }
  std::cout << std::endl;
  return 0;
}

int check_matrices(data_t A[N][N], hls_data_t A_hls[N][N])
// Check matrix indices for match or mismatch
{
  int match_counter = 0;
  int mismatch_counter = 0;

  std::cout << std::endl;
  std::cout << "Evaluation matrix; 0 for index match, 1 for mismatch" << std::endl;

  for(int i=0; i<8; i++) {
      for(int j=0; j<8; j++) {
        if (A[i][j] == A_hls[i][j]) {
          std::cout << "0" << " ";
          match_counter++;
        }
        if (A[i][j] != A_hls[i][j]) {
          std::cout << "1" << " ";
          mismatch_counter++;
        }
  }
  std::cout << std::endl;
  }

  std::cout << ">> " << match_counter << " match(es) found" << std::endl;
  std::cout << ">> " << mismatch_counter << " mismatch(es) found" << std::endl;
  std::cout << std::endl;

  if (mismatch_counter > 0) {
    return 1;
  }
  else {
    return 0;
  }
}

int check_matrices(data_t A[N][N], hls_result_t A_hls[N][N])
// Check matrix indices for match or mismatch
{
  int match_counter = 0;
  int mismatch_counter = 0;

  std::cout << std::endl;
  std::cout << "Evaluation matrix; 0 for index match, 1 for mismatch" << std::endl;

  CHECK_I_RESULT: for(int i=0; i<8; i++) {
      CHECK_J_RESULT: for(int j=0; j<8; j++) {

        if (A[i][j] == A_hls[i][j]) {
          std::cout << "0" << " ";
          match_counter++;
        }
        if (A[i][j] != A_hls[i][j]) {
          std::cout << "1" << " ";
          mismatch_counter++;
        }
  }
  std::cout << std::endl;
  }

  std::cout << ">> " << match_counter << " match(es) found" << std::endl;
  std::cout << ">> " << mismatch_counter << " mismatch(es) found" << std::endl;
  std::cout << std::endl;

  if (mismatch_counter > 0) {
    return 1;
  }
  else {
    return 0;
  }
}

int check_plus(data_t A[N][N], hls_data_t A_hls[N][N])
{
  int data_value_counter = 0;
  int hls_data_value_counter = 0;

  for(int i=0; i<8; i++) {
    for(int j=0; j<8; j++) {
      data_value_counter += A[i][j];
      hls_data_value_counter += A_hls[i][j];
    }
  }

  std::cout << "i+j results: " << std::endl;
  std::cout << ">> " << data_value_counter << " data matrice result" << std::endl;
  std::cout << ">> " << hls_data_value_counter << " hls matrice result" << std::endl;
  std::cout << std::endl;

  if (data_value_counter != hls_data_value_counter) {
    return 1;
  }
  else {
    return 0;
  }
}

int check_plus(data_t A[N][N], hls_result_t A_hls[N][N])
{
  int data_value_counter = 0;
  int hls_data_value_counter = 0;

  for(int i=0; i<8; i++) {
    for(int j=0; j<8; j++) {
      data_value_counter += A[i][j];
      hls_data_value_counter += A_hls[i][j];
    }
  }

  std::cout << "i+j results: " << std::endl;
  std::cout << ">> " << data_value_counter << " data matrice result" << std::endl;
  std::cout << ">> " << hls_data_value_counter << " hls matrice result" << std::endl;
  std::cout << std::endl;

  if (data_value_counter != hls_data_value_counter) {
    return 1;
  }
  else {
    return 0;
  }
}

int check_minus(data_t A[N][N], hls_result_t A_hls[N][N])
{
  int data_value_counter = 0;
  int hls_data_value_counter = 0;

  for(int i=0; i<8; i++) {
    for(int j=0; j<8; j++) {
      data_value_counter -= A[i][j];
      hls_data_value_counter -= A_hls[i][j];
    }
  }

  std::cout << "i-j results: " << std::endl;
  std::cout << ">> " << data_value_counter << " data matrice result" << std::endl;
  std::cout << ">> " << hls_data_value_counter << " hls matrice result" << std::endl;
  std::cout << std::endl;

  if (data_value_counter != hls_data_value_counter) {
    return 1;
  }
  else {
    return 0;
  }
}

int check_minus(data_t A[N][N], hls_data_t A_hls[N][N])
{
  int data_value_counter = 0;
  int hls_data_value_counter = 0;

  for(int i=0; i<8; i++) {
    for(int j=0; j<8; j++) {
      data_value_counter -= A[i][j];
      hls_data_value_counter -= A_hls[i][j];
    }
  }

  std::cout << "i-j results: " << std::endl;
  std::cout << ">> " << data_value_counter << " data matrice result" << std::endl;
  std::cout << ">> " << hls_data_value_counter << " hls matrice result" << std::endl;
  std::cout << std::endl;

  if (data_value_counter != hls_data_value_counter) {
    return 1;
  }
  else {
    return 0;
  }
}

int fill_matrix_with_zero(data_t A[N][N])
// Fills matrix indices with zeros
{
  FILL_0_I: for(int i=0; i<8; i++) {
      FILL_0_J: for(int j=0; j<8; j++) {
          A[i][j] = 0;
      }
  }
  return 0;
}

int fill_matrix_with_identity_matrix(data_t A[N][N])
{
  FILL_IDENTITY_I: for(int i=0; i<8; i++) {
      FILL_IDENTIY_J: for(int j=0; j<8; j++) {
          A[i][j] = 0;
      }
  }

  FILL_IDENTITY_WITH_1: for(unsigned int t = 0; t < 8; t++)
  {
    A[t][t] = 1;
  }
  return 0;
}

int fill_matrix_with_twos(data_t A[N][N])
{
  FILL2_I: for(int i=0; i<8; i++) {
      FILL2_J: for(int j=0; j<8; j++) {
          A[i][j] = 2;
      }
  }
  return 0;
}

int fill_matrix_with_plus(data_t A[N][N]) {
    for(int i=0; i<8; i++) {
      for(int j=0; j<8; j++) {
          A[i][j] = i+j;
      }
  }
  return 0;
}

int fill_matrix_with_minus(data_t A[N][N]) {
    for(int i=0; i<8; i++) {
      for(int j=0; j<8; j++) {
          A[i][j] = i-j;
      }
  }
  return 0;
}

int fill_matrix_with_min_values(data_t A[N][N])
{
  FILL_MIN_I: for(int i=0; i<8; i++) {
      FILL_MIN_J: for(int j=0; j<8; j++) {
          A[i][j] = -32;
      }
  }
  return 0;
}

int fill_matrix_with_max_values(data_t A[N][N])
{
  FILL_MAX_I: for(int i=0; i<8; i++) {
      FILL_MAX_J: for(int j=0; j<8; j++) {
          A[i][j] = 31;
      }
  }
  return 0;
}

int fill_matrix_with_random(data_t A[N][N])
// Fill matrix indices with random values
{
  srand(time(0)); // Seed value

  FILL_RANDOM_I: for(int i=0; i<8; i++) {
      FILL_RANDOM_J: for(int j=0; j<8; j++) {
          A[i][j] = rand() % (8*8) - 32;
      }
  }
  return 0;
}

int copy_matrix(data_t A[N][N], hls_data_t B[N][N])
// Copies matricies
{
  COPY_I: for (int x=0; x<8 ; x++) {
    COPY_J: for (int y=0; y<8; y++) {
      // A[x][y] = B[x][y];
      B[x][y] = A[x][y];
    }
  }
  return 0;
}

int copy_matrix(data_t A[N][N], hls_result_t B[N][N])
// Copies matricies
{
  COPY2_I: for (int x=0; x<8 ; x++) {
    COPY2_J: for (int y=0; y<8; y++) {
      // A[x][y] = B[x][y];
      B[x][y] = A[x][y];
    }
  }
  return 0;
}

int print_matrix_tests(data_t A[N][N])
{

  std::cout << "Test for print" << std::endl;
  std::cout << "Random matrix:" << std::endl;
  fill_matrix_with_random(A);
  print_matrix(A);

  std::cout << "Matrix with zeroes:" << std::endl;
  fill_matrix_with_zero(A);
  print_matrix(A);

  std::cout << "Matrix with twos:" << std::endl;
  fill_matrix_with_twos(A);
  print_matrix(A);

  std::cout << "Identity Matrix:" << std::endl;
  fill_matrix_with_identity_matrix(A);
  print_matrix(A);

  std::cout << "Matrix with max values" << std::endl;
  fill_matrix_with_max_values(A);
  print_matrix(A);

  std::cout << "Matrix with min values" << std::endl;
  fill_matrix_with_min_values(A);
  print_matrix(A);

  return 0;

}

// Tests for different inputs for design
int test_matrix_mult(data_t A[N][N], hls_data_t A_hls[N][N])
{
  std::cout << "::::::::::::::::::::::::::::::" << std::endl;
  std::cout << "Test for Matrix Multiplication" << std::endl;
  std::cout << "::::::::::::::::::::::::::::::" << std::endl;
  std::cout << "=============================" << std::endl;
  std::cout << "Test starting: .............." << std::endl;
  std::cout << "=============================" << std::endl;

  std::cout << "Matrix 1:" << std::endl;
  std::cout << std::endl;
  print_matrix(A);

  std::cout << std::endl;
  std::cout << "Matrix 2:" << std::endl;
  std::cout << std::endl;
  print_matrix(A_hls);

  int test_output = 2;
  test_output = check_matrices(A, A_hls);

  if (test_output == 0)
  {
    std::cout << "TEST PASSES" << std::endl;
    std::cout << std::endl;
  }
  else {
    std::cout << "TEST FAILS" << std::endl;
    std::cout << std::endl;
  }

  return test_output;
}

int test_matrix_mult(data_t A[N][N], hls_result_t A_hls[N][N])
{
  std::cout << "::::::::::::::::::::::::::::::" << std::endl;
  std::cout << "Test for Matrix Multiplication" << std::endl;
  std::cout << "::::::::::::::::::::::::::::::" << std::endl;
  std::cout << "=============================" << std::endl;
  std::cout << "Test starting: .............." << std::endl;
  std::cout << "=============================" << std::endl;

  std::cout << "Matrix 1:" << std::endl;
  std::cout << std::endl;
  print_matrix(A);

  std::cout << std::endl;
  std::cout << "Matrix 2:" << std::endl;
  std::cout << std::endl;
  print_matrix(A_hls);

  int test_output = 2;
  test_output = check_matrices(A, A_hls);

  if (test_output == 0)
  {
    std::cout << "TEST PASSES" << std::endl;
    std::cout << std::endl;
  }
  else {
    std::cout << "TEST FAILS" << std::endl;
    std::cout << std::endl;
  }

  return test_output;
}

int test_transpose_both(data_t A[N][N], hls_data_t A_hls[N][N])
{
  std::cout << "::::::::::::::::::::::::::::::" << std::endl;
  std::cout << "Test for Matrix Multiplication" << std::endl;
  std::cout << "with both matrices transposed" << std::endl;
  std::cout << "::::::::::::::::::::::::::::::" << std::endl;
  std::cout << "=============================" << std::endl;
  std::cout << "Test starting: .............." << std::endl;
  std::cout << "=============================" << std::endl;

  std::cout << "Matrix 1:" << std::endl;
  std::cout << std::endl;
  print_matrix(A);

  std::cout << std::endl;
  std::cout << "Matrix 2:" << std::endl;
  std::cout << std::endl;
  print_matrix(A_hls);

  int test_output = 2;
  test_output = check_matrices(A, A_hls);

  if (test_output == 0)
  {
    std::cout << "TEST PASSES" << std::endl;
    std::cout << std::endl;
  }
  else {
    std::cout << "TEST FAILS" << std::endl;
    std::cout << std::endl;
  }

  return test_output;
}

int test_transpose_both(data_t A[N][N], hls_result_t A_hls[N][N])
{
  std::cout << "::::::::::::::::::::::::::::::" << std::endl;
  std::cout << "Test for Matrix Multiplication" << std::endl;
  std::cout << "with both matrices transposed" << std::endl;
  std::cout << "::::::::::::::::::::::::::::::" << std::endl;
  std::cout << "=============================" << std::endl;
  std::cout << "Test starting: .............." << std::endl;
  std::cout << "=============================" << std::endl;

  std::cout << "Matrix 1:" << std::endl;
  std::cout << std::endl;
  print_matrix(A);

  std::cout << std::endl;
  std::cout << "Matrix 2:" << std::endl;
  std::cout << std::endl;
  print_matrix(A_hls);

  int test_output = 2;
  test_output = check_matrices(A, A_hls);

  if (test_output == 0)
  {
    std::cout << "TEST PASSES" << std::endl;
    std::cout << std::endl;
  }
  else {
    std::cout << "TEST FAILS" << std::endl;
    std::cout << std::endl;
  }

  return test_output;
}

int test_transpose_a(data_t A[N][N], hls_data_t A_hls[N][N])
{
  std::cout << "::::::::::::::::::::::::::::::" << std::endl;
  std::cout << "Test for Matrix Multiplication" << std::endl;
  std::cout << "with matrix A transposed" << std::endl;
  std::cout << "::::::::::::::::::::::::::::::" << std::endl;
  std::cout << "=============================" << std::endl;
  std::cout << "Test starting: .............." << std::endl;
  std::cout << "=============================" << std::endl;

  std::cout << "Matrix 1:" << std::endl;
  std::cout << std::endl;
  print_matrix(A);

  std::cout << std::endl;
  std::cout << "Matrix 2 (hls):" << std::endl;
  std::cout << std::endl;
  print_matrix(A_hls);

  int test_output = 2;
  test_output = check_matrices(A, A_hls);

  if (test_output == 0)
  {
    std::cout << "TEST PASSES" << std::endl;
    std::cout << std::endl;
  }
  else {
    std::cout << "TEST FAILS" << std::endl;
    std::cout << std::endl;
  }

  return test_output;
}

int test_transpose_a(data_t A[N][N], hls_result_t A_hls[N][N])
{
  std::cout << "::::::::::::::::::::::::::::::" << std::endl;
  std::cout << "Test for Matrix Multiplication" << std::endl;
  std::cout << "with matrix A transposed" << std::endl;
  std::cout << "::::::::::::::::::::::::::::::" << std::endl;
  std::cout << "=============================" << std::endl;
  std::cout << "Test starting: .............." << std::endl;
  std::cout << "=============================" << std::endl;

  std::cout << "Matrix 1:" << std::endl;
  std::cout << std::endl;
  print_matrix(A);

  std::cout << std::endl;
  std::cout << "Matrix 2 (hls):" << std::endl;
  std::cout << std::endl;
  print_matrix(A_hls);

  int test_output = 2;
  test_output = check_matrices(A, A_hls);

  if (test_output == 0)
  {
    std::cout << "TEST PASSES" << std::endl;
    std::cout << std::endl;
  }
  else {
    std::cout << "TEST FAILS" << std::endl;
    std::cout << std::endl;
  }

  return test_output;
}

int test_transpose_b(data_t A[N][N], hls_data_t A_hls[N][N])
{
  std::cout << "::::::::::::::::::::::::::::::" << std::endl;
  std::cout << "Test for Matrix Multiplication" << std::endl;
  std::cout << "with matrix B transposed" << std::endl;
  std::cout << "::::::::::::::::::::::::::::::" << std::endl;
  std::cout << "=============================" << std::endl;
  std::cout << "Test starting: .............." << std::endl;
  std::cout << "=============================" << std::endl;

  std::cout << "Matrix 1:" << std::endl;
  std::cout << std::endl;
  print_matrix(A);

  std::cout << std::endl;
  std::cout << "Matrix 2 (hls):" << std::endl;
  std::cout << std::endl;
  print_matrix(A_hls);

  int test_output = 2;
  test_output = check_matrices(A, A_hls);

  if (test_output == 0)
  {
    std::cout << "TEST PASSES" << std::endl;
    std::cout << std::endl;
  }
  else {
    std::cout << "TEST FAILS" << std::endl;
    std::cout << std::endl;
  }

  return test_output;
}

int test_transpose_b(data_t A[N][N], hls_result_t A_hls[N][N])
{
  std::cout << "::::::::::::::::::::::::::::::" << std::endl;
  std::cout << "Test for Matrix Multiplication" << std::endl;
  std::cout << "with matrix B transposed" << std::endl;
  std::cout << "::::::::::::::::::::::::::::::" << std::endl;
  std::cout << "=============================" << std::endl;
  std::cout << "Test starting: .............." << std::endl;
  std::cout << "=============================" << std::endl;

  std::cout << "Matrix 1:" << std::endl;
  std::cout << std::endl;
  print_matrix(A);

  std::cout << std::endl;
  std::cout << "Matrix 2 (hls):" << std::endl;
  std::cout << std::endl;
  print_matrix(A_hls);

  int test_output = 2;
  test_output = check_matrices(A, A_hls);

  if (test_output == 0)
  {
    std::cout << "TEST PASSES" << std::endl;
    std::cout << std::endl;
  }
  else {
    std::cout << "TEST FAILS" << std::endl;
    std::cout << std::endl;
  }

  return test_output;
}


CCS_MAIN(int argc, char *argv[]) // The Catapult testbench should always be invoked with this macro
{
	// Use this variable as a return value from the testbench (0 indicates passing the testbench, 1 failing it)
	int ret = 0; // Change value to 1 if test fails

  // Initialize return value of tests to failing 
  // (0 == PASS)  (1 == FAIL)  (-1 == UNKNOWN VALUE)
  int ret1 = -1;
  int ret2 = -1;
  int ret3 = -1;
  int ret4 = -1;
  int ret5 = -1;
  int ret6 = -1;
  int ret7 = -1;
  int ret8 = -1;
  int ret9 = -1;
  int ret10 = -1;


	data_t A[N][N];
	data_t B[N][N];
	result_t C[N][N];

	hls_data_t A_hls[N][N];
	hls_data_t B_hls[N][N];
	hls_result_t C_hls[N][N];

  // Open output file named "matrix_mult_output.txt" for writing.
  freopen("matrix_mult_output.txt", "w", stdout);

  // Check data matrix validity
  print_matrix_tests(A);

  // Fill matrices A and B with random values and copy them to
  // A_hls and B_hls
  fill_matrix_with_random(A);
  fill_matrix_with_random(B);
  copy_matrix(A, A_hls);
  copy_matrix(B, B_hls);

  // Test 1
  // for Multiplication, transpose = 0
  // random input in matrices
  matrixMult(A, B, C, 0);
  CCS_DESIGN(matrixMultHLS)(A_hls, B_hls, C_hls, 0);
  std::cout << "Test 1:" << std::endl;
  ret1 = test_matrix_mult(C, C_hls);
  print_matrix(C);
  print_matrix(C_hls);
  ret1 = check_plus(C, C_hls);
  ret1 = check_minus(C, C_hls);

  // Test 2
  // for Transpose both A and B before multiplication, transpose = 3
  matrixMult(A, B, C, 3);
  CCS_DESIGN(matrixMultHLS)(A_hls, B_hls, C_hls, 3);
  std::cout << "Test 2:" << std::endl;
  ret2 = test_transpose_both(C, C_hls);
  ret2 = check_plus(C, C_hls);
  ret2 = check_minus(C, C_hls);

  // Test 3
  // for Transpose B before multiplication, transpose = 2
  matrixMult(A, B, C, 2);
  CCS_DESIGN(matrixMultHLS)(A_hls, B_hls, C_hls, 2);
  std::cout << "Test 3:" << std::endl;
  ret3 = test_transpose_b(C, C_hls);
  ret3 = check_plus(C, C_hls);
  ret3 = check_minus(C, C_hls);

  // Test 4
  // for Transpose A before multiplication, transpose = 1
  matrixMult(A, B, C, 1);
  CCS_DESIGN(matrixMultHLS)(A_hls, B_hls, C_hls, 1);
  std::cout << "Test 4:" << std::endl;
  ret4 = test_transpose_a(C, C_hls);

  // Test 5
  // with constant values in matrices, transpose = 0
  fill_matrix_with_twos(A);
  fill_matrix_with_twos(B);
  copy_matrix(A, A_hls);
  copy_matrix(B, B_hls);

  matrixMult(A, B, C, 0);
  CCS_DESIGN(matrixMultHLS)(A_hls, B_hls, C_hls, 0);

  std::cout << "Test 5:" << std::endl;
  ret5 = test_matrix_mult(C, C_hls);
  ret5 = check_plus(C, C_hls);
  ret5 = check_minus(C, C_hls);

  // Test 6
  // for Transpose both A and B before multiplication, transpose = 3
  // With identity matrices
  fill_matrix_with_identity_matrix(A);
  fill_matrix_with_identity_matrix(B);
  copy_matrix(A, A_hls);
  copy_matrix(B, B_hls);

  matrixMult(A, B, C, 3);
  CCS_DESIGN(matrixMultHLS)(A_hls, B_hls, C_hls, 3);
  std::cout << "Test 6:" << std::endl;
  ret6 = test_transpose_both(C, C_hls);
  ret6 = check_plus(C, C_hls);
  ret6 = check_minus(C, C_hls);

  // Test 7
  // Max values
  // for Transpose both A and B before multiplication, transpose = 3
  fill_matrix_with_max_values(A);
  fill_matrix_with_max_values(B);
  copy_matrix(A, A_hls);
  copy_matrix(B, B_hls);

  matrixMult(A, B, C, 3);
  CCS_DESIGN(matrixMultHLS)(A_hls, B_hls, C_hls, 3);
  std::cout << "Test 7, max values:" << std::endl;
  ret7 = test_transpose_both(C, C_hls);
  ret7 = check_plus(C, C_hls);
  ret7 = check_minus(C, C_hls);

  // Test 8
  // Min values
  // for Transpose both A and B before multiplication, transpose = 3
  fill_matrix_with_min_values(A);
  fill_matrix_with_min_values(B);
  copy_matrix(A, A_hls);
  copy_matrix(B, B_hls);

  matrixMult(A, B, C, 3);
  CCS_DESIGN(matrixMultHLS)(A_hls, B_hls, C_hls, 3);
  std::cout << "Test 8, min values, transpose=3:" << std::endl;
  ret8 = test_transpose_both(C, C_hls);
  ret8 = check_plus(C, C_hls);
  ret8 = check_minus(C, C_hls);

  // Test 9
  // Input with plus values (i+j)
  fill_matrix_with_plus(A);
  fill_matrix_with_plus(B);
  copy_matrix(A, A_hls);
  copy_matrix(B, B_hls);

  matrixMult(A, B, C, 3);
  CCS_DESIGN(matrixMultHLS)(A_hls, B_hls, C_hls, 3);
  std::cout << "Test 9, plus values, transpose=3:" << std::endl;
  ret9 = test_transpose_both(C, C_hls);
  ret9 = check_plus(C, C_hls);
  ret9 = check_minus(C, C_hls);

  // Test 10
  // Input with minus values (i-j)
  fill_matrix_with_minus(A);
  fill_matrix_with_minus(B);
  copy_matrix(A, A_hls);
  copy_matrix(B, B_hls);

  matrixMult(A, B, C, 2);
  CCS_DESIGN(matrixMultHLS)(A_hls, B_hls, C_hls, 2);
  std::cout << "Test 10, plus values, transpose=2:" << std::endl;
  ret10 = test_transpose_both(C, C_hls);
  ret10 = check_plus(C, C_hls);
  ret10 = check_minus(C, C_hls);


  // Test for validity matrices
  // Check for failing tests, sets retun value (ret)
  TEST_VALIDITY: if (ret1 != 0 || ret2 != 0 || ret3 != 0 || ret4 != 0 || ret5 != 0 || ret6 != 0 || ret7 != 0 || ret8 != 0 || ret9 != 0 || ret10 != 0)
  {
    ret = 1;
    std::cout << "Some tests FAIL, return value of the testbench ret = 1" << std::endl;
  }
  else {
    ret = 0;
    std::cout << "All the tests are PASSING" << std::endl;
  }

  std::cout << "return value (ret) is: " << ret << std::endl;

  int WIDTH_test = ac::log2_floor<RANGE>::val;
  int RESULT_WIDTH_test = ((2 * ac::log2_floor<RANGE>::val)) + ac::log2_floor<N>::val;
  int TRANSPOSE_WIDTH = ac::nbits<CONTROL>::val;

  std::cout << std::endl;
  std::cout << "Width is: " <<  WIDTH_test << std::endl;
  std::cout << "Result width is: " << RESULT_WIDTH_test << std::endl;
  std::cout << "Transpose width is: " << TRANSPOSE_WIDTH << std::endl;
  std::cout << std::endl;

/*
	// -Random input values are a good idea in some test, as are corner cases
	// 	* For control reasons, in one test case, the input values should be
	//	  A[i][j] = i+j
	//    B[i][j] = i-j

	// This Catapult macro calls the design and passes the variables to it
	// Do not use this macro for calling the golden reference function
	// CCS_DESIGN(matrixMultHLS)(A_hls, B_hls, C_hls, transpose);

	// TODO:
	// -Print the results of the tests to the "matrix_mult_output.txt" file. Make the file readable and informative!
	// -Close the output file at the end
	// -Give the testbench appropriate return value:
	//  *The testbench should always end with this macro that should return 0 if the design passes the test
	//   and 1 if it fails the test
	// -Comment your testbench!
*/
  
  // Close file writing
  fclose(stdout);

  // Return ret for indicatin failing or passing tests
  CCS_RETURN(ret);

}
