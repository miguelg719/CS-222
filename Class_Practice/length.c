#include<stdio.h>

int length( char string[] )
{
	int i = 0;
	while( string[i] != '\0' )
		i++;
		
	return i;
}

void reverse( char string[], int size )
{
	int i = 0;
	
	for( i = 0; i < size/2; i++ )
	{
		char temp = string[i];
		string[i] = string[size - i - 1];
		string[size - i - 1] = temp;
	}

} 

int main()
{
	char text[] = "I like potatoes and cauliflowers";
	int size = length(text);
	printf("The length of \"%s\" is %d\n", text, size);
	
	reverse(text, size);
	printf("Its reverse is \"%s\"\n", text);
	
	return 0;
}
