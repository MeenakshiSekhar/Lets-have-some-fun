Given two arrays of equal length, the task is to find if given arrays are equal or not.
Two arrays are said to be equal if both of them contain same set of elements, arrangements (or permutation) 
of elements may be different though.

Note : If there are repetitions, then counts of repeated elements must also be same for two array to be equal.

Examples:

Input  : A[] = {1, 2, 5, 4, 0};
         B[] = {2, 4, 5, 0, 1}; 
Output : 1

Input  : A[] = {1, 2, 5};
         B[] = {2, 4, 15}; 
Output : 0

*************************************************************************************************************************

#include <iostream>
#include<algorithm>

#define ll long long

using namespace std;

int checkEqual(ll *a, ll *b, ll n)
{
    sort(a, a+n);
    sort(b, b+n);
    for(ll i=0; i<n; i++)
    {
        if(a[i]!=b[i])
            return 0;
    }
    return 1;
}

int main() {
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    ll a[n], b[n];
	    for(ll i=0; i<n; i++)
	    {
	        cin>>a[i];
	    }
	    for(ll i=0; i<n; i++)
	    {
	        cin>>b[i];
	    }
	    cout<<checkEqual(a,b,n)<<endl;
	}
	return 0;
}
