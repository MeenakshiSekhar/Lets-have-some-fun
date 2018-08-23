Given an integer N. Your task is to print the pattern.
For example:
Input N=4 
Output : 
4444444 
4333334 
4322234 
4321234 
4322234 
4333334 
4444444 

Input N=3 
Output : 
 33333 
 32223 
 32123 
 32223 
 33333
 
Input:
First line consists of test cases.For each test case only one line be the input containing an integer N.

Output:
For each test case. Print the pattern in single line by giving space instead of new line.

Constraints:
1<=T<=20
1<=N<=20

Example:
Input
1
4

Output
4444444 4333334 4322234 4321234 4322234 4333334 4444444

**************************************************************************************************************************************************

#include <iostream>
#define ll long long
using namespace std;

void print(int num)
{
    int n = num*2-1;
    ll arr[n][n];
    int incr = 0;
    int val = num;
    for(int k=0; k<val; k++)
    {
        for(int i=incr; i<=n-k-1; i++)
        {
            arr[i][k] = num;
            arr[i][n-k-1] = num;
            arr[k][i] = num;
            arr[n-k-1][i] = num;
        }
        incr++;
        num--;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<arr[i][j];
        }
        cout<<" ";
    }
    cout<<endl;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int num;
	    cin>>num;
	    print(num);
	}
	return 0;
}
