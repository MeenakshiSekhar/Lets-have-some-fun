Given a positive integer N, print count of set bits in it. 
For example, if the given number is 6, output should be 2 as there are two set bits in it.

Input:

The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. The next T lines will contain an integer N.

Output:
Corresponding to each test case, in a new line, print count of set bits in it.

Constraints:

1 ≤ T ≤ 100

1 ≤ N ≤ 1000000


Example:

Input:

2
6
11
 

Output:
2
3

***************************************************************************************************************
#include <iostream>
#define ll long long
using namespace std;

int setBits(ll n)
{
    int count = 0;
    while(n>0)
    {
        n = (n&n-1);
        count++;
    }
    return count;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    cout<<setBits(n)<<endl;
	}
	return 0;
}
