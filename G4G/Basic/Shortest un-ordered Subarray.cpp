Given an array of n distinct elements. Find the length of shortest unordered (neither increasing nor decreasing) 
sub array in given array.

Input:
The first line consists of an integer T i.e number of test cases. The first line of each test case 
consists of an integer n.The next line consists of n spaced numbers. 

Output:
Print the required output.

Constraints: 
1<=T<=100
1<=n<=100
1<=a[i]<=105

Example:
Input:
2
5
7 9 10 8 11
4
1 2 3 5

Output:
3
0

*****************************************************************************************************************
#include <iostream>

#define ll long long
using namespace std;

bool increasing(ll *arr, ll n)
{
    for(ll i=1; i<n; i++)
    {
        if(arr[i]<arr[i-1]) 
            return false;
    }
    return true;
}

bool decreasing(ll *arr, ll n)
{
    for(ll i=1; i<n; i++)
    {
        if(arr[i]>arr[i-1]) 
            return false;
    }
    return true;
}

ll minSubarray(ll *arr, ll n)
{
    if(increasing(arr,n)==true || decreasing(arr,n)==true)
        return 0;
    return 3;
}

int main() {
	ll t;
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
	    cout<<minSubarray(arr, n)<<endl;
	}
	return 0;
}
