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

struct node *findLca(struct node *root, int n1, int n2, bool &v1, bool &v2)
{
	if(root == NULL)
		return NULL;
		
	if(root->data == n1)
	{
		v1 = true;
	}
	if(root->data == n2)
	{
		v2 = true;
	}
	
	if(root->data > n1 && root->data >n2)
		return findLca(root->left, n1, n2, v1, v2);
	
	if(root->data > n1 && root->data >n2)
		return findLca(root->right, n1, n2, v1, v2);
		
	return root;	
}

bool findNode(struct node *root, int n)
{
	if(root == NULL)
		return false;
	
	if(root->data == n || findNode(root->left, n) || findNode(root->right, n))
		return true;
	
	return false;
}

struct node *lca(struct node *root, int n1, int n2)
{
	bool v1 = false;
	bool v2 = false;
	struct node *result = findLca(root, n1, n2, v1, v2);
	if((v1 && v2) || (v1 && findNode(root, n2)) || (v2 && findNode(root, n1)))
	{
		return result;
	}
	return NULL;
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
    
    struct node *result = lca(root, 1, 10);
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
