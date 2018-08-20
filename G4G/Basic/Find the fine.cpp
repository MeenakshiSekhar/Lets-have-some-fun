Given an array of penalties, an array of car numbers and also the date. 
The task is to find the total fine which will be collected on the given date. 
Fine is collected from odd-numbered cars on even dates and vice versa.

Input:
The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. Each test case consists of three lines. 
First line of each test case contains two integers N & Date, 
second line contains N space separated car numbers and third line contains N space separated penalties.

Output:
For each test case,In new line print the total fine.

Constraints:
1<=T<=100
1<=N<=105
1000<= Car num<=9999
1<=Date<=31
1<=penalty[i]<=103
Example:
Input:
2
4 12
2375 7682 2325 2352
250 500 350 200
3 8
2222 2223 2224
200 300 400
Output:
600
300

***********************************************************************************************************************
#include <iostream>
#define ll long long
using namespace std;

ll sumPenalty(ll *car,ll *penalty, ll n, ll date)
{
    ll sum = 0;
    for(ll i=0; i<n; i++)
    {
        if(date%2==0)
        {
            if(car[i]%2==1)
            {
               sum+=penalty[i]; 
            }
        }
        else 
        {
            if(car[i]%2==0)
            {
               sum+=penalty[i]; 
            }
        }
    }
    return sum;
}

int main() {
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    ll date;
	    cin>>date;
	    ll car[n], penalty[n];
	    for(ll i=0; i<n; i++)
	    {
	        cin>>car[i];
	    }
	    for(ll i=0; i<n; i++)
	    {
	        cin>>penalty[i];
	    }
	    cout<<sumPenalty(car, penalty, n, date)<<endl;
	}
	return 0;
}
