#include<bits/stdc++.h>
using namespace std;

long long hotness(long long *men, long long *women, int n)
{
	long long hotSum = 0;
	sort(men, men+n);
	sort(women, women+n);
	for(int i=0; i<n; i++)
	{
		hotSum += (men[i] * women[i]);
	}
	return hotSum;
}

int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long men[n];
		long long women[n];
		for(int i=0; i<n; i++)
		{
			cin>>men[i];
		}
		for(int i=0; i<n; i++)
		{
			cin>>women[i];
		}
		cout<<hotness(men, women, n)<<endl;
	}
	return 0;
}
