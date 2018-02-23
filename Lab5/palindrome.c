#include<stdio.h>

int isPalindrome (char n[], int length);
char lower( char c );

int main()
{

	printf("Enter a string: ");
	
	char c;
	char string[1024];
	int i = 0;	
	int length = 0;


	c = getchar();
	
	while(c != '\n' && c != EOF)
	{
		string[i++] = c;
		c = getchar();		
	}
	string[i] = '\0';
	
	length = i;
	
	if( isPalindrome(string, length) )
		printf("The string \"%s\" is palindrome \n", string);
	else
		printf("The string \"%s\" is not palindrome \n", string);
	
	return 0;
}

int isPalindrome (char n[], int length)
{
	int i;
	
	for( i = 0; i < length/2; i++ )
		if(lower(n[i]) != lower(n[length - 1 - i]))
			return 0;
	
	return 1;
}

char lower( char c )
{
	if( c >= 'A' && c <= 'Z' )
	{
		int difference = 'A' - 'a';
		c -= difference;
	}
	
	return c;
}
