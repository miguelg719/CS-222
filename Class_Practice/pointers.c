#include<stdio.h>

int main()
{
	int value = 7;
	int* pointer = &value;
	printf("0x%X\n", pointer);
	*pointer = 55;
	printf("%d\n", value);
	
	return 0;
}
