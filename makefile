main.c: MatrixOperations.h
	gcc -o "main" main.c

MatrixOperations.h: AllocateMemory.h
	gcc -o "MatrixOperations" MatrixOperations.h

AllocateMemory.h:
	gcc -o "AllocateMemory" AllocateMemory.h







