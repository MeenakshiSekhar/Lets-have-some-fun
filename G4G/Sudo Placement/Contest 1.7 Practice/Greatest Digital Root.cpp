
Given a number N, you need to find a divisor of N such that the Digital Root of that divisor is the 
greatest among all other divisors of N. If more than one divisors give the same greatest Digital Root 
then output the maximum divisor.

The Digital Root of a non-negative number can be obtained by repeatedly summing the digits of the number 
until we reach to a single digit. Example: DigitalRoot(98)=9+8=>17=>1+7=>8(single digit!)

Input:
The first line of the input contains a single integer T, denoting the number of test cases. 
Then T test cases follow. Each testcase contains one line of input denoting the value of N.

Output:
For each testcase, print the greatest divisor having the greatest Digital Root followed by a space 
and the Digital Root of that divisor.
 

Constraints:
1<=T<=500
1<=N<=1012

Example:
Input:
2
10
18

Output:
5 5
18 9

************************************************************************************************************************

#include <iostream>
#include<algorithm>
#include<climits>
#define ll long long
using namespace std;

int computeMaxDigt(ll n, ll sum)
{
    while(n>0)
    {
        sum+=n%10;
        n/=10;
    }
    if(sum>=10)
    {
        computeMaxDigt(sum, 0);
    }
    else
    {
        return sum;
    }
}

void digitalRoot(ll n)
{
    ll arr[n];
    arr[0]=1;
    ll k=1;
    for(ll i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            if(n/i == i)
            {
                arr[k++] = n/i;
            }
            else
            {
                arr[k++] = i;
                arr[k++] = n/i;
            }
        }
    }
    arr[k++] = n;
    sort(arr, arr+k);
    int maxDigt = INT_MIN;
    ll maxDiv = arr[0];
    for(ll i=0; i<k; i++)
    {
        ll temp = computeMaxDigt(arr[i], 0);
        if(temp>=maxDigt)
        {
            maxDigt = temp;
            if(arr[i]>maxDiv)
            {
                maxDiv = arr[i];
            }
        }
    }
    cout<<maxDiv<<" "<<maxDigt<<endl;
}



int main() {
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    digitalRoot(n);
	}
	return 0;
}
