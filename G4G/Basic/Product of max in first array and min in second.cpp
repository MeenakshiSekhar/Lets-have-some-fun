Given two arrays of size N1 and N2 respectively, the task is to calculate the product of max element of first array 
and min element of second array.

Input:
The first line of the input contains a single integer T, denoting the number of test cases. Then T test case follows.
Each testcase contains 4 lines:-
Size of the first array N1
Elements of the first array separated by spaces
Size of the second array N2
Elements of the second array separated by spaces

Output:
For each testcase, print the product of the max element of the first array and the minimum element of the second array.

Constraints:
1<=T<=107
1<=N1,N2<=1000
-1000<=A[i]<=1000

Example:

Input:
2
6
5 7 9 3 6 2
6
1 2 6 -1 0 9
6
1 4 2 3 10 2
6
4 2 6 5 2 9

Output:
-9
20
************************************************************************************************************************

#include <iostream>
#include<climits>
#define ll long long
using namespace std;

ll prod(ll *a, ll n1, ll *b, ll n2)
{
    ll min = INT_MAX;
    ll max = INT_MIN;
    for(ll i=0; i<n1; i++)
    {
        if(max<a[i])
            max = a[i];
    }
    for(ll i=0; i<n2; i++)
    {
        if(min>b[i])
            min = b[i];
    }
    return min*max;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    ll n1;
	    cin>>n1;
	    ll arr[n1];
	    for(ll i=0; i<n1; i++)
	    {
	        cin>>arr[i];
	    }
	    ll n2;
	    cin>>n2;
	    ll barr[n2];
	    for(ll i=0; i<n2; i++)
	    {
	        cin>>barr[i];
	    }
	    cout<<prod(arr, n1, barr, n2)<<endl;
	}
	return 0;
}
