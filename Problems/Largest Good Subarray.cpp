/*You are given an array a with n

integers. A subarray is any subset of consecutive elements from this array. Let us call a subarray good 
if its first element is greater than or equal to the last element.

For example, if the given array is (2,5,1,6,4,7)
, then (5,1,6) is a subarray, but it is not a good subarray because 5 is lesser than 6. 
But the subarray (5,1,6,4) is good, because 5≥4.

Find out the length of the largest good subarray.
Input
    The first line of the input contains an integer T
denoting the number of test cases. The description of the test cases follows.
The first line of each test case contains an integer n.
The second line of each test case contains n
space separated integers denoting the array a    .

Output
    For each test case, output an integer corresponding to the answer of the problem.

Constraints
    1≤T≤10

1≤n≤105
1≤ai≤109

Information to score partial points

    For 30% of the score: 1≤n≤103

    Remaining 70%: No extra constraints.

Sample Input

2
6
2 5 1 6 4 7
9
4 4 6 3 4 7 3 5 5

Sample Output

4
7

Explanation

Example case 1: The largest good subarray is (5,1,6,4)

.

Example case 2: One of the largest good subarrays is (6,3,4,7,3,5,5)
. Another such largest good subarray is (4,4,6,3,4,7,3). 

*/





#include <iostream>
#define ll long long
using namespace std;

ll goodArray(ll *arr, ll n)
{
	ll count = 0;
	ll j=0;
	for(ll i=n-1; i>=count; i--)
	{
		for(j=0; j<i; j++)
		{
			if(arr[j]>arr[i] && (count < i-j+1))
			{
				count = i-j+1;
				break;
			}
		}
	}
	return count;
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
		cout<<goodArray(arr, n)<<endl;
	}
	return 0;
}
