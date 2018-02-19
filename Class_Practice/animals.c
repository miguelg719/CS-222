#include <stdio.h>
#include <string.h>


int main( int argc, char** argv )
{
	if( argc != 2 || argv[1][0] != '-' )
	{
		printf("Usage: animals [ -y | -c | -t ]\n");
	}
	else 
	{
		if( strcmp( argv[1], "-y" ) == 0)
			  printf("Yak\n");
		else if ( strcmp (argv[1], "-c" ) == 0)
			printf("Cormorant\n");
		else if ( strcmp (argv[1], "-t" ) == 0)
			printf("Tasmanian devil\n");
		else 
			printf("Unknown animal\n");
	}
	
	return 0;
}
