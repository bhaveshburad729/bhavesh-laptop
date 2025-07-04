#include <iostream>
using namespace std;
 
void MaxHeapify(int a[], int i, int n)
{
	int j, temp;
	temp = a[i];
	j = 2*i;
 
 	while (j <= n)
	{
		if (j < n && a[j+1] > a[j])
		j = j+1;
		if (temp > a[j])
			break;
		else if (temp <= a[j])
		{
			a[j/2] = a[j];
			j = 2*j;
		}
	}
	a[j/2] = temp;
	return;
}

void Build_MaxHeap(int a[], int n)
{
	int i;
	for(i = n/2; i >= 1; i--)
		MaxHeapify(a, i, n);
}

void Max_HeapSort(int a[], int n)
{
	int i, temp;
	for (i = n; i >= 2; i--)
	{
		temp = a[i];
		a[i] = a[1];
		a[1] = temp;
		MaxHeapify(a,1,i-1);
	}
}

void print(int arr[], int n)
{
cout<<"\nSorted Data ";
 
	for (int i = 1; i <=n; i++)
		cout<<"->"<<arr[i];
 	return;
}


int main()
{
	int n, i, ch;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
	
	int arr[n];
	for(i = 1; i <=n; i++)
	{
		cout<<"Enter element "<<i<<": ";
		cin>>arr[i];
	}
	
	do
	{	
	cout<<"\n1. Heap sort using  max heap";
	cout<<"\n2.Exit";
	

	cout<<"\nenter your choice:";
	cin>>ch;
	switch(ch)
	{
	case 1:	Build_MaxHeap(arr, n);
    	 	Max_HeapSort(arr, n);
       		print(arr, n);
       		break;	
	
	case 2:return 0;
    
	default:cout<<"\n Invalid choice !! Please enter your choice again."<<endl;		
	}
	}while(ch!=2);
}