#include <iostream>
#define ll long long
using namespace std;

ll lcm(ll num, ll prod)
{
    return num/prod;
}

ll gcd(ll n1, ll n2)
{
    if(n2 == 0)
        return n1;
    return gcd(n2, n1%n2);
}

int main() {
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n1, n2;
	    cin>>n1>>n2;
	    ll hcf = gcd(n1,n2);
	    cout<<lcm(n1*n2, hcf)<<" "<<hcf<<endl;
	}
	return 0;
}
