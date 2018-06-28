#include<iostream>

using namespace std;

void print(struct node *node);

struct node {
	int data;
	struct node *next;
	};
	
void insert(struct node **head, int data)
{
	struct node *newnode = new node();
	newnode->data = data;
	newnode->next = NULL;
	
	if(*head == NULL)
	{
		*head = newnode;
		return;
	}
	
	struct node *temp = *head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newnode;
	return;
}

void detectnremoveloop(struct node *head)
{
	struct node *slowptr = head;
	struct node *fastptr = head->next;
	
	while(slowptr != fastptr)
	{
		slowptr = slowptr->next;
		fastptr = fastptr->next->next;
	} 

    if(fastptr->next == head)
    {
    	cout<<"Its a circular linked list"<<endl;
    }
	slowptr = head;
	struct node *prev = NULL;
	while(slowptr != fastptr)
	{
		slowptr = slowptr->next;
		prev = fastptr->next;
		fastptr = fastptr->next->next;
	}
	cout<<"Loop starts at "<<fastptr->data<<endl;
	cout<<"Unlinking loop"<<endl;
	prev->next = NULL;
	print(head);
}

void createloop(struct node *head)
{
	struct node *temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = head->next;
}

void print(struct node *node)
{
	struct node *temp = node;
	while(node != NULL)
	{
		cout<<node->data<<"\t";
		node = node->next;
	}
	cout<<endl;
}

int main()
{
	struct node *head = NULL;
	
	insert(&head, 1);
	insert(&head, 10);
	insert(&head, 25);
	insert(&head, 50);
	
	createloop(head);
	detectnremoveloop(head);
	return 0;
}
