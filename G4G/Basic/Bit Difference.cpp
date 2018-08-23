You are given two numbers A and B. Write a program to count number of bits needed to be flipped to convert A to B.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is a and b.

Output:

Print the number of bits needed to be flipped.

Constraints:

1 ≤ T ≤ 100
1 ≤ a,b ≤ 1000

Example:

Example:
Input
1
10 20

Output
4
 

Explanation:

A  = 1001001
B  = 0010101
No of bits need to flipped = set bit count i.e. 4

**************************************************************************************************************************************
#include <iostream>
using namespace std;

int bitDiff(int a, int b)
{
    int c = a ^ b;
    int count = 0;
    while(c>0)
    {
        c = (c&c-1);
        count++;
    }
    return count;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int a, b;
	    cin>>a>>b;
	    cout<<bitDiff(a,b)<<endl;
	}
	return 0;
}
