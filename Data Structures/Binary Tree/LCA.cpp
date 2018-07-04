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

struct node *lca_value(struct node *root, int d1, int d2, bool &v1, bool &v2)
{
	if(root == NULL)
		return NULL;
	if(root->data == d1)
	{
		v1 = true;
		return root;	
	}
	if(root->data == d2)
	{
		v2 = true;
		return root;
	}
		
	struct node* lca_left = lca_value(root->left, d1, d2, v1, v2);
	struct node* lca_right = lca_value(root->right, d1, d2, v1, v2);
	
	if(lca_left && lca_right)
		return root;
	
	return (lca_left != NULL) ? lca_left : lca_right;
}

bool findNode(struct node *root, int n)
{
	if(root == NULL)
		return false;
	
	if(root->data == n || findNode(root->left, n) || findNode(root->right, n))
		return true;
	
	return false;
}
struct node* lca(struct node *root, int d1, int d2)
{
	bool v1 = false;
	bool v2 = false;
	struct node *result = lca_value(root, d1, d2, v1, v2);
	if(v1 && v2 || (v1 && findNode(root, d2)) || (v2 && findNode(root, d1)))
	return result;
	return NULL;
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
	struct node *result = lca(root, 10, 15);
	if(result != NULL)
	{
		cout<<result->data<<endl;
	}
	else
	{
		cout<<"Key not found"<<endl;	
	}
	return 0;
}
