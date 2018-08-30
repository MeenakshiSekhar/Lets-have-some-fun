/*Given q number of queries, you need to perform operations on stack. Operations to be performed are listed below:
Query Type            :               Operation
      1                        :               Push
      2                        :               Pop
      3                        :               Top (To print the top)

Input :
First line of input contains number of testcases T. For each testcase, first line contains Q (Number of Queries). 
Next Q lines contains the queries of any of the three type (1, 2, 3) with element to be pushed (during the push operation).

Output :
For each testcase, if the operation is to push (1) then push the elments, if the operations is to pop (2) 
then pop the element and if it is Top (3), then print the element at the top of stack 
(If stack is empty, print “-1”, without quotes).

Constraints :
1 <= T <= 100
1 <= Si <= 106
1<=Q<=200

Example :
Input :
1
6
3
1 5
1 6
1 7
2
3

Output :
-1
6*/

/*********************************************************************************************************************/
#include<iostream>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        stack<ll> s;
        while(q--)
        {
            int op;
            cin>>op;
            int val;
            if(op == 1)
            {
                cin>>val;
            }
            switch(op)
            {
                case 1: s.push(val); break;
                case 2: if(!s.empty())
                            s.pop();
                        break;
                case 3: if(s.empty())
                        {
                            cout<<"-1"<<endl;
                        }
                        else
                        {
                            cout<<s.top()<<endl;
                        }
                        break;
            }
        }
    }
    return 0;
}
