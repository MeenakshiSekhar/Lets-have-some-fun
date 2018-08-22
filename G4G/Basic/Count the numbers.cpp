
Given a number N, count the numbers from 1 to N which comprise of digits, only in set 1, 2, 3, 4 and 5. 

Input:

The first line of input contains an integer T denoting the number of test cases.Then T test cases follow. 
Each test case consist of one line. Each line of each test case is N, where N is the range from 1 to N.

Output:

Print the count of numbers in the given range from 1 to N.

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 1000

Example:

Input:
2
100
10
Output:
30
5

*************************************************************************************************************************

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
        if(rem!=1 && rem!=2 && rem!=3 && rem!=4 && rem!=5)
            return false;
    }
    return true;
}

ll number(ll n)
{
    ll k = 0;
    for(ll i=1; i<=n; i++)
    {
        if(computeVal(i))
            k++;
    }
    return k;
}

int main() {
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    cout<<number(n)<<endl;
	}
	return 0;
}
