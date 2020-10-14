#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gsl/gsl_cblas.h>

float *create_rnd_matrix(size_t n)
{
    float *matrix = (float*) malloc(n * sizeof(float));
    for (size_t i = 0; i < n; i++)
    {
        matrix[i] = (float)rand() / RAND_MAX;
    }
    return matrix;
}

float *create_zeros_matrix(size_t n)
{
    float *matrix = (float*) malloc(n * sizeof(float));
    for (size_t i = 0; i < n; i++)
    {
        matrix[i] = 0;
    }
    return matrix;
}

void matrix_multiplication(float *A, float *B, float *C, size_t n)
{
    for(size_t k = 0; k < n; k++)
    {
        for(size_t i = 0; i < n; i++)
        {
            for(size_t j = 0; j < n; j++)
                C[i * n + j] += A[i* n + k] * B[k * n + j];
        }
    }
}

void matrix_multiplication_from_vector(float *A, float *B, float *C, size_t n)
{
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < n; j++)
        C[i] += A[i* n + j] * B[j];
    }
}

void matrix_multiplication_from_cblas(float *A, float *B, float *C, size_t n)
{
    cblas_sgemm (CblasRowMajor, CblasNoTrans, CblasNoTrans, 
                 n, n, n,
                 1.0, A, n, B, n, 0.0, C, n);
}


void print_values_matrix(float *matrix, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
            printf("%f ", matrix[i * n + j]);
        printf("\n");
    }
}

void print_values_vector(float *matrix, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%f ", matrix[i]);
    printf("\n");
    }
}

void solver_from_matrix(size_t n_size, size_t n_rep, size_t variant)
{
    srand(time(NULL));
    float start;
    float finish;
    float time_solution = 0.0;
    for (size_t i = 0; i < n_rep; i++)
    {
        float *A = create_rnd_matrix(n_size*n_size);
        float *B = create_rnd_matrix(n_size*n_size);
        float *C = create_zeros_matrix(n_size*n_size);
        start = clock();
        if (variant == 1)
        {
            matrix_multiplication(&A[0], &B[0], &C[0], n_size);
        }
        else
        {
            matrix_multiplication_from_cblas(&A[0], &B[0], &C[0], n_size);
        }
        finish = clock();
        time_solution += (finish - start)/ CLOCKS_PER_SEC;
        printf("time iter %f sec.\n", (finish - start)/ CLOCKS_PER_SEC);
	
        /* //для вывода матриц на экран
        printf("A\n");
        print_values_matrix(A, n_size);
        printf("B\n");
        print_values_matrix(B, n_size);
        printf("C\n");
        print_values_matrix(C, n_size);
        */
        free(A);
        free(B);
        free(C);
    }
    printf("[%ld;%ld] x [%ld;%ld]\nmean time %f sec.\n\n", n_size, n_size, n_size, n_size, time_solution / n_rep);

}

void solver_from_vector(size_t n_size, size_t n_rep)
{
    srand(time(NULL));
    float start;
    float time_solution = 0.0;
    float finish;
    for (size_t i = 0; i < n_rep; i++)
    {
        float *A = create_rnd_matrix(n_size*n_size);
        float *B = create_rnd_matrix(n_size);
        float *C = create_zeros_matrix(n_size);
        start = clock();
        matrix_multiplication_from_vector(&A[0], &B[0], &C[0], n_size);
        finish = clock();
        time_solution += (finish - start)/ CLOCKS_PER_SEC;
        printf("time iter %f sec.\n", (finish - start)/ CLOCKS_PER_SEC);

        free(A);
        free(B);
        free(C);
    }
    printf("[%ld;%ld] x [%ld;1]\nmean time %f sec.\n\n", n_size, n_size, n_size, time_solution / n_rep);
}

