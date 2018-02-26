#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* new_strdup(char* source);

int main() 
{
	char string[1024];
	printf("Enter a string: ");
	scanf("%s\n", string);
	
	char* duplicate = new_strdup(string);
	int size = strlen(string);
	int i = 0;
	for( i = 0; i < size; i++ )
		if(string[i] >= 'A' && string[i] <= 'Z')
			string[i] += 'a' - 'A';
		else if( string[i] >= 'a' && string[i] <= 'z' )
			string[i] -= 'a' - 'A';
	
	printf("Original: %s\n", duplicate);
	printf("Flipped: %s\n", string);

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
		newString[i] = source[i];

	return newString;

}
