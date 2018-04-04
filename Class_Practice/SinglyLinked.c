#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node* next;
} node;

void add( node** headPointer, int value );
node* find( node* headPointer, int value );
void Remove( node** headPointer, int value );
void insert( node** headPointer, int value );
void empty( node* head );

int main()
{
  node* head = NULL;
  add(&head, 5);
  add( &head, 7 );
  add( &head, 8 );
  head = find( head, 7 );
  printf("%d\n", head->data);

	return 0;
}

void add( node** headPointer, int value )
{
  node* head = *headPointer;

  node* box = (node*)malloc(sizeof(node));
  box->data = value;
  box->next = head;
  *headPointer = box;

}

node* find( node* headPointer, int value )
{
  node* head = headPointer;

  if( head->data == value )
    return head;

  while( head != NULL )
  {
    if( head->data == value )
      return head;

    head = head->next;
  }

  return NULL;

}

void Remove( node** headPointer, int value )
{
	node* head = *headPointer;

	if( head == NULL )
		return;

	if( head->data == value )
	{
		*headPointer = head->next;
		free( head );
	}

	while( head->next != NULL )
	{
		if( head->next->data == value )
		{
			node* temp = head->next;
			head->next = head->next->next;
			free( temp );
			return;
		}

		head = head->next;
	}
}

void insert( node** headPointer, int value )
{
	node* head = *headPointer;

	if( (head == NULL) || (value < head->data) )
	{
		node* box = (node*)malloc(sizeof(node));
		box->data = value;
		box->next = head;
		*headPointer = box;
	}

	while( (head->next != NULL) && (head->next->data < value) )
		head = head->next;

		node* box = (node*)malloc(sizeof(node));
		box->data = value;
		box->next = head->next;
		head->next = box;
		return;
}

void empty( node* head )
{
	while( head != NULL )
	{
		node* temp = (node*)malloc(sizeof(node));
		temp = head;
		head = head->next;
		free(temp);
	}
}
