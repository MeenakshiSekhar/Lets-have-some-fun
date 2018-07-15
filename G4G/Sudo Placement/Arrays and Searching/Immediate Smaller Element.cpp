#include <iostream>
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
	        if(i != 0)
	        {
	            (arr[i-1]>arr[i]) ? cout<<arr[i]<<" " : cout<<"-1 ";
	        }
	    }
	    cout<<"-1"<<endl;
	}
	return 0;
}
