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
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int findPair(ll *arr, ll n, ll *sum, ll k)
{
    map<ll, ll> m;
    
    for(ll i=0; i<n; i++)
    {
        m[arr[i]]++;
    }
    
    for(ll i=0; i<k; i++)
    {
        ll s = sum[i];
        for(ll j=0; j<n; j++)
        {
            if(m[s-arr[j]] && ((s-arr[j]==arr[j] && m[arr[j]]>1) ||(s-arr[j]!=arr[j])))
                return 1;
        }
    }
    return 0;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    ll n, k;
	    cin>>n;
	    ll arr[n];
	    for(ll i=0; i<n; i++)
	    {
	        cin>>arr[i];
	    }
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
	    cout<<findPair(arr, n, sum, k)<<endl;
	}
	return 0;
}
