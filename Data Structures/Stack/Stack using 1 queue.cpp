#include<bits/stdc++.h>
using namespace std;

class Stack
{
	queue<int> q;
	int size;
	public:
	Stack()
	{
		size = 0; 	
	}	
	
	void push(int n)
	{
		size++;
		q.push(n);
		
		int temp = size;
		while(temp-- > 1)
		{
			int front = q.front();
			q.pop();
			q.push(front);
		}
	}
	
	int pop()
	{
		if(!q.empty())
		{
			int top = q.front();
			q.pop();
			return top;
		}
	}
};

int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	return 0;
}
