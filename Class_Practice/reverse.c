#include <stdio.h>

void reverse ( int n[], int size );
void print ( int n[], int size );

int main()
{
	int value [100];
	int i;
	
	for(i = 0; i < 100 ; i++)
		value [i] = i + 1;
		
	print( value , 100 );
	printf("\n");
	reverse( value, 100 ); 
	print( value , 100 );

	return 0;
}

void reverse ( int n[] , int size )
{
	int i;
	
	for ( i = 0; i < size/2 ; i++ )
	{
		int temp = n[i];
		n[i] = n[size - i - 1];
		n[size - i - 1] = temp;
	}
}

void print ( int n[], int size )
{
	int i = 0;
	for ( i = 0; i < size; i++ )
	{
		if( n[i] == 100 && n[i-1] == 99 || (n[i] == 1 && n[i+1] != 2))
			printf("%d", n[i]);
		else
			printf("%d,", n[i]);
	}	
	printf("\n");

}
