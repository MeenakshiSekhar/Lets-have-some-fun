#include<iostream>

using namespace std;

int equalDivide(long long int *candy, long long int n)
{
	long long int sum = 0;
	for(long long int i =0; i<n; i++)
	{
		sum += candy[i]%n;
	}
	return (sum%n == 0) ? 1:0;
}

int main()
{
	long long int t;
	cin>>t;
	while(t--)
	{
		long long int n;
		cin>>n;
		long long int candy[n];
		for(long long int i=0; i<n; i++)
		{
			cin>>candy[i];
		}
		equalDivide(candy, n) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
	}
	return 0;
}
