#ifndef INPUT_H
#define INPUT_H

int InputInt(long*, int);
int InputInt8(char*);
int InputInt16(short*);
int InputInt32(int*);
int InputInt64(long*);

int IsDigit(char);
void ClearBuffer(void);
long Pow(int,int);



#define ERROR_TYPE        1
#define ERROR_RANGE       2
#define ERROR_EOF         3
#define ERROR_SIZE        4
#define ERROR_EMPTY_INPUT 5

#endif
