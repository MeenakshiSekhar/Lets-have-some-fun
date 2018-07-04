#include<iostream>
#include<algorithm>

using namespace std;

int max(int a, int b)
{
	return (a>b) ? a : b;
}

string lcs(string str1, int size1, string str2, int size2)
{
	int dp[size1+1][size2+1];
	string result;
	for(int i=0; i<=size1; i++)
	{
		for(int j=0; j<=size2; j++)
		{
			if(i==0 || j==0)
			{
				dp[i][j] = 0;
			}
			else if(str1[i-1] == str2[j-1])
			{
				dp[i][j] = max(1+dp[i][j-1], dp[i-1][j]);
			}
			else if(dp[i][j-1] > dp[i-1][j])
			{
				dp[i][j] = dp[i][j-1];
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	for(int i=size1, j=size2; i>=0, j>=0; )
	{
		if(i==0 || j==0)
			break;
		if(dp[i][j-1] == dp[i-1][j])
		{
			if(dp[i][j]>dp[i-1][j-1] || dp[i][j]>dp[i-1][j])
			{
				result += str1[i-1];
			}
			i--;
			j--;
		}
		else if(dp[i-1][j] > dp[i][j-1])
		{
			i--;
		}
		else if(dp[i][j-1] > dp[i-1][j])
		{
			j--;
		}
	}
	reverse(result.begin(), result.end());
	return result;
}

int main()
{
	string str1 = "bangaloreisabeautifulplace";
	string str2 = "iusedtowatchchottabheem";
	
	string commonSeq = lcs(str1, str1.length(), str2, str2.length());
	cout<<commonSeq<<endl;
	return 0;
}
