#include <math.h>
#include "func.h"

int main()
{
    size_t variant;
    size_t n_base;
    size_t n_power;
    size_t n_rep;
    size_t size;
    
    // вариант расчёта
    printf("print variant:\n1 - mult matrix to matrix (base)\n2 - mult matrix to matrix (cblas)\n3 - mult matrix to vector\n");
    scanf("%ld", &variant);
    
    // размер базовой матрицы [n;n]
    printf("base size matrix: ");
    scanf("%ld", &n_base);
    
    // сколько раз увеличивать размер матрицы в 2 раза по направлениям
    printf("counts power: ");
    scanf("%ld", &n_power);

    // сколько раз перемножение матриц для среднего времени
    printf("counts reps: ");
    scanf("%ld", &n_rep);

    for (size_t i = 0; i < n_power; i++)
    {
        size = n_base * pow(2.0, i);
        if (variant < 3)
        {
            solver_from_matrix(size, n_rep, variant);
        }
        else
        {
            solver_from_vector(size, n_rep);
        }
    }

    return 0;
}
