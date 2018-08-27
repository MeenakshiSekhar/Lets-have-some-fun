
Given a number N. our task is to find the closest Palindrome number whose absolute difference with given number is minimum.

Input:
The first line of the input contains integer T denoting the number of test cases. Each test case contains a  number N.

Output:
For each test case, the print the closest palindrome number.
Note:  If the difference of two closest palindromes numbers is equal then we print smaller number as output.

Constraints:
1<=T<=1000
1<=n<=10^14

Input :
2
9
489

output:
9
484

Explanation :

Test Case 1: closest palindrome number is 9 itself .

*************************************************************WRONG ANSWER**************************************************************

#include <iostream>
#define ll long long
using namespace std;

string palindrome(string s)
{
    ll len = s.length();
    for(ll i=0; i<len/2; i++)
    {
        if(s[i]-'0' != s[len-i-1]-'0')
        {
            s[len-i-1] = s[i];
        }
    }
    return s;
}

int main() {
	ll t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    cout<<palindrome(s)<<endl;
	}
	return 0;
}
