/*
You are given 3 stacks, A(Input Stack), B(Auxiliary Stack) and C(Output Stack). 
Initially stack A contains numbers from 1 to N, you need to transfer all the numbers from
stack A to stack C in sorted order i.e in the end, the stack C should have smallest element 
at the bottom and largest at top. You can use stack B i.e at any time you can push/pop elements 
to stack B also. At the end stack A, B should be empty.

Input :
First line of input contains number of test cases T. For each test case, first line contains integer N. 
Second line of each test case contains N space separated integers showing configuration of the stack A from Top to Bottom.

Output :
Print "YES" and number of transfers if it is possible to transfer content from A to C in sorted order otherwise print "NO".

Constraints :
1 <= T <= 100
1 <= N <= 105
1 <= A[i] <= N

Input :
2
5
4 3 1 2 5
5
3 4 1 2 5

Output :
YES 7
NO
*/

/*****************************************************************************************************************/

#include <iostream>
#include<stack>
#define ll long long
using namespace std;

void checkSort(ll *arr, ll n)
{
		stack<ll> s;
		ll count = 0;
		ll min = 1;
		for(ll i=0; i<n; i++)
		{
			if(arr[i] == min)
			{
				count++;
				min++;
			}
			else
			{
				if(!s.empty() && arr[i]>s.top())
				{
					cout<<"NO"<<endl;
					return ;
				}
				else
				{
					s.push(arr[i]);
					count++;
				}
			}
			while(!s.empty() && s.top() == min)
			{
				min++;
				s.pop();
				count++;
			}
		}
		cout<<"YES "<<count<<endl;
}

int main() {
	int t;
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
		checkSort(arr, n);
	}
	return 0;
}
