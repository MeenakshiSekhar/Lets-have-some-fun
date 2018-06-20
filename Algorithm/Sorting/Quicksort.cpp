#include<iostream>

using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b =temp;
}

int partition(int *arr, int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;
	int j = low;
	
	for(int j=low; j<=high-1; j++)
	{
		if(arr[j]<=pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[high]);
	return i+1;
}

void quicksort(int *arr, int low, int high)
{
	if(low<high)
	{
		int pi = partition(arr, low, high);
		quicksort(arr, low, pi-1);
		quicksort(arr, pi+1, high);
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
	int arr[] = {64, 34, 25, 12, 22, 11, 90, 67};
	int size = sizeof(arr)/sizeof(int);
	quicksort(arr, 0, size-1);
	print(arr, size);
}
