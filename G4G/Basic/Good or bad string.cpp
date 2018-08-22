In this problem, a String is composed of lowercase alphabets and wildcard characters i.e. '?'. 
Here, '?' can be replaced by any of the lowercase alphabets. Now you have to classify the given 
String on the basis of following rules:

If there are more than 3 consonants together or more than 5 vowels together, 
the String is considered to be "BAD". A String is considered "GOOD" only if it is not “BAD”.

NOTE: String is considered as "BAD" if the above condition is satisfied even once. 
Else it is "GOOD" and the task is to make the string "BAD".

Input:
The first line consists of an integer T i.e number of test cases.
The first and only line of each test case consists of a string s. 

Output:
If the string is GOOD,  Print "1"  else print "0".

Constraints: 
1<=T<=100
1<=|Length of string|<=100

Example:
Input:
2
aeioup??
bcdaeiou??

Output:
1
0

*************************************************************************************************************************
#include <iostream>
using namespace std;

int goodString(string s)
{
    int len = s.length();
    int cons = 0;
    int vowel = 0;
    int curr = 0;
    int dummy = 0;
    for(int i=0; i<len; i++)
    {
        if(cons >3 || vowel>5)
        {
            return 0;
        }
        if(s[i]=='?')
        {
            dummy++;
        }
        if(s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u'&&s[i]!='?')
        {
            if(dummy>0)
            {
                cons+=dummy;
            }
            cons++;
            vowel = 0;
        }    
        else if(s[i]!='?')
        {
            if(dummy>0)
            {
                vowel+=dummy;
            }
            vowel++;
            cons = 0;
        }
    }
    return 1;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    cout<<goodString(s)<<endl;
	}
	return 0;
}
