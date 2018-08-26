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

void mirror(struct node *root)
{
	if(root == NULL)
		return;
	mirror(root->left);
	mirror(root->right);
	
	struct node *temp = root->left;
	root->left = root->right;
	root->right = temp;
}

void print(struct node *root)
{
	if(root == NULL)
	return;
	
	print(root->left);
	cout<<root->data<<"  ";
	print(root->right);
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
	mirror(root);
	print(root);
	
}
