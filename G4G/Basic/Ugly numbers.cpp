Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … 
shows the first 11 ugly numbers. By convention, 1 is included. Write a program to find Nth Ugly Number.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N.

Output:

Print the Nth Ugly Number.

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 500

Example:

Input:
2
10
4

Output:
12
4
**************************************************************************************************************************
#include <iostream>
#define ll long long
using namespace std;

bool checkUgly(int n)
{
	while(n>1)
    {
    	if(n%2==0)
    	{
    		n/=2;
    	}
    	else if(n%3==0)
    	{
    		n/=3;
    	}
    	else if(n%5==0)
    	{
    		n/=5;
    	}
    	else
    		return false;
    }
    return true;
}

ll ugly(int n)
{
    ll i = 1;
    while(1)
    {
        if(n == 1)
        {
            return i;
        }
        if(checkUgly(++i))
        {
        	n--;
        }
    }
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    cout<<ugly(n)<<endl;
	}
	return 0;
}
