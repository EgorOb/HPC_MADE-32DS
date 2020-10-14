#include "func.h"

int main(char *argv[])
{
    size_t n = 100000000;

    float start = omp_get_wtime();  
    float pi = find_pi(n);
    float finish = omp_get_wtime();
    
    printf("pi = %f\n", pi); 
    printf("time iter %f sec.\n", finish - start);  
    return 0;
}
