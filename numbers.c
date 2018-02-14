#include <stdio.h>

int readInt()
{
	int c = 0;
	int total = 0;
	while( (c = getchar()) != EOF && c != '\n' )
	{
		if ( c>= '0' && c<= '9')
			total = total * 10 + (c - '0');
	}
	
	return total;
}

void selectionSort(int array[], int size)
{
	int i = 0;
	int small = i;
	for( i = 0; i < size; i++)
	{
		int j = 0;
		int small = i;
		for( j = i + 1 ; j < size; j++ )
			if ( array[i] < array[small] )
				small = i;
				
		int temp = array[i];
		array[i] = array[small];
		array[small] = temp;	
	
	}

}

int main()
{
	int values[100];
	int size = 0;
	
	do
	{
		printf("Please input an integer (0-100): ");
		size = readInt();
	} while( size > 100 );
	
	printf("Enter %d positive integers:\n", size);
	
	int i = 0;
	for( i = 0; i < size; i++ )
		values[i] = readInt();
		
	int max = values[0];
	int min = values[0];
	double mean = values[0];
	
	for( i = 1; i< size; i++ )
	{
		if( max < values[i] )
			max = values[i];
		
		if( min > values[i] )
			min = values[i];
			
		mean += values[i];
	}
	
	mean = mean / size;
	
	
	double variance = 0;
	
	for( i = 0; i < size ; i++ )
		variance += (values[i] - mean)*(values[i] - mean);
		
	variance /= (size - 1);
	
	selectionSort( values, size );
	
	double median;
	
	if( size % 2 == 0 )
		median = .5*(values[size/2] + values[size/2-1]);
	else
		median = (values[size/2]);
	
	
	
	printf("Maximum: %d\n", max);
	printf("Minimum: %d\n", min);
	printf("Mean: %f\n", mean);	
	printf("Variance: %f\n", variance);
	printf("Median: %f\n", median);
	
	
	return 0;
}
