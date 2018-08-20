
Given an array of items, an i-th index element denotes the item id’s and given a number m, 
the task is to remove m elements such that there should be minimum distinct id’s left.
Print the number of distinct id’s.

Input:
The first line of the input contains a single integer T, denoting the number of test cases. 
Then T test case follows, the three lines of the input, the first line contains N, 
denoting number of elements in an array,second line contains N elements/ids, 
and third line contains the number M.

Output:
For each test case, print the minimum number of distinct ids.

Constraints:
1<=T<=100
1<=N<=100
1<=arr[i]<=10^6
1<=M<=100

Example:
Input:
2
6
2 2 1 3 3 3
3
8
2 4 1 5 3 5 1 3
2
Output:
1
3

************************************************************************************************************************
#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#define ll long long
using namespace std;

bool cmp(const pair<ll, ll> &v1, const pair<ll, ll> &v2)
{
    return v1.second < v2.second;
}

ll minId(ll *arr, ll n, ll m)
{
    unordered_map<ll, ll> mp;
    for(ll i=0; i<n; i++)
    {
        mp[arr[i]]++;
    }
    ll k = 1;
    vector<pair<ll, ll>> vmap(mp.begin(), mp.end());
    sort(vmap.begin(), vmap.end(), cmp);
    ll count = 0;
    vector<pair<ll, ll>> :: iterator itr;
    for(itr= vmap.begin(); itr!=vmap.end(); itr++)
    {
    	if(m>0)
	{
		if(m<itr->second)
		{
			count ++;
			m = 0;
		}
		else
		{
			m-=itr->second;
		}
	}
	else
	{
		count++;
		if(m<0)
		{
			count++;
			m = 0;
		}
	}
    }
    return count;
}

int main() {
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    ll arr[n];
	    for(ll i=0; i<n; i++)
	    {
	        cin>>arr[i];
	    }
	    ll m;
	    cin>>m;
	    cout<<minId(arr, n, m)<<endl;
	}
	return 0;
}
