#include<bits/stdc++.h>

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

void calculateSum(struct node *root, int hd, map<int, int> &hashMap)
{
	if(root == NULL)
	{
		return;
	}
	calculateSum(root->left, hd-1, hashMap);
	hashMap[hd] += root->data;
	calculateSum(root->right, hd+1, hashMap);
}

void verticalSum(struct node *root)
{
	map<int, int> hashMap;
	map<int, int> :: iterator itr;
	calculateSum(root, 0, hashMap);
	
	for(itr = hashMap.begin(); itr!=hashMap.end(); itr++)
	{
		cout<<itr->first<<" : "<<itr->second<<endl;
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
	
	verticalSum(root);
	return 0;
}
