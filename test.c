#include<stdio.h>

int main()
{
	char letters[5];
	int i;
	for( i = 0; i < 5; i++)
	{
		letters[i]='A';
	}
	
	printf("The word of the week is \"%s\".\n", letters);
	
	return 0;
}
