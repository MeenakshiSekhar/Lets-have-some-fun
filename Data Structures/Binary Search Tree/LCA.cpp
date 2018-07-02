#include<iostream>

using namespace std;

struct node
{
	int data;
	struct node *left, *right;
};

struct node *newNode(int data)
{
	struct node *temp = new node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node *lca(struct node *root, int n1, int n2)
{
	if(root == NULL)
		return NULL;
	
	if(root->data > n1 && root->data >n2)
		return lca(root->left, n1, n2);
	
	if(root->data > n1 && root->data >n2)
		return lca(root->right, n1, n2);
		
	return root;
}

int main()
{
	struct node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);
    
    cout<<lca(root, 4, 12)->data;
    
    return 0;
}
