#include <iostream>
using namespace std;

struct queue
{
    int front, rear, capacity, size;
    int *arr;
};

struct queue* createQueue(int n)
{
//	cout<<"create q"<<endl;
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
    if(!isEmpty(q))
    {
        q->front = (q->front+1)%q->capacity;
        q->size = q->size-1;
    }
}

int front(struct queue *q)
{
    if(!isEmpty(q))
    {
        return q->arr[q->front];
    }
    return -1;
}

void DFSUtil(int (*graph)[100], bool visited[], int n, struct queue* q, int v)
{
	if(!visited[v])
    {	
    	visited[v] = true;
    	push(q, v);
    }
    while(!isEmpty(q))
    {
    	int index = front(q);
        cout<<index<<" ";
        pop(q);
        for(int j=0; j<n; j++)
            {
                if(graph[index][j] == 1 && !visited[j])
                {
                    visited[j] = true;
                    push(q, j);
                    DFSUtil(graph, visited, n, q, j);
                }
            }
    }
    
}

void DFS(int (*graph)[100], int n, struct queue* q)
{
	bool visited[n];
    for(int i=0; i<n; i++)
    {
    	visited[i] = false;
    }
    DFSUtil(graph, visited, n, q, 2);
}

int main() {
    struct queue *q = createQueue(1000);
    //cout<<"here"<<endl;
	int n = 4;
	int graph[100][100];
	for(int i=0; i<n; i++)
	{
	    for(int j=0; j<n; j++)
	    {
	        cin>>graph[i][j];
	    }
	}
	DFS(graph, n, q);
	return 0;
}
