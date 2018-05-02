#include <stdio.h>

int hexToInt(char string[]);
void intToHex(int number, char hex[]);


// check the functions for this program


int main()
{
	char* hex = "ABCDEF";
	
	int result = hexToInt(hex);
	
	int number = 13825;
	char* res = "";
	intToHex(number, res);
	
	printf("%d\n", result);
	printf("%s\n", res);
	
	return 0;
}

int hexToInt(char string[])
{
	int sum = 0;
	int i = 0;
	while( string[i] != '\0' )
	{
		sum *= 16;
		if(string[i] >= '0' && string[i] <= '9')
			sum += string[i]-'0';
		
		else if(string[i] >= 'A' && string[i] <= 'F')
			sum += (string[i] - 'A') + 10;
		
		i++;
	}
	
	return sum;
}

void intToHex(int number, char hex[])
{
	int i = 0;
	char c;
	
	do
	{
		c = number % 16;
		if(c >= '0' && c <= '9')
			c += '0';
		else 
			c += 'a' - 10;
		
		hex[i] = c;
		
		i++;
		number /= 16;
	} while(number > 0);
	
	int j;
	for( j = 0; j < i/2; ++j )
	{
		char temp = hex[j];
		hex[j] = hex[i - j - 1];
		hex[i - j - 1] = temp;		
	}	
	
}
