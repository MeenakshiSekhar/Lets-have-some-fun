/*


Given two arrays of integers where maximum size of first array is big and that of second array is small. Your task is to find if there is a pair in the first array whose sum is present in the second array.

Input : First line of input contains number of testcases T. For each testcase, there will be four lines. First line contains size of first array N1 and second line contains elements of array of size N1. Third line contains size of second array N2 and the next line follows second array's elements.

Output :
For each testcase, output "1" if such pair exists, otherwise print "0" without quotes.

Constraints :
1 <= T <= 400
2 <= N1 <= 104
2 <= N2 <= 100
0 <= A[i] <= 106

Example :
Input :
1
4
1 5 10 8
3
2 20 13

Output :
1

Explanation :
Pair (5, 8) exists in first array whose sum 13 is present in second array.
*/

**************************************************************************************************************************

#include <iostream>
#include<algorithm>
#define ll long long 
using namespace std;

int subsetSum(ll *arr, ll n, ll *sum, ll k)
{
    ll size = sum[k-1];
    //cout<<sum[k-1]<<endl;
    ll dp[n+1][size+1];
    for(ll i=0; i<=n; i++)
    {
        for(ll j=0; j<=size; j++)
        {
            if(j == 0 || i==0)
            {
                dp[i][j] = 0;
            }
            else
            {
                if(arr[i-1]>j)
                {
                    dp[i][j] = dp[i-1][j];
                }
                else
                {
                    if(arr[i-1]==j)
                    {
                        dp[i][j] = 1;
                    }
                    else
                    {
                        dp[i][j] = (dp[i-1][j] || dp[i-1][j-arr[i-1]]);
                    }
                }
            }
        }
    }
    for(ll j=0; j<=n; j++)
    {
    	for(ll i=0; i<k; i++)
    	{
    		
    		if(dp[j][sum[i]]==1)
    		{
    			return 1;
    		}
    	}
    }
    return 0;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    ll arr[n];
	    for(ll i=0; i<n; i++)
	    {
	        cin>>arr[i];
	    }
	    ll k;
	    cin>>k;
	    ll sum[k];
	    for(ll i=0; i<k; i++)
	    {
	        cin>>sum[i];
	    }
	    sort(arr, arr+n);
	    sort(sum, sum+k);
	    for(ll i=n-1; i>=0; i--)
	    {
	        if(arr[i]>sum[k-1])
	            n--;
	        else 
	            break;
	    }
	    cout<<subsetSum(arr, n, sum ,k);
	}
	return 0;
}
