#include <stdio.h>
#include <stdlib.h>

void merge(int array1[], int length1, int array2[], int length2, int result[]);

int main()
{
	int length1;
	scanf("%d", &length1);
	int length2;
	scanf("%d", &length2);
	int lengthTot = length1 + length2;
	
	int* array1 = (int*)malloc(sizeof(int)*length1);
	int* array2 = (int*)malloc(sizeof(int)*length2);
	int* result = (int*)malloc(sizeof(int)*lengthTot);
	
	int i = 0;
	for( i = 0; i < length1; i++ )
		scanf("%d", &array1[i]);
	
	for( i = 0; i < length2; i++ )
		scanf("%d", &array2[i]);
			
	merge(array1, length1, array2, length2, result);
	
	printf("List 1: ");
	for(i = 0; i < length1; i++)
		printf("%d ", array1[i]);
	printf("\n");
		
	printf("List 2: ");
	for(i = 0; i < length2; i++)
		printf("%d ", array2[i]);
	printf("\n");
	
	printf("Merged List: ");
	for(i = 0; i < lengthTot; i++)
		printf("%d ", result[i]);
	printf("\n");
	


	return 0;
}

void merge(int array1[], int length1, int array2[], int length2, int result[])
{
	int i, j, k;
	j = 0;
	k = 0;
	int lengthTot = length1 + length2;
	
	for( i = 0; i < lengthTot; i++ )
	{
		if( j >= length1 )
			result[i] = array2[k++];
				
		else if( k >= length2 )
			result[i] = array1[j++];
		
		else if(array1[j] > array2[k])
			result[i] = array2[k++];
		
		else 
			result[i] = array1[j++];
		
	}

}
