#include <stdio.h>
#include <math.h>

int main()
{
	double x = 6.64;
	double y = 9.98;

	double theta = atan2(y,x);
	
	printf("Fire at %f radians \n",theta);
	
	return 0;
}
