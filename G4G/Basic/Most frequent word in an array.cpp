Given an array containing N words, you need to find the most frequent word in the array. If multiple words have same frequency then print the word that comes first in lexicographical order.

Input:
The first line of the input contains a single integer T, denoting the number of test cases. Then T test case follows. Each test case contains 2 lines:-
The size of array N
N words separated by spaces

Output:
For each testcase, print the most frequent word.

Constraints:
1<=T<=100
1<=N<=1000

Example:

Input:
3
3
geeks for geeks
2
hello world
3
world wide fund

Output:
geeks
hello
fund

*****************************************************************************************************************

#include <iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

bool compare(const pair<string, int> &v1, const pair<string, int> &v2)
{
    return (v1.second > v2.second); 
}
bool compareStr(const pair<string, int> &v1, const pair<string, int> &v2)
{
    if(v1.second == v2.second)
	      return v1.first<v2.first; 
	  return v1.second>v2.second;
}

string maxFreq(string s[1000], int n)
{
    map<string, int> mp;
    for(int i=0; i<n; i++)
    {
        mp[s[i]] += 1;
    }
    vector<pair<string, int>> vmap(mp.begin(), mp.end());
    sort(vmap.begin(), vmap.end(), compare);
    sort(vmap.begin(), vmap.end(), compareStr);
    return vmap[0].first;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string s[n];
	    for(int i=0; i<n; i++)
	    {
	        cin>>s[i];
	    }
	    cout<<maxFreq(s,n)<<endl;
	}
	return 0;
}
