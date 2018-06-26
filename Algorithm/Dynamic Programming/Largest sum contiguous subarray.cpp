//Kadane

#include<iostream>

using namespace std;

int max(int a, int b)
{
	return (a>b) ? a : b;
}

int kadane(int *arr, int size)
{
	int curr_sum = 0;
	int max_sum = arr[0];
	
	for(int i=0; i<size; i++)
	{
		curr_sum = curr_sum + arr[i];
		if(max_sum < curr_sum)
		{
			max_sum = curr_sum;	
		}
		if(curr_sum < 0)
		{
			curr_sum = 0;
		}
	}
	return max_sum;
}

int main()
{
	int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int size = sizeof(arr)/sizeof(int);
	
	cout<<kadane(arr, size);
	return 0;
}
