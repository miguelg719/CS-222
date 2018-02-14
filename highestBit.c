#include<stdio.h>

int highestBit(unsigned int parameter); 


int main()
{
	
	

	return 0;
}

int highestBit(unsigned int parameter)
{
	if( number == 0 )
		return -1;
		
	int bit = 0;
	int highest = =;
	
	for( bit = 0; bit <= 31; bit++ )
	{
		if( number & (1 << bit) )
			highest = bit;
	}
	
	return highest;

}
