
Given N, count all ‘a’ and ‘b’ that satisfy the condition a^3 + b^3 = N.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains integer n.

Output:
Count all 'a' and 'b' that satisfy the above equation.

Constraints:
1<=T<=10^5
1<=n<=10^5

Example:
Input:
2
9
28

Output:
2
2

****************************************************************************************************************************************************

#include <iostream>
#include<cmath>
#define ll long long
using namespace std;

ll pairCube(ll n)
{
    ll count = 0;
    for(ll i=1; i<=cbrt(n); i++)
    {
        ll diff = n - (i*i*i);
        ll checkdiff = cbrt(diff);
        if(checkdiff*checkdiff*checkdiff == diff)
            count++;
    }
    return count;
}

int main() {
	ll t;
	cin>>t;
	while(t--)
	{
	  ll n;
	  cin>>n;
	  cout<<pairCube(n)<<endl;
	}
	return 0;
}
