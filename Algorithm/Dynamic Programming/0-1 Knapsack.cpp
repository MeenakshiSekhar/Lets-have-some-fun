#include<iostream>

using namespace std;

int max(int a, int b)
{
	return (a>b) ? a : b;
}

int knapsackDp(int *wt, int *val, int size, int weight)
{
	int dp[size+1][weight+1];
		
	for(int i=0; i<=size; i++)
	{
		for(int j=0; j<=weight; j++)
		{
			if(i==0 || j==0)
			{
				dp[i][j] = 0;
			}
			else if(wt[i-1]>j)
			{
				dp[i][j] = dp[i-1][j];
			}
			else if(wt[i-1]<=j)
			{
				dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
			}
		}
	}
	return dp[size][weight];
}

int main()
{
	int wt[] = {1, 2, 4, 5};
	int val[] = {3, 5, 7, 11};
	int size = sizeof(wt)/sizeof(int);
	int weight = 8;
	
	cout<<knapsackDp(wt, val, size, weight);
	return 0;	
}
