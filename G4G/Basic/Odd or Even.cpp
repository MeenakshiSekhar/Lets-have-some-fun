Given an odd number in the form of string, the task is to make largest even number possible 
from the given number provided one is allowed to do only one swap operation, 
if no such number is possible then print the input string itself.

Examples:

Input : 1235785
Output :1535782
Swap 2 and 5.

Input:
Thr first line of the input contains a single integer T, denoting the number of test cases. 
Then T test case follows, the only line of the input contains an odd number in the form of string.

Output:
For each test case print the largest possible even number that could be formed by using one swap operation only.

Constraints:
1<=T<=100
1<=N<=106

Example:
Input:
3
789
536425
1356425
Output:
798
536524
1356524

***********************************************************************************************************************
#include<iostream>
#define ll long long

using namespace std;

string swap(string s, int n1, int  n2)
{
	char ch = s[n1];
	s[n1] = s[n2];
	s[n2] = ch;
	return s;
}

string maxEven(string s)
{
	ll len = s.length();
	int last = s[len-1] - '0';
	int first = -1;
	int max = -1;
	int firstIndex = -1, maxIndex = -1;
	for(int i=len-2; i>=0; i--)
	{
		int num = s[i] - '0';
		if(num%2==0)
		{
			if(first == -1)
			{
				first = num;
				firstIndex = i;
			}
			else
			{
				if(num<last)
				{
					max = num;
					maxIndex = i;
				}
			}
		}
	}
	if(maxIndex == -1 && firstIndex == -1)
	{
		return s;
	}
	if(maxIndex == -1)
	{
		return swap(s, firstIndex, len-1);
	}
	else
	{
		return swap(s, maxIndex, len-1);
	}
}

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		cout<<maxEven(s)<<endl;
	}
	return 0;
}
