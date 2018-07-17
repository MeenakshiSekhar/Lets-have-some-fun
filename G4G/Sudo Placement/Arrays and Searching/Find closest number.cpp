#include<iostream>

using namespace std;

int findClosest(int *arr, int n, int k)
{
    int prev;
    int curr;
    for(int i=1; i<n; i++)    
    {
        curr = arr[i];
        prev = arr[i-1];
        if(k == prev || k == curr)
        {
            return k;
        }
        if(k<prev)
        {
        	return prev;
        }
        if(k > prev && k < curr)
        {
        	return (k-prev < curr-k) ? prev : curr;
        }
        if(k>curr && i == n-1)
        {
        	return curr;
        }
    }
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    int k;
	    cin>>n;
	    cin>>k;
	    int arr[n];
	    for(int i=0; i<n; i++)
	    {
	        cin>>arr[i];
	    }
	    cout<<findClosest(arr, n, k)<<endl;
	}
	return 0;
}
