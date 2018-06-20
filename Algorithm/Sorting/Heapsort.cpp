#include<iostream>

using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b =temp;
}

void heapify(int *arr, int n, int i)
{
	int largest =i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	
	if(l<n && arr[l]>arr[largest])
	{
		largest = l;
	}
	if(r<n && arr[r]>arr[largest])
	{
		largest = r;
	}
	if(largest != i)
	{
		swap(arr[largest], arr[i]);
		heapify(arr, n, largest);
	}
}

void heapsort(int *arr, int n)
{
	for(int i= n/2 -1; i>=0; i--)
	{
		heapify(arr, n, i);
	}
	
	for(int i=n-1; i>=0; i--)
	{
		swap(arr[i], arr[0]);
		heapify(arr, i,0);
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
	heapsort(arr, size);
	print(arr, size);
}
