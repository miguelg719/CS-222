#include <stdio.h>
#include <stdlib.h>

char* new_strdup(char* source);

int main() 
{
	char* array = NULL;
	unsigned long size = 10;
	
	do
	{
		printf("Size: %lu\n", size);
		
		array = (char*)malloc(sizeof(char)*size);
		if( array != NULL)
		{
			array[0] = 'a';
			free(array);
			
			size *= 10;
		}
		
		//getchar();
		
	} while (array != NULL);
	
	printf("Size that's too big %lu\n", size);

	return 0;
}

char* new_strdup(char* source)
{
	int size = 0;
	while ( source[size] != '\0' )
		size++;
	
	char* newString = (char*)malloc(sizeof(char)*(size+1));
	int i = 0;
	
	for( i = 0; i <= size; ++i ) // goes >= to address the null char
	{
		newString[i] = source[i];
		
	}

}
