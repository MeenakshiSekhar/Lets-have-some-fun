Given a dictionary of words where each word follows CamelCase notation, print all words in the dictionary 
that match with a given pattern consisting of uppercase characters only.

CamelCase is the practice of writing compound words or phrases such that each word or abbreviation begins 
with a capital letter. Common examples include: “PowerPoint” and “WikiPedia”, “GeeksForGeeks”, “CodeBlocks”, etc.

Input:
The first line of input contains an integer T denoting the number of test cases. 
Then the description of T test cases follow. Each test case contains an integer n 
denoting the number of words in the dictionary. The next line contains the vector of strings in the dictionary. 
The last line contains the pattern.

Output:
Print all words in the dictionary that match with a given pattern consisting of uppercase characters
only in lexicographic order. If the pattern is not found, print "No match found" (without quotes).

Constraints:
1<=T<=100
1<=n<=100
1<=length of string<=100
1<=length of patter<=length of string<=100

Example:
Input:
2
8
Hi Hello HelloWorld HiTech HiGeek HiTechWorld HiTechCity HiTechLab
HA
3
WelcomeGeek WelcomeToGeeksForGeeks GeeksForGeeks
WTG

Output:
No match found
WelcomeToGeeksForGeeks

Explanation:
Testcase 1 : In the given input dictionary, there is no word with H and A as starting uppercase letters of word.
Testcase 2 : In the given dictionary, WelcomeToGeeksForGeeks is the word having WTG as the continuous 
uppercase letters right from start.

**********************************************************************************************************************

#include <iostream>
#include<cstring>
using namespace std;

string camelCase(string *arr, int n, string acro)
{
    for(int i=0; i<n; i++)
    {
        int k = 0;
        int len = arr[i].length();
        string s = arr[i];
        for(int j=0; j<len; j++)
        {
            if((!acro.empty()) && (isupper(s[j]) && s[j] == acro[k]) )
            {
                k++;
                if(k == acro.length())
                {
                    return s;
                }
            }
        }
    }
    return "No match found";
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string arr[n];
	    for(int i=0; i<n; i++)
	    {
	        cin>>arr[i];
	    }
	    string acro;
	    cin>>acro;
	    cout<<camelCase(arr, n, acro)<<endl;
	}
	return 0;
}
