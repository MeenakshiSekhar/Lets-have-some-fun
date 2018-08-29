#include <iostream>
using namespace std;

bool checkCycleUtil(int (*arr)[100], bool *visited, int n, int parent, int v)
{
	visited[v] = true;
		for(int i=0; i<n; i++)
		{
			if(arr[v][i]==1 && !visited[i])
			{
				if( checkCycleUtil(arr, visited, n, v, i))
				return true;
			}
			else if(arr[v][i]==1 && parent!=-1 && i!=parent )
			{
				//cout<<"here"<<parent<<" "<<v<<" "<<i<<endl;
				return true;
			}
		}
		return false;
}

bool checkCycle(int (*arr)[100], int n)
{
	bool visited[n];
	for(int i=0; i<n; i++)
	{
		visited[i] = false;
	}
	{
	for(int i=0; i<n; i++)
	if(!visited[i])
		{if(checkCycleUtil(arr, visited,  n,-1,  i))
			return true;}
	}
	return false;
}

int main() {
	int n=5;
	int arr[100][100];
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin>>arr[i][j];
		}
	}
	bool res= checkCycle(arr, n);
	cout<<res<<endl;
	return 0;
}
