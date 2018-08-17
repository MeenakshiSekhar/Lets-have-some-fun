Given a string - "str", find the repeated character present first in the string.

Example : 
Input  :  geeksforgeeks
Output :  g
          (mind that it will be g, not e.)
          
*******************************************************************************************************************

#include <iostream>
#include<unordered_map>
#include<string.h>
using namespace std;

char findRepeat(string s)
{
    int len = s.length();
    unordered_map<char, int> map;
    int i = 0;
    while(s[i]!='\0')
    {
        map[s[i++]]++;
    }
    i=0;
    while(s[i]!='\0')
    {
        if(map[s[i]]>1)
            return s[i];
        i++;
    }
    return 0;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    char res = findRepeat(s);
	    res==0? cout<<"-1"<<endl :cout<<res<<endl;
	}
	return 0;
}
