#include <stdio.h>
#include <stdlib.h>

void addFront( node** headPointer, node** tailPointer, int value );
void addBack( node** headPointer, node** tailPointer, int value );

typedef struct _node
{
	int data;
	struct _node* next;
	struct _node* previous;
}  node;

int main()
{
	
	return 0;
}

void addFront( node** headPointer, node** tailPointer, int value )
{
	node* box = (node*)malloc(sizeof(node));
	box->data = value;
	box->previous = NULL;
	box->next = *headPointer;	
	*headPointer = box;
	
	if( box->next == NULL )
		*tailPointer = box;
}

void addBack( node** headPointer, node** tailPointer, int value )
{
	node* box = (node*)malloc(sizeof(node));
	box->data = value;
	box->previous = *tailPointer;
	box->next = NULL;	
	*tailPointer = box;
	
	if( box->previous == NULL )
		*headPointer = box;
}
