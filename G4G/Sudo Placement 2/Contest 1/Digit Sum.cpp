Given a positive integer N. Your task is to check if the sum of 1st and last digit of the number 
is equal to the sum of all remaining digits.

Input:
First line of input contains number of testcases T. For each testcase, there will be a single line 
containing a positive integer N.

Output:
For each testcase, print "YES" or "NO" (without quotes).

Task: Your task is to complete the function given in the text area. No need to worry about input and output.

Constraints:
1 <= T < 100
1 <= N <= 106

Example:
Input:
2
12345
10021
Output:
NO
YES


FUNCTIONAL PROBLEM
***************************************************************************************************************

//User function Template for C++
void check(int n)
{
    int sum_firstLast = 0;
    int sum_rem = 0;
    sum_firstLast = n%10;
    n/=10;
    while(n>=10)
    {
        sum_rem += n%10;
        n/=10;
    }
    sum_firstLast += n;
    if(sum_firstLast == sum_rem)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
