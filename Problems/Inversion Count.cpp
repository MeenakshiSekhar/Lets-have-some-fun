#include<iostream>

using namespace std;

int merge(int *arr, int low, int mid, int high)
{
	int inv_count = 0;
	
	int size1 = mid - low +1;
	int size2 = high - mid;
	
	int i=0;
	int j=0;
	int k=low;
	
	int n1[size1];
	int n2[size2];
	
	for(int temp=0; temp<size1; temp++)
	{
		n1[temp] = arr[temp+low];
	}
	for(int temp=0; temp<size2; temp++)
	{
		n2[temp] = arr[temp+mid+1];
	}
	
	while(i<size1 && j<size2)
	{
		if(n1[i]<=n2[j])
		{
			arr[k++] = n1[i++];
		}
		else
		{
			arr[k++] = n2[j++];
		}
		inv_count += mid - i;
	}
	
	while(i<size1)
	{
		arr[k++] = n1[i++];
	}
	while(j<size2)
	{
		arr[k++] = n2[j++];
	}
}

int mergesort(int *arr, int low, int high)
{
	int mid, inv_count=0;
	if(low<high)
	{
		mid = low + (high-low) / 2;
		inv_count = mergesort(arr, low, mid);
		inv_count += mergesort(arr, mid+1, high);
		inv_count += merge(arr, low, mid, high);
	}
	return inv_count;
}

void print(int *arr, int size)
{
	for(int i=0; i<size; i++)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
}

int main()
{
	int arr[] = {2, 4, 1, 3, 5, 7,6};
	int size = sizeof(arr)/sizeof(int);
	cout<<mergesort(arr, 0, size-1)<<endl;
	print(arr, size);
	return 0;
}
