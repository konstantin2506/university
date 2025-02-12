#ifndef MATRIX_H
#define MATRIX_H

typedef struct Line{
	int numElems;
	int* elems;
}Line;

typedef struct Matrix{
	int numLines;
	Line* lines;
}Matrix;

Matrix* CreateMatrix(void);
void PrintMatrix(Matrix* );
#endif
