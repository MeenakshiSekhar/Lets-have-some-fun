#include<bits/stdc++.h>

using namespace std;

class Stack
{
	queue<int> q1, q2;
	
	int size;
	public:
	Stack()
	{
		size = 0;
	}
	
	void push(int x)
	{
		size++;
		q2.push(x);
		
		while(!q1.empty())
		{
			q2.push(q1.front());
			q1.pop();
		}
		
		queue<int> q = q1;
		q1 = q2;
		q2 = q;
	}
	
	int pop()
	{
		if(!q1.empty())
		{
			int top = q1.front();
			q1.pop();
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
