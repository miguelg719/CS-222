#include <stdio.h>
#include <string.h>

void backwards(char** argv, int count);

void reverse(char** argv, int count);

void sort(char** argv, int count);

int main(int argc, char** argv)
{
	int i = 1;
	int j = 1;
	
	if(argc > 1 && argv[1][0] == '-')
	{
		while(argv[1][i] != '\0')
		{
			if( argv[1][i] == 'b')
			  backwards(argv, argc);
			else if (argv[1][i] == 'r' )
				reverse(argv, argc);
			else if ( argv[1][i] == 's' )
				sort(argv, argc);
			else 

			printf("Usage: [-(b|r|s)+] sentence");
			
			i++;
		}
	}
	
	for(j = 2; j < argc; j++ )
	{
		printf("%s ", argv[j]);
	
	}
	
	printf("\n");
	
	return 0;
}

void backwards(char** argv, int count)
{
	int i = 0;
	char temp = 0;
	int a = 0;
	
	for(a = 2; a < count; a++)
	{
		int length = strlen(argv[a]);
	
		for ( i = 0; i < length/2 ; i++ )
		{
			temp = argv[a][i];
			argv[a][i] = argv[a][length - 1 - i];
			argv[a][length -1 - i] = temp;
		}
		
	}
}

void reverse(char** argv, int count)
{
	char* temp = argv[2];
	int i = 0;
	
	for( i = 2; i < (count-2)/2+2; i++)
	{
		temp = argv[i];
		argv[i] = argv[ count + 1 - i ];
		argv[ count + 1 - i] = temp;
	} 
}

void sort(char** argv, int count)
{
	int i = 0;
	int j = 0;
	
	for( i = 2; i < count - 1; i++)
		for( j = 2; j < count -1 ; j++ )
		{
			if(strcmp(argv[j], argv[j+1])>0)
			{
				char* temp = argv[j];
				argv[j] = argv[j+1];
				argv[j+1] = temp;
			}
		
		}
	
	
}
