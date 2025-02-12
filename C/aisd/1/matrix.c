#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
#include "input.h"

Matrix* CreateMatrix(void)
{
	int numLines;
	int err = 0;
	do{
		printf("Enter number of lines: ");
		if((err = InputInt32(&numLines)) == 0){
			if(numLines < 0){
				printf("Error: number less than 0\n");
				continue;
			}
			break;
		}
		if(err != ERROR_EOF)	
			printf("Error: not a number\n");
	}while(err != ERROR_EOF);
	
	if(err == ERROR_EOF)
		return NULL;
	Matrix* matrix = (Matrix* ) malloc(sizeof(Matrix));
	if(matrix == NULL){
		printf("Fatal: MATRIX memory was not allocated\n");
		return NULL;
	}
	matrix->numLines = numLines;
	matrix->lines = (Line* ) malloc(sizeof(Line) * numLines);
	if(matrix->lines == NULL){
		printf("Fatal: LINES memory was not allocated\n");
		free(matrix);
		return NULL;
	}
	for(int i = 0; i < numLines; i++){
		int numElems;
		do{
			printf("Enter number of elements in line[%d]: ", i+1);
			if((err = InputInt32(&numElems)) == 0){
				if(numElems < 0){
					printf("Error: number less than 0\n");
					continue;
				}
				break;
			}
			if(err != ERROR_EOF)	
				printf("Error: not a number\n");
		}while(err != ERROR_EOF);
		if(err == ERROR_EOF)
			return NULL;
			
		matrix->lines[i].numElems = numElems;
		matrix->lines[i].elems = (int* ) malloc(sizeof(int) * numElems);
		if(matrix->lines[i].elems == NULL){
			printf("Fatal: LINE[%d] memory was not alocated\n", i);
			for(int k = 0; k < i; k++){
				free(matrix->lines[k].elems);
			}
			free(matrix->lines);
			free(matrix);
			return NULL;
		}
		for(int j = 0; j < numElems; j++){
			int elem;
			do{
				printf("Enter elems[%d]: ", j+1);
				
				if((err = InputInt32(&elem)) == 0)
					break;
				if(err != ERROR_EOF)		
					printf("Error: not a number\n");
			}while(err != ERROR_EOF);
			
			if(err == ERROR_EOF){
				for(int k = 0; k < i; k++){
					free(matrix->lines[k].elems);
				}
				free(matrix->lines);
				free(matrix);
				return NULL;
			}
			
			matrix->lines[i].elems[j] = elem;
		}	
	}	
	return matrix;
}
void 
PrintMatrix(Matrix* matrix)
{
	if(matrix == NULL){
		printf("\nError: null-matrix\n");
		return;
	}
	printf("numLines = %d\n", matrix->numLines);
	for(int i = 0; i < matrix->numLines; i++){
		printf("Line[%d]: ", i);
		for(int j = 0; j < matrix->lines[i].numElems; j++){
			printf("%d ", matrix->lines[i].elems[j]);
		}
		printf("\n");
	}
}
