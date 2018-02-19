#include <stdio.h>

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

long long factorial(int n)
{
	
	if (n == 0 || n == 1)
		return 1;
		
	else
		return factorial(n - 1)* n; 

}

int main()
{
	int number = readInt();
	
	if( 0 <= number && number <= 20)
	{
		int i, j = 0;
		
		for( i = 0; i<number; i++ )
		{
			for( j = 0; j <= i; j++)
				printf("%lld " , factorial(i)/(factorial( i - j ) * factorial(j)));
		
			printf("\n");
		}
	
	}
	else
		printf("Invalid input \n");

	return 0;
}
