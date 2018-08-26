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

int height(struct node *root)
{
	if(root == NULL)
		return 0;
	else
	{
		int l_height = height(root->left);
		int r_height = height(root->right);
		return (l_height>r_height) ? l_height+1 : r_height+1;
	}
}

void printNodes(struct node *root, int level)
{
	if(root == NULL)
		return;

	if(level == 1)
		cout<<root->data<<"  ";
	else if(level>1)
	{
		printNodes(root->left, level-1);
		printNodes(root->right, level-1);
	}
	
}

void levelordertraversal(struct node *root)
{
	int ht = height(root);
	for(int d=1; d<=ht; d++)
	{
		printNodes(root, d);
	}
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
	levelordertraversal(root);
	return 0;		
}
