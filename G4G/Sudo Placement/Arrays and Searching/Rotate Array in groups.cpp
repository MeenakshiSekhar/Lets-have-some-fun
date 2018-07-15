#include <iostream>
using namespace std;

void rotateArray(int *arr, int n, int d)
{
	for(int i=0; i<n; i+=d)
	{
		int left = i;
		int right = min(i+d-1, n-1);
		while(left<right)
		{
			swap(arr[left++], arr[right--]);
		}
	}
}

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
	    int d;
	    cin>>d;
	    rotateArray(arr,n,d);
	    for(int i=0; i<n; i++)
	    {
		    cout<<arr[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
