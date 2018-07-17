/*

Given an array A of N positive integers and a budget B. Your task is to decide the maximum number of elements to be picked from the array such that the cumulative cost of all picked elements is less than or equal to budget B. Cost of picking the ith element is given by : A[i] + (i * K) where, K is a constant whose value is equal to the number of elements picked. The indexing(i) is 1 based.

Input : First line of input contains number of testcases T. For each testcase, there will be two lines. First line contains size of array A and budget B. Next line contains the array elements.

Output : For each testcase, output two integers, the number of elements picked and cumulative cost.

Constraints :
1 <= T <= 100
1 <= N <= 105
1 <= A[i] <= 105
1 <= B <= 109
1 <= K <= N

Example:
Input :
2
3 11
2 3 5
4 60
1 2 5 6

Output :
2 11
4 54

Explanation :
In the 1st sample, Cost of picking maximum cities = {2 + (1 * 2) } + {3 + (2 * 2)} = 4 + 7 = 11 (which is within Budget).
*/

/*---------------------------------------------WROGN ANSWER------------------------------------------------*/


#include <iostream>
#include<string.h>
#define ll long long 
using namespace std;

void knapsack(ll *arr, ll n, ll budget)
{
    ll dp[n+1];
    memset(dp,0,sizeof(dp));
    ll j;
    for(j=1; j<=n; j++)
    {
           	for(ll k=1; k<=j; k++)
           	{
           		dp[j] += (arr[k-1]+(j*k));
           	}
           	if(dp[j]>budget)
           	{
           	    cout<<j-1<<" "<<dp[j-1]<<endl;
           	    return;
           	}
    }
    cout<<j-1<<" "<<dp[j-1]<<endl;
}


int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    ll n, budget;
	    cin>>n>>budget;
	    ll arr[n];
	    for(ll i=0; i<n; i++)
	    {
	        cin>>arr[i];
	    }
	    knapsack(arr, n, budget);
	}
	return 0;
}
