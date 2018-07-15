#include<iostream>
#include<stack>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    stack<int> s;
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++)
	    {
	        cin>>arr[i];
	    }
	    s.push(arr[n-1]);
	    int curr_max = arr[n-1];
	    for(int i=n-2; i>=0; i--)
	    {
	        if(arr[i]>curr_max)
	        {
	            s.push(arr[i]);
	            curr_max = arr[i];
	        }
	    }
	    while(!s.empty())
	    {
	        cout<<s.top()<<" ";
	        s.pop();
	    }
	    cout<<endl;
	}
	return 0;
}
