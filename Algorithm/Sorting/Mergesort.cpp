#include<iostream>

using namespace std;

void merge(int *arr, int left, int middle, int right)
{
	int i = 0;
	int j = 0;
	int k = left;
	
	int n1 = middle - left + 1;
	int n2 = right - middle;
	
	int L[n1];
	int R[n2];
	
	for(int temp=0; temp<n1; temp++)
	{
		L[temp] = arr[temp+left];
	}
	for(int temp=0; temp<n2; temp++)
	{
		R[temp] = arr[middle+temp+1];
	}
	
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			arr[k++] = L[i++];
		}
		else
		{
			arr[k++] = R[j++];
		}
	}
	
	while(i<n1)
	{
		arr[k++] = L[i++];
	}
	while(j<n2)
	{
		arr[k++] = R[j++];
	}
	
}

void mergesort(int *arr, int left, int right)
{
	if(right >left)
	{
		int middle = left + (right-left)/2;
		mergesort(arr, left, middle);
		mergesort(arr, middle+1, right);
		merge(arr, left, middle, right);
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
	mergesort(arr, 0, size-1);
	print(arr, size);
}
