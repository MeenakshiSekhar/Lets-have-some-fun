Given a string containing of ‘0’, ‘1’ and ‘?’ wildcard characters, generate all binary strings
that can be formed by replacing each wildcard character by ‘0’ or ‘1’.
 

Input:

The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. 
Each test case consist of two lines. The first line of each test case consists of a string S.
 

Output:

Print all binary string that can be formed by replacing each wildcard character.
 

Constraints:

1 ≤ T ≤ 60
1 ≤  length  of string S ≤ 30

Example:

Input
1
1??0?101

Output
10000101 10001101 10100101 10101101 11000101 11001101 11100101 11101101

****************************************************WRONG ANSWER ****************************************************

#include <iostream>
#include<math.h>
#define ll long long
using namespace std;

static int index = 0;

void printString(string *arr, ll combi)
{
    for(ll i=0; i<combi; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int add(string *arr, string s, ll combi)
{
	arr[index++]= s;
	if(index == combi)
	{
		printString(arr, combi);
		return 1;
	}
	return 0;
}

void completeString(string s, ll i, ll len, string *arr, ll combi)
{
    while(s[i]!='?' && i<len)
    {
    	i++;
    }
    if(i == len)
    {
    	int ret= add(arr, s, combi--);
    	if(ret)
    		return;
    }
    if(s[i] == '?')
    {
        s[i] = '0';
        completeString(s,i+1, len, arr, combi);
        s[i] = '1';
        completeString(s, i+1, len, arr, combi);
    }
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int len = s.length();
	    int count = 0;
	    for(ll i=0; i<len; i++)
	    {
	    	if(s[i] == '?')
	    		count++;
	    }
	    ll combi = pow(2, count);
	    string arr[combi];
	    completeString(s, 0, len, arr, combi);
	}
	return 0;
}

***************************************************************************************************************************
