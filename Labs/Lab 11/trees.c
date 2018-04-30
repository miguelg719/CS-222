#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab11.h"

Contact* addContact(char* name, char* email, int age, Contact* root);
Contact* findContact(char* name, Contact* root);
void printSortedContacts(Contact* root);
void cleanUp(Contact* root);

int main()
{	
	char name[NAME_LENGTH];
	char email[EMAIL_LENGTH];
	int age = 0;
	Contact* root = NULL;
	Contact* found = NULL;
	char choice = '\0';	

	do
	{
		choice = menu();
		switch( choice )
		{
			case 'A': 
				printf("\tEnter name: ");
				readLine(name);
				printf("\tEnter e-mail: ");
				readLine(email);
				printf("\tEnter age: ");
				scanf("%d", &age);
				root = addContact(name, email, age, root);
				break;
			case 'F':
				printf("\tEnter name: ");
				readLine(name);
				found = findContact( name, root );
				if( found == NULL )
					printf("\"%s\" not found\n", name);
				else
					printContact( found );
				break;
			case 'P':
				printSortedContacts( root );
				break;
		}	
	} while( choice != 'Q' );
	
	cleanUp( root );
	root = NULL;

	return 0;
}

char menu()
{  
	int choice;  // input

	// print menu  
	printf("A - Add a contact\n");
	printf("F - Find and display a contact\n");
	printf("P - Print contact list\n");
	printf("Q - Quit\n");
	printf("Your choice: ");

	// Get input
	while( isspace(choice = getchar()) );
	while( getchar() != '\n');

	return toupper(choice);
}

void readLine(char buffer[])
{
	int value = 0;
	int index = 0;
	
	value = getchar();
	while( value != '\n' && value != EOF )
	{
		buffer[index++] = value;
		value = getchar();
	}
	
	buffer[index] = '\0';
}

void printContact(const Contact* contact)
{
	printf("\t%s ", contact->name);
	printf("<%s> ", contact->email);
	printf("is %d years old.\n", contact->age);
}

Contact* addContact(char* name, char* email, int age, Contact* root)
{
	if( root == NULL ) 
	{
		Contact* temp = (Contact*)malloc(sizeof(Contact));
		temp->left = NULL;
		temp->right = NULL;
		temp->name = strdup(name);
		temp->email = strdup(email);
		temp->age = age;
		return temp;
	}
	
	else if( strcmp(name, root->name) <= 0 )
		root->left = addContact(name, email, age, root->left);

	else 
		root->right = addContact(name, email, age, root->right);
	
	return root;		
}

Contact* findContact(char* name, Contact* root)
{
	if( root == NULL ) 
		return NULL;
	
	else if( strcmp(name, root->name) == 0 )
		return root;
	
	else if( strcmp(name, root->name) < 0 ) 
		return findContact(name, root->left);
	
	else
		return findContact(name, root->right);	
}


void printSortedContacts(Contact* root)
{
	if( root != NULL )
	{
		printSortedContacts(root->left);
			
		printContact(root);
		
		printSortedContacts(root->right);
	}
}

void cleanUp(Contact* root)
{
	if( root!= NULL )
	{
		cleanUp(root->left);
		
		free(root->name);
		free(root->email);
		free(root);
		
		cleanUp(root->right);
	}
}
