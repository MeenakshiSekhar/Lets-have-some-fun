Given an array of numbers, the task is to print only those numbers which have only 1, 2 and 3 as their digits.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
Each test case consists of two lines. First line of each test case contains an integer N and the second line 
contains N space separated array elements.

Output:
For each test case, In new line print the required elements in increasing order. if there is no such element
present in the array print "-1".

Constraints:
1<=T<=100
1<=N<=106
1<=A[i]<=106

Example:
Input:
2
3
4 6 7
4
1 2 3 4

Output:

-1
1 2 3

*********************************************************************************************************************

#include <iostream>
#include<algorithm>
#define ll long long
using namespace std;

bool computeVal(ll n)
{
    ll rem;
    while(n>0)
    {
        rem = n%10;
        n/=10;
        if(rem!=1 && rem!=2 && rem!=3)
            return false;
    }
    return true;
}

ll* number(ll *arr, ll n)
{
    ll *num = new ll[n];
    ll k = 0;
    for(ll i=0; i<n; i++)
    {
        if(computeVal(arr[i]))
            num[k++] = arr[i];
    }
    if(k == 0)
        num[k] = -1;
    sort(num, num+k);
    return num;
}

int main() {
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    ll arr[n];
	    ll i;
	    for(i=0; i<n; i++)
	    {
	        cin>>arr[i];
	    }
	    ll *b;
	    b = number(arr, n);
	    if(b[0]==-1)
	    {
	        cout<<"-1"<<endl;
	    }
	    else
	    {
	        i = 0;
	        while(b[i])
	        {
	            cout<<b[i++]<<" ";
	        }
	        cout<<endl;
	    }
	}
	return 0;
}
