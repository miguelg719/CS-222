#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("What file do you want to open?\n");
	char filename[100];
	scanf("%s", &filename);
	
	FILE* file = fopen(filename, "r");
	int total;
	fscanf(file, "%d", &total);
	
	int i;
	int sum = 0;
	for( i = 0; i < total; i++ )
	{
		int number;
		fscanf(file, "%d", &number);
		sum += number;
	}
	
	double average = sum / (double)total;
	
	printf("The average is: %f\n", average);
	
	fclose(file);
	
	return 0;
}
