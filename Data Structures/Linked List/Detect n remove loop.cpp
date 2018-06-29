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
	struct node *fastptr = head;
	
	while(fastptr->next != NULL)
	{
		slowptr = slowptr->next;
		fastptr = fastptr->next->next;
		if(slowptr == fastptr)
		{
			break;
		}
	}
	//remove loop
	slowptr = head;
	while(slowptr->next != fastptr->next)
	{
		slowptr = slowptr->next;
		fastptr = fastptr->next;
	}
	cout<<"Loop starts at "<<fastptr->data<<endl;
	cout<<"Unlinking loop"<<endl;
	fastptr->next = NULL;
	print(head);
}

void createloop(struct node *head)
{
	struct node *temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = head->next->next->next;
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
	insert(&head, 150);
	insert(&head, 510);
	insert(&head, 5011);
	
	
	createloop(head);
	detectnremoveloop(head);
	return 0;
}
