#include <stdio.h>

#include "arrays.h"
#include "input.h"
#include <stdlib.h>
void
Info(void)
{
	printf("Command list:\n \
	1.Initialize vector\n \
	2.Insert element\n \
	3.Delete element\n \
	4.INDIVIDUAL TASK\n \
	5.Print vector\n \
	6.Expand capacity\n \
	7.Reduce capacity\n \
	8.Finish\n \
	9.Hard task\n");
}
int 
GetValue(int* x)
{
	int err = 0;
	while((err = InputInt32(x)) != 0){
		if(err == ERROR_EOF){
			return 1;
		}
	}
	return 0;
}
int
main(void)
{
	VectorInt vec;
	vec.base = NULL;
	while(1){
		Info();
		int ans, inx, val, n, cap;
		if(GetValue(&ans) != 0)
			return 0;
		
		switch(ans){
		default:
			printf("Incorrect answer\n");
			break;
		case 1:
			if(vec.base != NULL)
				free(vec.base);
			printf("Capacity: ");
			if(GetValue(&cap) != 0){
				free(vec.base);
				return 0;
			}
			if(cap <= 0)
				break;
			vec = CreateVector(cap);
			for(int i = 0;i < cap; ++i){
				int n = 0;
				if(GetValue(&n) != 0){
					free(vec.base);
					return 0;
				}
				Append(&vec, n);
			}
			break;
		case 2:
			printf("Value: ");

			if(GetValue(&val) != 0){
				free(vec.base);
				return 0;
			}
			printf("Insert index: ");
			if(GetValue(&inx) != 0){
				free(vec.base);
				return 0;
			}
			if(Insert(&vec, val, inx) != 0)
				printf("Error: memory\n");
			break;
		case 3:
			printf("Delete index: ");
			if(GetValue(&inx) != 0){
				free(vec.base);
				return 0;
			}
			if(Delete(&vec, inx) != 0){
				printf("Error: memory\n");
			}
			break;
		case 4:
			Task(&vec);
			break;
		case 5:
			PrintVec(&vec);
			break;
		case 6:
			printf("New capacity will be calculated as\n---->new = old + n\nn:");
			if(GetValue(&n) != 0){
				free(vec.base);
				return 0;
			}
			if(Expand(&vec, n) != 0)
				printf("Error\n");
			break;
		case 7:
			printf("New capacity will be calculated as\n---->new = old - n\nn:");
			if(GetValue(&n) != 0){
				free(vec.base);
				return 0;
			}
			if(Reduce(&vec, n) != 0)
				printf("Error\n");
			break;
		case 8:
			if(vec.base != NULL)
				free(vec.base);
			return 0;
		case 9:
			HardTask(&vec);
			break;	
		}
		
	}
	if(vec.base != NULL)
		free(vec.base);
	return 0;
}
