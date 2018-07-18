/*
Given a string S, print all ‘Special Subsequences’ of S. A special subsequence is a subsequence of given string with capital letters allowed.   A Subsequence is a sequence that can be derived from given string by removing zero or more elements, without changing the order of the remaining elements. For example subsequences of abc are {a, b, c, ab, ac, bc, abc}. To generate Special Subsequences, we need to consider both the upper and lowercases and their combination. For Instance, “ab” has the following Special-Subsequences-: { “A”, “AB”, “Ab”, “B”, “a”, “aB”, “ab”, “b” }.

NOTE : Consider only the non-empty Special Subsequences of S, as shown above.

Input : The first line of input conains number of testcases T.  Each testcase contains a single line denoting the string S.

Output : For each testcase you need to print two lines. In the 1st line print N, denoting the number of Special Sub Sequences of S.

In the 2nd line print N space separated integers denoting the Special Sub Sequences of S, in lexicographically increasing order.

Constraints
1 <= T <= 100
1 <= |S| <= 10
The String S, contains only lower-case letters (i.e ‘a’ - ‘z’)

Example :
Input :
2
ab
abc

Output :
8
A AB Ab B a aB ab b
26
A AB ABC ABc AC Ab AbC Abc Ac B BC Bc C a aB aBC aBc aC ab abC abc ac b bC bc c
*/

******************************************************************************************************************************


#include<iostream>
#include<algorithm>

using namespace std;

void permuteCase(string *arr, int opSize)
{
	int maxCount =0;
	for(int r=0; r<opSize-1; r++)
	{
		cout<<arr[r]<<endl;
	}
	for(int i=0; i<opSize-1; i++)
	{
		int l = arr[i].length();
		maxCount+=(1<<l);
	}
	cout<<maxCount<<endl;
	string result[maxCount];
	static int resultIndex =0;
	for(int i=0; i<opSize-1; i++)
	{
		string str = arr[i];
		int len = str.length();
		int maxPermute = 1<<len;
		transform(str.begin(), str.end(), str.begin(), ::tolower);
		for(int j=0; j<maxPermute; j++)
		{
			string per = str;
			for(int k=0; k<len; k++)
			{
				if((1 & (j>>k))==1)
				{
					per[k] = toupper(per.at(k));
				}
			}
			result[resultIndex++] = per;
		}
		
		
	}
	sort(result, result+maxCount);
	for(int print=0; print<maxCount; print++)
	{
		cout<<result[print]<<endl;
	}
}

void computePermutations(string str, int len)
{
	int opSize = pow(2,len);
	string s;
	string arr[opSize-1];
	for(int counter =1; counter<opSize; counter++)
	{
		s.clear();
		for(int j=0; j<len; j++)
		{
			if(counter & (1<<j))
			{
				s += str[j]; 		
			}
		}
		arr[counter-1] = s;
	}
	permuteCase(arr, opSize);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		int len = str.length();
		computePermutations(str, len);
	}
	return 0;
}
