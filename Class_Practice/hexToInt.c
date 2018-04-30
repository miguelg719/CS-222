#include <stdio.h>

int hexToInt(char string[]);

int main()
{
	char* hex = "ABCDEF";
	
	int result = hexToInt(hex);
	
	printf("%d\n", result);
	
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
