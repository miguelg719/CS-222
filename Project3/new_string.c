/*******************************
*
*  Project Name: Project 3
*  Description: An implementation of several
*				string.h library files
*  File names: new_string.h main.c
*  Date: 3/2/2018   
*  Authors: Miguel Gonzalez
*			Ahn Nguyen
*
********************************/

#include "new_string.h"

// Finds the length of a given string
size_t new_strlen( const char* string )
{
	size_t size = 0;
	while( string[size] != '\0' )
		size++;
	
	return size;
}

// Copies the string from source into destination
char* new_strcpy( char* destination, const char* source )
{
	size_t size = 0;
	while( destination[size] != '\0' )
		size++;
		
	int i = 0;
   	for ( i = 0; i < size && source[i] != '\0'; i++ )
		destination[i] = source[i];
  	for (  ; i < size; i++ )
       		destination[i] = '\0';

	return destination;
}

// Copies the string from source into destination until the n element of source
char* new_strncpy( char* destination, const char* source, size_t n )
{
	size_t i;

	for ( i = 0; i < n && source[i] != '\0'; i++ )
	   destination[i] = source[i];
	for (  ; i < n; i++ )
	   destination[i] = '\0';

	return destination;
}

// Compares two given strings and returns -1 if the second string is alphabetically 
//	larger than the first, if the second one is larger it returns 1, and 0 if equal
int new_strcmp( const char* string1, const char* string2 )	
{
	int i = 0;
	while( (string1[i] != '\0') || (string2[i] != '\0') )
	{
		if( string1[i] < string2[i] )
			return 1;
		else if( string1[i] > string2[i] )
			return -1;
		else 
			return 0;
			
		i++;
	}
}
//
// Same as new_strcmp until the nth character
int new_strncmp( const char* string1, const char* string2, size_t n )
{
	for ( ; n > 0; n -= 1 ) 
	{
		if ( *string1 != *string2 ) 
		{
			if ( *string1 > *string2 ) 
				return 1;
			else 
				return -1;
		}
		if ( *string1++ == 0 ) 
			return 0;
		
		*string2++;
	}
    return 0;
}
//
// Concatenates source into destination (without null terminating character)
char* new_strcat( char* destination, const char* source )
{
	size_t length = new_strlen(destination);
	int i = 0;
	
	for( i = 0; source[i] != '\0'; i++ )
		destination[length+i] = source[i];
		destination[length+i] = '\0';
	
	return destination;	
}
//
// Same as new_strcat until the nth character of source
char* new_strncat( char* destination, const char* source, size_t n )
{
	size_t length = new_strlen(destination);
	int i;

	for ( i = 0 ; i < n && source[i] != '\0' ; i++ )
		destination[length + i] = source[i];
		destination[length + i] = '\0';

	return destination;
}
//
//finding the the string have the specific character 
char* new_strchr(const char* string, int character)
{
    for (  ; *string != '\0'; ++string )
    {
      if ( *string == character )
        return (char*) string;
    }
    return NULL;
}

//
// finding if characters in the neddle  matching the characters in the haystack 
char* new_strstr(const char* haystack, const char* needle)
{
	int i,j;
	for(i = 0; haystack[i] != '\0'; i++)
	{
		for(j = 0 ; needle[j] !='\0' && needle[j] == haystack[i+j]; j++);
		if( needle[j] == '\0')
			return (char*)&haystack[i];
	}	
	return NULL;
}
