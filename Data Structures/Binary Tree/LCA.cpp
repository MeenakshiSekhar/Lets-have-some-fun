#include<iostream>

using namespace std;

struct node
{
	int data;
	struct node *left, *right;
};

struct node *newnode(int data)
{
	struct node *temp = new node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node* lca(struct node *root, int d1, int d2)
{
	if(root == NULL)
		return NULL;
	if(root->data == d1 || root->data == d2)
		return root;
		
	struct node* lca_left = lca(root->left, d1, d2);
	struct node* lca_right = lca(root->right, d1, d2);
	
	if(lca_left && lca_right)
		return root;
	
	return (lca_left != NULL) ? lca_left : lca_right;
}

int main()
{
	struct node *root = NULL;
	root = newnode(10);
	root->left = newnode(5);
	root->right = newnode(15);
	root->left->left = newnode(3);
	root->left->left->left = newnode(1);
	root->left->right = newnode(33);
	root->right->left = newnode(45);
	root->right->right = newnode(25);
	
	cout<<lca(root, 15,25)->data;
	
	return 0;
}
