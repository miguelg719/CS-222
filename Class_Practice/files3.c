#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	printf("Input an integer: ");
	int n;
	scanf("%d", &n);
	
	char filename[100];
	printf("What is the name of the file you would like?\n");
	scanf("%s", &filename);
	
	FILE* file = fopen(filename, "wb");
	
	//fprintf(file, "%d\n", n);
	
	fwrite(&n, sizeof(int), 1, file);
	
	srand(time(NULL));
	
	int i;
	for( i = 0; i < n; i++ )
	{
		int number = rand() % 100000;
		fprintf(&number, sizeof(int), 1, file);
	}
	
	fclose(file);
	
	return 0;
}
