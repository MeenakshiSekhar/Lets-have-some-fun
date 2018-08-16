#include <iostream>
#define ll long long
using namespace std;

string power(ll n)
{
    if((n!=0) && (n&(n-1))==0)
        return "YES";
    return "NO";
}

int main() {
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    cout<<power(n)<<endl;
	}
	return 0;
}
