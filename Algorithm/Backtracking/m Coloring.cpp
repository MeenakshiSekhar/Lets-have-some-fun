#include<iostream>
#define V 4

using namespace std;

void print(int *color);

bool isSafe(int graph[V][V], int *color, int m, int c, int v)
{
	for(int i=0; i<V; i++)
	{
		if(graph[v][i] && color[i]==c) {
			return false;
		}
	}
	return true;
}

bool mcolorUtil(int graph[V][V], int m, int *color, int v)
{
	if(v==V)
	{
		return true;
	}
	
	for(int i=1; i<=m ; i++)
	{
		if(isSafe(graph, color, m, i, v))
		{
			color[v] = i;
			if(mcolorUtil(graph, m, color, v+1)) {
				return true;
			}
			color[v] = 0;
		}
	}
	return false;
}

bool mcolor(int graph[V][V], int m)
{
	int color[V];
	for(int i=0; i<V; i++)
	{
		color[i] = 0;
	}
	if(mcolorUtil(graph, m, color, 0)){
		print(color);
		return true;
	}
	cout<<"Solution doesnot exist"<<endl;
	return false;
}

void print(int *color)
{
	for(int i=0; i<V; i++)
	{
		cout<<color[i]<<"\t";
	}
}
int main()
{
	int graph[][V] ={ {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
	};
	int m = 3;
	mcolor(graph, m);
	return 0;
}
