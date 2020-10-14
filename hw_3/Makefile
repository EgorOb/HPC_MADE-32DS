all:
	gcc -c func.c -O3 -o func.o -fopenmp
	ar rc dll.a func.o
	gcc main.c dll.a -O3 -o pi.exe -fopenmp
	gcc omp_bugparfoc.c -O3 -o omp_bugparfoc.exe -fopenmp
	gcc omp_bugreduction.c -O3 -o omp_bugreduction.exe -fopenmp
clean:
	rm *.o
	rm *.a
	
