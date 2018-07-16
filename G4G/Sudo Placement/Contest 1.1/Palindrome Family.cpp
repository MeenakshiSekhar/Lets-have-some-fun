/* Given a string of lowercase characters. You need to detect the family of string, where family of string is described as follows :
Odd Palindrome : String with characters at odd index (1-based indexing) forming Palindrome.
Even Palindrome : String with characters at even index (1-based indexing) forming Palindrome.
TWIN Palindrome : String with both of the above properties.
Parent Palindrome : If the string is itself a Palindrome.
If string is not in the family, print “ALIEN” (without quotes).

If the string is not ALIEN then the priority of plaindromes goes like PARENT > TWIN > EVEN/ODD.

Input :
First line of input contains number of testcases T. For each testcase, there will be a single line containing the string.

Output :
For each testcase, output a single line “ODD”/ “EVEN”/ “TWIN”/ “PARENT”/ "ALIEN" (without quotes).
Constraints :
1 <= T <= 210
1 <= String Length <= 105

Example :
Input :
3
geeks
geeksforskeeg
aibohobia

Output :
ALIEN
ODD
PARENT*/


#include <iostream>
using namespace std;

int checkString(string s)
{
	int len = s.length();
	for(int i=0, j=len-1; i<len/2, j>=i; i++, j--)
	{
		if(s[i]!=s[j])
			return 0;
	}
	return 1;
}

string createOdd(string s)
{
    long len = s.length();
    string odd;
    for(long i=0; i<len; i+=2)
    {
        odd+=s[i];
    }
    return odd;
}

string createEven(string s)
{
    long len = s.length();
    string even;
    for(long i=1; i<len; i+=2)
    {
        even+=s[i];
    }
    return even;
}

int checkPalin(string s)
{
    if(checkString(s))
        return 1;
    string odd = createOdd(s);
    string even = createEven(s);
    if(checkString(odd) && checkString(even))
    {
        return 2;
    }
    else if(checkString(odd))
    {
        return 3;
    }
    else if(checkString(even))
    {
        return 4;
    }
    else
    {
        return 5;
    }
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int result = checkPalin(s);
	    switch(result)
	    {
	        case 1: cout<<"PARENT"<<endl;break;
	        case 2: cout<<"TWIN"<<endl;break;
	        case 3: cout<<"ODD"<<endl;break;
	        case 4: cout<<"EVEN"<<endl;break;
	        case 5: cout<<"ALIEN"<<endl;break;
	    }
	}
	return 0;
}
