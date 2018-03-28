#include <stdio.h>

typedef struct _Tree
{
	int data;
	struct _Tree* left;
	struct _Tree* right;
} Tree;

Tree* find( Tree* root, int value );
Tree* add( Tree* root, int value );

int main()
{
	
	
	return 0;
}

Tree* find( Tree* root, int value )
{
	if( root == NULL )
		return root;
	
	else if( root->data == value )
		return root;
		
	else if( value < root->data )
		return find(root->left, value);
	
	else
		return find(root->right, value);		
	
}

Tree* add( Tree* root, int value )
{
	if( root == NULL )
	{
		Tree* temp = (Tree*)malloc(sizeof(Tree));
		temp->left == NULL;
		temp->right == NULL;
		temp->data = value;
		return temp;
	}
	
	else if( value < root->data )
		root->left = add(root->lef, value);
	
	else if( value > root->data )
		root->right = add(root->right, value);
		
	return root;
}
