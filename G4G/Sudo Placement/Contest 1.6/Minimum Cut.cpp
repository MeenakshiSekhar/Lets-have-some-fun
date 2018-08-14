

Given an adjacency matrix and two integers S and T. The task is to find minimum capacity s-t cut of the given network. 
An s-t cut is a cut that requires the source ‘s’ and the sink ‘t’ to be in different subsets, and it consists of edges going from the source’s side to the sink’s side. The capacity of an s-t cut is defined by the sum of the capacity of each edge in the cut-set. 

Input:
The first line consists of T test cases. The first line of each test case consists of V number of vertices. The second line of each test case consists of V*V spaced integers consisting of the weight of edge from ith to jth index. The third line of each test case contains two integers S and T.

Output:
Output single line containing all the vertices which takes the minimum cut from one vertex to other. If there is no min cut edge print  "-1"(without quotes).

Constraints:
1 <= T <= 10
1 <= N <= 50

Example:
Input:
1
6
0 16 13 0 0 0 0 0 10 12 0 0 0 4 0 0 14 0 0 0 9 0 0 20 0 0 0 7 0 4 0 0 0 0 0 0
0 5

Output:
1 3 4 3 4 5

Explanation :
Edges with weight 1 3 4 3 4 5 are the required edges.
