#include<stdio.h>

int highestBit(unsigned int parameter); 


int main()
{
	int number = sizeof(3)U;
	
	int highest = highestBit(number);
	
	printf("%d/n", highest);

	return 0;
}

int highestBit(unsigned int parameter)
{
	if( parameter == 0 )
		return -1;
		
	int bit = 0;
	int highest = 0;
	
	for( bit = 0; bit <= 31; bit++ )
	{
		if( parameter & (1 << bit) )
			highest = bit;
	}
	
	return highest;

}
