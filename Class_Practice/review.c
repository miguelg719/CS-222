#include <stdio.h>

char* median(char* word)
{
	int length = strlen(word);
	int i = 0;
	char* word2 = malloc(length*sizeof(char));
	
	while(length > 0)
	{
		word2[i++] = word[--length];
		word[i] = '\0';
		
		return word2
	}
	
}

int main()
{
	
	return 0;
	
}
