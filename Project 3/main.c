#include <stdio.h>
#include "new_string.h"
#include <string.h>
#include <stdlib.h>

int main()
{
	const char* str1 = "hello";
	char* str2 = "wonderful";
	char* str3 = "hellowo";

	int size = new_strlen(str2);
	printf("%d\n", size);
	
	//char* string = "Ahn";
	//char* value = strcat(string, str1);
	//printf("%s",value);

	return 0;
}
