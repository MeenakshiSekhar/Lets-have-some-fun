Given a string containing 0’s and 1’s. The task is to find out minimum number of bits to be flipped such that 
0’s and 1’s will be alternative.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
Each test case contains a string.

Output:
For each test case, print the minimum number of flipped bits in a new line.

Constraints:
1<=T<=100
1<=|string length|<=104

Example:
Input:
2
0011
011000
Output:
2
3
************************************************************************************************************************

#include <iostream>
#define ll long long
using namespace std;

char flip(char ch)
{
    return (ch == '0') ? '1' : '0';
}

ll countFlip(string str, char expected)
{
    ll flipCount = 0;
    ll len = str.length();
    for(ll i=0; i<len; i++)
    {
        if(str[i] != expected)
        {
            flipCount++;
        }
        expected = flip(expected);
    }
    return flipCount;
}

ll minFlip(string str)
{
    return min(countFlip(str, '0'), countFlip(str, '1'));
}

int main() {
	ll t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    cout<<minFlip(str)<<endl;
	}
	return 0;
}
