#include <iostream>
using namespace std;

string findWinner(int *a, int *b, int n)
{
    string res;
    int aTeam = 0, bTeam = 0;
    for(int i=0; i<n; i++)
    {
        if(a[i]!=b[i])
        {
            if(a[i]>b[i])
            {
                aTeam++;
            }
            else
            {
                bTeam++;
            }
        }
    }
    res+=aTeam+'0';
    res+=" ";
    res+=bTeam+'0';
    res+=" ";
    if(aTeam == bTeam)
    {
        cout<<aTeam<<" "<<bTeam<<" "<<"DRAW"<<endl;
    }
    else
    {
        if(aTeam>bTeam)
        {
            cout<<aTeam<<" "<<bTeam<<" "<<"A"<<endl;
        }
        else
        {
            cout<<aTeam<<" "<<bTeam<<" "<<"B"<<endl;
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
	    int a[n], b[n];
	    for(int i=0; i<n; i++)
	    {
	        cin>>a[i];
	    }
	    for(int i=0; i<n; i++)
	    {
	        cin>>b[i];
	    }
	    findWinner(a,b,n);
	}
	return 0;
}
