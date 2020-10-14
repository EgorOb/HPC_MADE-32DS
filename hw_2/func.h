#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float *create_rnd_matrix(size_t n);

float *create_zeros_matrix(size_t n);

void matrix_multiplication(float *A, float *B, float *C, size_t n);

void matrix_multiplication_from_vector(float *A, float *B, float *C, size_t n);

void matrix_multiplication_from_cblas(float *A, float *B, float *C, size_t n);

void print_values_matrix(float *matrix, size_t n);

void print_values_vector(float *matrix, size_t n);

void solver_from_matrix(size_t n_size, size_t n_rep, size_t variant);

void solver_from_vector(size_t n_size, size_t n_rep);

