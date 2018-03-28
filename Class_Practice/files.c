#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	printf("Input an integer: ");
	int size;
	scanf("%d", &size);
	
	char filename[100];
	printf("What is the name of the file you would like?\n");
	scanf("%s", &filename);
	
	FILE* file = fopen(filename, "w");
	
	fprintf(file, "%d\n", size);
	
	srand(time(NULL));
	
	int i;
	for( i = 0; i < size; i++ )
	{
		fprintf(file, "%d\n", rand() % size);
	}
	
	fclose(file);
	
	return 0;
}
