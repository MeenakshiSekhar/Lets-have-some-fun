#include<iostream>
#define V 5
#define inf 9999

using namespace std;

void print(int *parent, int *key)
{
	for(int i=0; i<V; i++)
	{
		cout<<i<<"  "<<parent[i]<<"  "<<key[i]<<endl;
	}
}

int findmin(int *key, bool *mst)
{
	int min = 10000;
	int min_index = -1;
	for(int i=0; i<V; i++)
	{
		if(!mst[i] && key[i] < min)
		{
			min = key[i];
			min_index = i;
		}
	}
	return min_index;
}

void primMst(int graph[V][V])
{
	int parent[V];
	int key[V];
	bool mst[V];
	
	for(int i=0; i<V; i++)
	{
		key[i] = inf;
		mst[i] = false;
	}	
	
	key[0] = 0;
	parent[0] = 0;
	for(int index =0; index<V; index++)
	{
		int vertex = findmin(key, mst);
		mst[vertex] = true;
				
		for(int i=0; i<V; i++)
		{
			if(graph[vertex][i] && mst[i] == false && key[i] > graph[vertex][i])
			{
				key[i] = graph[vertex][i];
				parent[i] = vertex;
			}
		}
	}
	print(parent, key);
}

int main()
{
	int graph[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };
    
	primMst(graph);
	return 0;
}
