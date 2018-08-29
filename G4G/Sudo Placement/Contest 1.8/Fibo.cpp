#include <iostream>
#define ll long long
using namespace std;

void fibo(ll n)
{
    ll c=n+5;
    ll f[c];
    f[2] = 1;
    f[1] = 1;
    for(ll i=3; i<c; i++)
    {
        f[i] = (f[i-1]+f[i-2])%100;
    }
    ll val = f[n]%100;
    cout<<val<<endl;
}

int main() {
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    fibo(n);
	}
	return 0;
}
