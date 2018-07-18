#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;

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
	sort(arr, arr+opSize-1);
	for(int counter =0; counter<opSize-1; counter++)
	{
		cout<<arr[counter]<<endl;
	}
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
