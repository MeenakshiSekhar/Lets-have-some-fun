/*

Given a  N x N matrix where value at cell (i, j) is the cost of moving from a cell (i, j) to cell (i - 1, j - 1) or (i - 1, j) or  (i, j - 1). Your task is to find the maximum cost path from (N - 1, N - 1) cell to (0, 0) cell in the N x N matrix (0 - based indexing). However, you have some restrictions on the movement from one cell to the other cell. If you are at (i, j) cell  and (i + j) is a power of 2, you can only move to (i - 1, j - 1) cell.  If (i + j) is not a power of 2 then you can move to (i - 1, j) or  (i, j - 1). 

Input :
The first line of input contains number of testcases T. First line of every test case contains an integer N which denotes the number of rows and columns in the matrix. N lines follow which contains N integers which denotes the cost.

Output :
For each test case, print the maximum cost.

Constraints :
1 <= T <= 10
1 <= N <= 1000
1 <= Aij <= 100

Example :
Input :
1
4
1 2 3 1
4 5 6 1
7 8 9 1
1 1 1 1

Output :
16

Explanation:
The maximum cost path is: (3, 3) -> (3, 2) -> (2, 2) -> (1, 1) -> (0, 0).
Cost pathwise is: 1 + 1 + 9 + 5 = 16.
*/
*********************************************************************************************************************
#include <bits/stdc++.h>
#define ll long long

using namespace std;

//static int n
int power(int num)
{
    if (ceil(log2(num)) == floor(log2(num)))
        return 1;
    return 0;
}

int compute_max(int (*arr)[1000], int n)
{
    int max_cost = 0;
    int i,j;
    for(i=n-1; i>=0; )
    {
        for(j=n-1; j>=0; )
        {
        	if(i==0 && j==0)
        	{
        		return max_cost;
        	}
            if(power(i+j))
            {
            
                cout<<arr[i][j]<<endl;
                max_cost += arr[i][j];
                i--;
                j--;
            }
            else
            {
                if(max(arr[i-1][j], arr[i][j-1]) == arr[i][j-1])
                {
                    
                    cout<<arr[i][j]<<endl;
                    max_cost += arr[i][j];
                    j--;
                }
                else
                {
                    
                    cout<<arr[i][j]<<endl;
                    max_cost += arr[i][j];
                    i--;
                }
            }
        }
    }
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[1000][1000];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>arr[i][j];
            }
        }
        cout<<compute_max(arr, n)<<endl;
    }
	return 0;
}
