#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("What file do you want to open?\n");
	char filename[256];
	scanf("%s", &filename);
	
	FILE* file = fopen(filename, "rb");
	int n;
	//fscanf(file, "%d", &n);
	
	fread(&n, sizeof(int), 1, file);
	
	int* array = (int*)malloc(sizeof(int)*n);
	fread(array, sizeof(int), n, file);
	
	int i;
	int sum = 0;
	for( i = 0; i < n; i++ )
	{
		sum += array[i];
	}
	
	free(array);
	
	double average = sum / (double)n;
	
	printf("The average is: %f\n", average);
	
	fclose(file);
	
	return 0;
}
