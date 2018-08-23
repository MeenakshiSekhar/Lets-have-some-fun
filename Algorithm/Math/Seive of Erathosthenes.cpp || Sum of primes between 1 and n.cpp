#include<iostream>
#include<string.h>
#define ll long long
using namespace std;

ll primes(ll n)
{
	bool arr[n+1];
	memset(arr, true, n+1);
	for(ll p = 2; p*p<=n; p++)
	{
		if(arr[p] == true)
		{
			for(ll x=p*2; x<=n; x+=p)
			{
				arr[x] = false;
			}
		}
	}
	ll sum_of_primes = 0;
	for(ll i=2; i<=n; i++)
	{
		if(arr[i])
		{
			sum_of_primes += i;
		}
	}
	return sum_of_primes;
}

int main()
{
	ll n;
	cin>>n;
	cout<<primes(n)<<endl;
	return 0;
}

********************************************************************************************************************************
#include<iostream>
#include<string.h>
#define ll long long
using namespace std;

ll primes(ll n)
{
	bool arr[n+1];
	memset(arr, true, n+1);
	for(ll p = 2; p*p<=n; p++)
	{
		if(arr[p] == true)
		{
			for(ll x=p*2; x<=n; x+=p)
			{
				arr[x] = false;
			}
		}
	}
	ll sum_of_primes = 0;
	for(ll i=2; i<=n; i++)
	{
		if(arr[i])
		{
			sum_of_primes += i;
		}
	}
	return sum_of_primes;
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
	    cin>>n;
	    cout<<primes(n)<<endl;
    }
	return 0;
}
