#include<bits/stdc++.h>

using namespace std;

struct item
{
	int weight;
	int value;
	
	item(int weight, int value) : weight(weight), value(value)
	{}
};

bool compare(struct item t1, struct item t2)
{
	double d1 = (double)t1.value/t1.weight;
	double d2 = (double)t2.value/t2.weight;
	return d1>d2;
}

double fractionalKnapsack(int w, struct item *list, int size)
{
	sort(list, list+size, compare);
	
	int currentWt = 0;	
	double maxValue = 0.0;

	for(int i=0; i<size; i++)
	{
		if((currentWt + list[i].weight ) <= w)
		{
			currentWt += list[i].weight;
			maxValue += list[i].value;
		}
		else
		{
			int rem = w - currentWt;
			maxValue += list[i].value * ((double)rem/list[i].weight);
			break;
		}
	
	}
	return maxValue;
}

int main()
{
	item list[] = {{10,60}, {20,100}, {30, 120}};
	int size = sizeof(list)/ sizeof(item);
	
	int w = 45;
	cout<<fractionalKnapsack(w, list, size);
  return 0;
}
