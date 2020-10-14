#include "func.h"

size_t point_in_circle(float x, float y)
{
	if (x*x + y*y <= 1)
		return 1;
	return 0;
}

size_t iter(unsigned int * tid)
{
	float x = (float)rand_r(tid) / RAND_MAX;
	float y = (float)rand_r(tid) / RAND_MAX;
	return point_in_circle(x, y);
}

float find_pi(size_t n)
{
	size_t count = 0;
	unsigned int tid;
	srand(time(NULL));
#pragma omp parallel default(none) shared(n, count) private(tid)
	{
		tid = omp_get_thread_num();
#pragma omp for reduction(+:count)	
		for (size_t i = 0; i < n; i++)
		{
			count += iter(&tid);
		}
	}
	return 4.0 * count / n;
}

