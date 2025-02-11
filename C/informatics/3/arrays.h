#ifndef ARRAYS_H
#define ARRAYS_H
typedef struct vector_int{
	int len;
	int cap;
	int* base;
}VectorInt;

int Expand(VectorInt*, int);
int Reduce(VectorInt*, int);

int LinearSearch(VectorInt, int);
int BinarySearch(VectorInt, int);
VectorInt CreateVector(int);
int Append(VectorInt*, int);
int Insert(VectorInt*, int, int);
int Delete(VectorInt*, int);
void Swap(int*, int*);
void Reverse(VectorInt);
void Task(VectorInt*);
void PrintVec(const VectorInt*);
void HardTask(const VectorInt*);
#endif
