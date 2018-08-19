You have records of employee name and salary.You have to sort the records on the basis of employee salary,
if same then by employee name.

Input:
The first line consists of a number T denoting the number of test cases.Each test case will consist of a 
integer N denoting number of employees followed by the name and salary of the employee with spaces.

Output:
Each test case consists of a single line. It consists of the name and salary of the employees with spaces.

Constraints:
1<=T<=200
1<=N<=1000
1<=Max length of name <= 100
1<= salary of employee <=10^6

Example:
Input:
2
2
xbnnskd 100 geek 50
2
shyam 50 ram 50
Output:
geek 50 xbnnskd 100
ram 50 shyam 50

**************************************************************************************************************************

#include <iostream>
#include<algorithm>
#define ll long long
using namespace std;

struct emp
{
    ll sal;
    string name;
};

bool compare(emp a, emp b)
{
    if(a.sal!=b.sal)
        return a.sal < b.sal;
    return a.name < b.name;
}

void sortEmp(struct emp *e, ll n)
{
    sort(e, e+n, compare);
}

int main() {
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    struct emp e[n];
	    for(ll i=0; i<n; i++)
	    {
	        cin>>e[i].name>>e[i].sal;
	    }
	    sortEmp(e, n);
	    for(ll i=0; i<n; i++)
	    {
	        cout<<e[i].name<<" "<<e[i].sal<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
