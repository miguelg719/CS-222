#include <stdio.h>
#include <stdlib.h>

typedef struct _node 
{
	int data;
	struct _node* next;
} LinkNode;

//adds value to the head of the list
//returns new head
LinkNode* add(LinkNode* head, int value);

//delete first occurrence of value from the list
//returns new head
LinkNode* delete(LinkNode* head, int value);

//print all the values in the list
void print(LinkNode* head);

//free all the memory in the list
void empty(LinkNode* head);

int main()
{	
	int response;
	LinkNode *head = NULL;
	
	while( response != 4 )
	{
		printf("1. Add new element\n");
		printf("2. Delete element\n");
		printf("3. Print list\n");
		printf("4. Exit\n");
		
		scanf("%d", &response);
	
		if( response == 1 )
		{
			int num;
			scanf("%d", &num);
			head = add( head, num );
		}
		else if( response == 2 )
		{
			int num;
			scanf("%d", &num);
			head = delete( head, num );
		}
		else if( response == 3 )
		{
			print( head );
		}
		else if( response == 4 )
		{
			empty( head );
		}
		else
			printf( "Provide a correct input\n" );
	}
	
	
	return 0;
}

LinkNode* add(LinkNode* head, int value)
{
	LinkNode* newNode = (LinkNode*)malloc(sizeof(LinkNode));
	
	newNode->data = value;
	
	newNode->next = head;
	head = newNode;
	
	return head;
}

LinkNode* delete(LinkNode* head, int value)
{
	LinkNode* temp, *pointer;
	
	if( head == NULL ) 
		return head;
	
	else if( head->data == value )
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	else
	{
		pointer = head;
		
		while( pointer->next != NULL )
		{
			if( pointer->next->data != value )
				pointer = pointer->next;
			
			else
			{
				temp = pointer->next;
				pointer->next = temp->next;
				free(temp);
				return head;
			}
		} 
	}
	
	return head;
}
void print(LinkNode* head)
{
	if( head == NULL )
	{
		printf("The list is empty\n");
		return;
	}
	while( head != NULL )
	{
		printf("%d ", head->data);
		head = head->next;
	}
	
	printf("\n");
}

void empty(LinkNode* head)
{
	LinkNode* temp;
	
	while( head != NULL )
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
