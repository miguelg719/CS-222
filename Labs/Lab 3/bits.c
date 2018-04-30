#include<stdio.h>

/**
 * Function: 	readInt
 * Returns: 	an int, read from standard input. 
 **/
int readInt()
{
	int c = 0;
	int i = 0;
  
	while( (c = getchar()) != EOF && c != '\n' )
	{
		if( c >= '0' && c <= '9')	
			i = i * 10 + (c - '0');	
	}

	return i;
}

// main function
int main()
{
	int value = 0;
	printf("Please enter an integer: ");
	value = readInt();
	
	printf("Would you like to set, unset, or flip a bit? (s, u, f): ");
	char action = getchar();
	char n = getchar();
	
	printf("Which bit? (0-31): ");
	int bit = readInt();
	int one = 1;
	
	int result;
	
	if(action == 's')
	{
		result = ((one << bit)| value);
		printf("The result of setting bit %d in %d is %d\n", bit, value, result);
	}
	
	else 
		if(action == 'u')
		{
			result = ((~(one << bit))& value);
			printf("The result of unsetting bit %d in %d is %d\n", bit, value, result);
		}
		
		else 
			if(action == 'f')
			{
				result = ((one << bit)^ value);	
				printf("The result of flipping bit %d in %d is %d\n", bit, value, result);
			}
	
			else 
				printf("Input a correct action \n");
	
	return 0;
}
