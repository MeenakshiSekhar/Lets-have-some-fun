Given an array of characters which is basically a sentence. However there is no space between different words and the first letter of every word is in uppercase. You need to print this sentence after following amendments:
(i) Put a single space between these words
(ii) Convert the uppercase letters to lowercase.

Input: 

The first line of input contains the number of test cases. The description of T test case follows.

Each test case contains a single line containing a string.

Output:

Print the desired Sentence.


Constraints:

1<=T<=30

1<=Size of String <=100

Example:

Input : 

2

BruceWayneIsBatman

You

Output : 

bruce wayne is batman

you

***************************************************************************************************************************************

#include <iostream>
using namespace std;

string amendString(string s)
{
    string result;
    int i=0;
    while(s[i]!='\0')
    {
        if(s[i]>=65 && s[i]<=90)
        {
            if(i!=0)
            {
                result+=" ";
            }
            result+=tolower(s[i]);
        }
        else
        {
        	result+=s[i];
        }
        i++;
    }
    return result;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    cout<<amendString(s)<<endl;
	}
	return 0;
}
