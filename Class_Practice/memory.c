#include <stdio.h>
#include <stdlib.h>

//void allocate();

int main()
{
	printf("Enter size of list: ");
	int size;
	scanf("%d", &size);
	
	int* array = malloc(sizeof(int)*size);
	
	int i = 0;
	for( i = 0; i < size; i++ )
	{
		printf("Enter element %d: ", i+1 );	
		scanf("%d", &array[i]);
	}
	
	for( i = 0; i < size-1; i++)
	{
		int small = i;
		int j = 0;
		for(j = i+1; j < size; j++)
		{
			if( array[j] < array[small] )
				small = j;
		}
		
		int temp = array[small];
		array[small] = array[i];
		array[i] = temp;
	}	
	
	
	
	printf("Here are those numbers sorted, sir or madam: ");
	for( i = 0; i < size-1; i++ )
	{
		printf("%d, ",array[i]);
	}
	printf("%d\n",array[size-1]);
	
	free(array);
	array = NULL;

	return 0;
}

/*void allocate()
{
	char* buffer;
	
	while( 1 )
	{
		buffer = malloc(1024);
		buffer[0] = 'a';
	}
	
	printf("You'll never see this\n");

}*/
