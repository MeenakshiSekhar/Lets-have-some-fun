Checkout https://practice.geeksforgeeks.org/contest-problem/sp-k-sum/1/

/*


Given head of a linked list of integers and an integer k, your task is to modify the linked list as follows:

    Consider nodes in groups of size k. In every group, replace value of first node with group sum.

    Also, delete the elements of group except the first node.

    During traversal, if the remaining nodes in linkedlist are less than k then also do the above considering remaining nodes.


Input :
First line of input contains number of testcases T. For each testcase, first line contains length of linked list N and K. Second line contains elements of linked list.

Output :
For each testcase, print the modified linked list.

Task :
You are given function to complete with head reference and k as arguments. You only need to complete the function and modify the linked list as required. We will take care of the printing and other required functions.

Constraints :
1 <= T <= 100
1 <= N <= 104
1 <= Elements of Linked List <= 106
1 <= K <= N

Example :
Input :
1
6 2
1 2 3 4 5 6

Output:
3 7 11

Explanation:
For testcase1: k = 2.
We have denoted grouping of k elements by (). The elements inside () are summed.
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> null
(1 -> 2) -> 3 -> 4 -> 5 -> 6 -> null
(3) -> 3 -> 4 -> 5 -> 6 -> null
3 -> (3 -> 4) -> 5 -> 6 -> null
3 -> (7) -> 5 -> 6 -> null
3 -> 7 -> (5 -> 6) -> null
3 -> 7 -> (11) -> null
3 -> 7 -> 11 -> null
*/

*******************************************************************************************************************************
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

void KSum(Node *head, int k)
    {
       struct Node *ptr1, *ptr2;
       struct Node *temp = head;
       while(temp!= NULL)
       {
           ptr1 = temp;
           if(temp->next != NULL)
                ptr2 = temp->next;
            else
                break;
            long long sum = 0;
            int count = k;
            struct Node *prev = NULL;
           while(--count>0 && ptr2 != NULL)
           {
               sum += ptr2->data;
               prev = ptr2;
               ptr2 = ptr2->next;
           }
           ptr1->data = ptr1->data + sum;
           if(ptr2 == NULL)
           {
               ptr1->next = NULL;
               break;
           }
           struct Node *temp1 = ptr1->next;
           free(temp1);
           ptr1->next = ptr2;
           prev->next = NULL;
           temp = ptr1->next;
       }    
    }
