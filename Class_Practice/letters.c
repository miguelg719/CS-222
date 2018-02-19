#include <stdio.h>
#include <string.h>


void makeLower (char* letter);

int main()
{	
	char word[] = "Emacs is great";
	
	int length = strlen(word);
	int i;
	for( i = 0; i < length; i++ )
		makeLower(&word[i]);
		
	printf("\"%s\"\n", word);
		
	return 0;
}

void makeLower(char* letter)
{
	if( *letter >= 'A' && *letter <= 'Z' )
		*letter += 'a' - 'A';
}
