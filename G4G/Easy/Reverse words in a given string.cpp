Given a String of length N reverse the whole string without reversing the individual words in it. 
Words are separated by dots.

Input:
The first line contains T denoting the number of testcases. Then follows description of testcases. 
Each case contains a string containing spaces and characters.
 

Output:
For each test case, output a single line containing the reversed String.

Constraints:
1<=T<=20
1<=Lenght of String<=2000


Example:
Input:
2
i.like.this.program.very.much
pqr.mno

**********************************************************************************************************************

#include <iostream>
#define ll long long
using namespace std;

string reverse(string s)
{
    string rev;
    ll arr[1000000];
    ll i = 0, index = 0;
    while(s[i++]!='\0')
    {
        if(s[i]=='.')
            arr[index++] = i;
    }
    i = 0;
    while(--index>=0)
    {
        i = arr[index];
        i++;
        while(s[i]!='\0' && s[i]!='.')
        {
            rev+=s[i++];
        }
        rev+='.';
    }
    i = arr[0];
    ll temp = 0;
    while(temp<i)
    {
        rev+=s[temp++];
    }
    return rev;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    cout<<reverse(s)<<endl;
	}
	return 0;
}
