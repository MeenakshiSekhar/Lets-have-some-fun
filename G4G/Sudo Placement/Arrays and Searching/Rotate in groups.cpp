#include <iostream>
using namespace std;

void reverse(int *arr, int start, int end)
{
    while(start<end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void print(int *arr, int size)
{
	cout<<"called print"<<size<<endl;
	
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
	    int size = n;
	    cin>>d;
	    int i=0;
	    while(n>=0)
	    {
	        if(n/d>0)
	        {
	            reverse(arr, i, i+d-1);
	        }
	        else
	        {
	            reverse(arr, i, i+(n%d)-1);
	        }
	        i+=d;
	        n=n-d;
	    }
	    for(int i=0; i<size; i++)
	    {
		    cout<<arr[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
