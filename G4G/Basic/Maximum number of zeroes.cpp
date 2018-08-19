Given an array of n values. Print a number which had maximum number of zeroes. If their are no zeroes then print -1.

Note: If there are multiple numbers with same (max) number of zeroes then print the Maximum number among them.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case consists of an integer n. The next line consists of n spaced integers.

Output:
Print the number with maximum number of zeroes.

Constraints: 
1<=T<=100
1<=N<=1000
1<=A[i]<=100000

Example:
Input:
1
5
10 20 3000 9999 200
Output:
3000

****************************************************************************************************************

#include <iostream>
#define ll long long
using namespace std;

ll countZero(ll n)
{
    ll count = 0;
    ll rem = 0;
    while(n>9)
    {
        rem = n%10;
        if(rem == 0)
            count++;
        n/=10;
    }
    return count;
}

ll maxZero(ll *arr, ll n)
{
    ll count = 0;
    ll maxVal = -1;
    for(ll i=0; i<n; i++)
    {
        ll zero = countZero(arr[i]);
        if(count < zero)
        {
            count = zero;
            maxVal = arr[i];
        }
        else if (count != 0 && count == zero && maxVal < arr[i])
        {
            maxVal = arr[i];
        }
    }
    return maxVal;
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
	    cout<<maxZero(arr, n)<<endl;
	}
	return 0;
}
