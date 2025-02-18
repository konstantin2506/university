#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
#include "input.h"

Matrix* 
CreateMatrix(void)
{
	int numLines = 0;
	int err = 0;
	do{
		printf("Enter number of lines: ");
		if((err = InputInt32(&numLines)) == 0){
			if(numLines < 0){
				fprintf(stderr, "Error: number less than 0\n");
				continue;
			}
			break;
		}
		if(err != ERROR_EOF)	
			fprintf(stderr, "Error: not a number\n");
	}while(err != ERROR_EOF);
	
	if(err == ERROR_EOF)
		return NULL;
	Matrix* matrix = (Matrix* ) malloc(sizeof(Matrix));
	if(matrix == NULL){
		fprintf(stderr, "Fatal: MATRIX memory was not allocated\n");
		return NULL;
	}
	matrix->numLines = numLines;
	matrix->lines = (Line* ) calloc(sizeof(Line) * numLines, sizeof(Line));						//////////
	if(matrix->lines == NULL){
		fprintf(stderr, "Fatal: LINES memory was not allocated\n");
		DeleteMatrix(matrix);
		return NULL;
	}
	for(int i = 0; i < numLines; i++){
		int numElems = 0;
		matrix->lines[i].numElems = 0;
		do{
			printf("Enter number of elements in line[%d]: ", i+1);
			if((err = InputInt32(&numElems)) == 0){
				if(numElems < 0){
					fprintf(stderr, "Error: number less than 0\n");
					continue;
				}
				break;
			}
			if(err != ERROR_EOF)	
				fprintf(stderr, "Error: not a number\n");
		}while(err != ERROR_EOF);
		
		matrix->lines[i].numElems = numElems;
		matrix->lines[i].elems = (int* ) malloc(sizeof(int) * numElems);
		if(matrix->lines[i].elems == NULL){
			fprintf(stderr, "Fatal: LINE[%d] memory was not alocated\n", i);
			DeleteMatrix(matrix);
			return NULL;
		}
		if(err == ERROR_EOF){
			DeleteMatrix(matrix);
			return NULL;
		}
		
		for(int j = 0; j < numElems; j++){
			int elem;
			do{
				printf("Enter elems[%d]: ", j+1);
				
				if((err = InputInt32(&elem)) == 0)
					break;
				if(err != ERROR_EOF)		
					fprintf(stderr, "Error: not a number\n");
			}while(err != ERROR_EOF);
			
			if(err == ERROR_EOF){
				DeleteMatrix(matrix);
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
		fprintf(stderr,"Error: null-matrix\n");
		return;
	}
	printf("numLines = %d\n", matrix->numLines);
	for(int i = 0; i < matrix->numLines; i++){
		printf("Line[%d]: ", i+1);
		for(int j = 0; j < matrix->lines[i].numElems; j++){
			printf("%d ", matrix->lines[i].elems[j]);
		}
		printf("\n");
	}
}

void
DeleteMatrix(Matrix* matrix)
{
	if(matrix == NULL)
		return;
	if(matrix->lines != NULL){	
		for(int i = 0; i < matrix->numLines; i++){
			if(matrix->lines[i].elems != NULL)
				free(matrix->lines[i].elems);
		}
		free(matrix->lines);
	}
	free(matrix);
}
