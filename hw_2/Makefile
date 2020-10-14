all:
	gcc -c func.c -g -o func.o
	ar rc dll.a func.o
	gcc main.c dll.a -g -o matr_g.exe -lm -lgslcblas

	gcc -c func.c -O3 -o func.o
	ar rc dll.a func.o
	gcc main.c dll.a -O3 -o matr_O3.exe -lm -lgslcblas
clean:
	rm *.o
	rm *.a
	rm *~
	
