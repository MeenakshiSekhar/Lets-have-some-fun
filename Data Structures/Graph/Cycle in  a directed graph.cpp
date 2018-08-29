#include <iostream>
using namespace std;

bool checkCycleUtil(int (*arr)[100], bool *visited, bool *recstack, int n, int v)
{
	if(!visited[v])
	{
		visited[v] = true;
		recstack[v] = true;
		for(int i=0; i<n; i++)
		{
			if(arr[v][i]==1 && !visited[i] && checkCycleUtil(arr, visited, recstack, n, i))
			{
				return true;
			}
			else if(arr[v][i]==1 && recstack[i])
			{
				return true;
			}
		}
	}
	recstack[v] = false;
	return false;
}

bool checkCycle(int (*arr)[100], int n)
{
	bool visited[n];
	bool recstack[n];
	for(int i=0; i<n; i++)
	{
		visited[i] = false;
		recstack[i] = false;
	}
	{
	for(int i=0; i<n; i++)
		if(checkCycleUtil(arr, visited, recstack, n, i))
			return true;
	}
	return false;
}

int main() {
	int n=4;
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
