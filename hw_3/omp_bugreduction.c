#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

float dotprod(float * a, float * b, size_t N)
{
    int i, tid;
    float sum = 0.0;
	
#pragma omp parallel shared(a, b, N) private(i, tid)
	{
    tid = omp_get_thread_num();

#pragma omp for schedule(static) reduction(+:sum)
    for (i = 0; i < N; ++i)
    {
        sum += a[i] * b[i];
#pragma omp critical
        {
        printf("tid = %d i = %d\n", tid, i);
        }
    }
	}
    return sum;
}

int main (int argc, char *argv[])
{
    const size_t N = 100;
    int i;
    float a[N], b[N];

#pragma omp parallel shared(a, b, N) private(i)
{
#pragma omp for schedule(static)
    for (i = 0; i < N; ++i)
    {
        a[i] = b[i] = (double)i;
    }
}
    printf("Sum = %f\n", dotprod(a, b, N));

    return 0;
}
