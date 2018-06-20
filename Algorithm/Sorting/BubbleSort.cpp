#include<iostream>

using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b =temp;
}

void bubblesort(int *arr, int n)
{
	for(int i=0; i<n-1;i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(arr[i]>arr[j])
			{
				swap(arr[i], arr[j]);
			}
		}
	}
}

void print(int *arr, int size)
{
	for(int i=0; i<size; i++)
	{
		cout<<arr[i]<<"\t";
	}
}

int main()
{
	int arr[] = {64, 34, 25, 12, 22, 11, 90};
	int size = sizeof(arr)/sizeof(int);
	bubblesort(arr, size);
	print(arr, size);
}
