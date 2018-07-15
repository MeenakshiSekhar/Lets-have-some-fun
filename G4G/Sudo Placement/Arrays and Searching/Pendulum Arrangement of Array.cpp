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
        int sign = 1;
        int counter = 1;
        b[centre] = arr[0];
        for(int i=1; i<n; i++)
        {
            centre += sign*counter;
            b[centre] = arr[i];
            sign *= -1;
            counter++;
        }
	    for(int i=0; i<n; i++)
	    {
	        cout<<b[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
