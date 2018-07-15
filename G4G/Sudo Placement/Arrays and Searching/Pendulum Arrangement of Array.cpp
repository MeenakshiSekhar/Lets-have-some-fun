#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++)
	    {
	        cin>>arr[i];
	    }
	    sort(arr, arr+n);
	    int centre = (n-1)/2;
	    int b[n];
	    b[centre] = arr[0];
	    int j = 1;
	    int i = 1;
	    for( i=1; i<=centre; i++)
	    {
	    	b[centre+i] = arr[j++];
	    	b[centre-i] = arr[j++];
	    }
	    if(n%2==0)
	    {
	    	b[centre+i] = arr[j];
	    }
	    for(int i=0; i<n; i++)
	    {
	        cout<<b[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
