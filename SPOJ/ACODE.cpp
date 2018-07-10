#include<bits/stdc++.h>

using namespace std;

long long countPermutation(char *str, long long size)
{
	long long dp[size+1] = {0};
	dp[0] = 1;
	for(long long i=1; i<size; i++)
	{
		int num = (str[i-1]-'0') * 10;
		num += (str[i]-'0');
		if(str[i] - '0')
		{
			dp[i] = dp[i-1];
		}
		if(num>9 && num<=26)
		{
			dp[i] += dp[i-2>=0?i-2:0];
		}	
	}
	return dp[size-1];
}

int main()
{
	char str[5005];
	long long size;
	while(cin>>str)
	{
		if(str[0] == '0')
		{
			break;
		}
		size = strlen(str);
		cout<<countPermutation(str, size)<<endl;
	}
	return 0;
}
