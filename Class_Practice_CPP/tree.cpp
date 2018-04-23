#include <iostream>

using namespace std;

struct TreeNode
{
	int value;
	TreeNode* left;
	TreeNode* right;
};

void insert(TreeNode* &root, int data)
{
	if( root == NULL )
	{
		root = new TreeNode();
		root->value = data;
		root->right = NULL;
		root->left = NULL;
	}
	
	else if( data < root->value )
		insert(root->left, data);
		
	else if( data > root->value )
		insert(root->right, data);
}

void inorder(TreeNode* root)
{
	if( root != NULL )
	{
		inorder(root->left);
		cout << root->value << endl;
		inorder(root->right);
	}
}

void cleanup(TreeNode* &root)
{
	if( root != NULL )
	{
		cleanup(root->left);
		cleanup(root->right);
		delete root;
		root = NULL;
	}
}

int main()
{
	TreeNode* root = NULL;	
	
	int numbers;
	cout << "How many numbers would you like?  ";
	cin >> numbers;
	
	for( int i = 0; i < numbers; i++ )
	{
		int add;
		cout << "Number " << i+1 << ": ";
		cin >> add;
		insert(root, add);
	}
	
	cout << "Values in the tree: " << endl;
	inorder(root);
	cleanup(root);
	
	return 0;
}
