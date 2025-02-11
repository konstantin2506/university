#ifndef INPUT_H
#define INPUT_H

char InputInt(long*, char);
char InputInt8(char*);
char InputInt16(short*);
char InputInt32(int*);
char InputInt64(long*);

char IsDigit(char);
void ClearBuffer(void);
long Pow(int,int);



#define ERROR_TYPE        1
#define ERROR_RANGE       2
#define ERROR_EOF         3
#define ERROR_SIZE        4
#define ERROR_EMPTY_INPUT 5

#endif
