// Watch itoa() and atoi() for the test!!

#include <stdio.h>

int atoi(char* number);
char* itoa(int number, char* string);

int main()
{
	char text[12];
	itoa(-4981, text);
	
	printf("%s\n", text);
	
	return 0;
}

int atoi(char* number)
{
	int i = 0;
	int result;
	int sign = 1;
	
	if( number[0] == '-' )
	{
		sign = -1;
		i = 1;
	}
	
	while( number[i] != '\0' )
	{
		result = result * 10 + number[i] - '0';
		i++;
	}
		
	return sign * result;
}

char* itoa(int number, char* string)
{
	int i = 0;	
	int negative = 0;
	
	if( number < 0 )
	{
		number *= -1;
		negative = 1;
	}

	while( number != 0 )
	{
		int digit = number % 10;
		number /= 10;
		string[i] = digit + '0';
		i++;
	}
	
	if( negative )
	{
		string[i] = '-';
		i++;
	}
	
	string[i] = '\0';

	int j = 0;
	for( j = 0; j < i/2; j++ )
	{
		char temp = string[j];
		string[j] = string[i - j - 1];
		string[ i - j - 1 ] = temp;
	}
	
	return string;
}
