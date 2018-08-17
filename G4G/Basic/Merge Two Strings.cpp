Given two strings S1 and S2 as input, the task is to merge them alternatively i.e. the first character of S1 then the first character of S2 and so on till the strings end.

NOTE: Add the whole string if other string is empty.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains two strings S1 and S2.

Output:
For each test case, print the merged string in new line.

Constraints:
1<=T<=100
1<=|strings length|<=104

Example:
Input:
2
Hello Bye
abc def

Output:
HBeylelo
adbecf

***************************************************************************************************************************



#include <iostream>
#include<string.h>
#define ll long long
using namespace std;

string mergeString(string s1, string s2)
{
    int len1 = s1.length();
	int len2 = s2.length();  
	string s="";
	ll i=0, j=0;
	bool flag = true;
	for(i=0, j=0; i<len1 && j<len2;)
	{
	    if(flag)
	    {
	        s+=s1[i++];
	        flag = false;
	    }
	    else
	    {
	        s+=s2[j++];
	        flag = true;
	    }
	}
	while(i<len1)
	{
	    s+=s1[i++];
	}
	while(j<len2)
	{
	    s+=s2[j++];
	}
	return s;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s1, s2;
	    cin>>s1>>s2;
	    cout<<mergeString(s1,s2)<<endl;
	}
	return 0;
}
