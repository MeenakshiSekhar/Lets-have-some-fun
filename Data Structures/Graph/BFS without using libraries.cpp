#include <iostream>
using namespace std;

struct queue
{
    int front, rear, capacity, size;
    int *arr;
};

struct queue* createQueue(int n)
{
	cout<<"create q"<<endl;
    struct queue *q = new queue();
    q->front = q->size = 0;
    q->rear = n - 1;
    q->capacity = n;
    q->arr = new int[n];
    return q;
}

bool isFull(struct queue* q)
{
    return (q->capacity == q->size);
}

bool isEmpty(struct queue *q)
{
    return (q->size == 0);
}

void push(struct queue *q, int data)
{
    if(!isFull(q))
    {
        q->rear = (q->rear+1)%q->capacity;
        q->arr[q->rear] = data;
        q->size = q->size+1;
    }
    return;
}

void pop(struct queue *q)
{
    if(!isEmpty)
    {
        q->front = (q->front+1)%q->capacity;
        q->size = q->size-1;
    }
}

int front(struct queue *q)
{
    if(!isEmpty)
    {
        return q->arr[q->front];
    }
    return -1;
}

void BFS(int (*graph)[100000], int n, struct queue* q)
{
    cout<<"hi";
    bool visited[n];
    for(int i=0; i<n; i++)
    {
    	visited[i] = false;
    }
    
    visited[2] = true;
    push(q, 2);
    cout<<"check"<<endl;
    while(!isEmpty(q))
    {
        cout<<front(q)<<" ";
        pop(q);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(graph[i][j] == 1 && !visited[j])
                {
                    visited[j] = true;
                    push(q, j);
                }
            }
        }
    }
    
}

int main() {
    struct queue *q = createQueue(1000);
    
	int n = 4;
	int graph[100000][100000];
	for(int i=0; i<n; i++)
	{
	    for(int j=0; j<n; j++)
	    {
	        cin>>graph[i][j];
	    }
	}
	BFS(graph, n, q);
	return 0;
}
