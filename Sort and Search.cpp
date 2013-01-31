#include<iostream>
using namespace std;

int sort=0;

void bubble(int arr[], int n)
{
	int i, temp, j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n-i-1; j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	for(i=0; i<n; i++)
		cout<<arr[i]<<" ";

	sort++;
}

void selection(int arr[], int n)
{
	int i, min, minj, temp, j;
	min=10000;
	for(i=0; i<n; i++)
	{
		min = 10000;
		for(j=i; j<n; j++)
		{
			if(arr[j]<min)
			{
				min = arr[j];
				minj = j;
			}
		}
		temp = arr[i];
		arr[i] = min;
		arr[minj] = temp;
	}
	for(i=0; i<n; i++)
		cout<<arr[i]<<" ";

	sort++;
}

void insertion(int arr[], int n)
{
	int i, j, key;
	for(i=1; i<n; i++)
	{
		j=i;
		key = arr[j];
		while(key<arr[j-1] && (j-1)>=0)
		{
			arr[j] = arr[j-1];
			j--;
		}
		arr[j] = key;	
	}
	for(i=0; i<n; i++)
		cout<<arr[i]<<" ";

	sort++;
}

void binsrch(int arr[], int n)
{
	int mid, up=n, low=0, found=0, ele;
	if(!sort)
		cout<<"Array is not sorted\n";
	else
	{
		cout<<"Enter the element being searched for: ";
		cin>>ele;
		while(up != low)
		{
			mid = (up + low)/2;
			if(arr[mid]>ele)
			{
				up = mid;
			}
			else if(arr[mid]<ele)
			{
				low = mid;
			}
			else
			{
				found++;
				cout<<"Element found at index "<<mid;
				break;
			}
		}
		if(!found)
			cout<<"Element does not exist";
	}
}

int main()
{
	int arr[100], n, i, ch, ele;
	char op;
	cout<<"Enter no. of array elements: ";
	cin>>n;
	cout<<"Enter "<<n<<" elements: ";
	for(i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	do {
	cout<<"Select one of the foll.\n1.Bubble Sort\n2.Selection Sort\n3.Insertion Sort\n4.Binary Search(After sorting)";
	cin>>ch;
	switch(ch)
	{
		case 1:
			bubble(arr, n);
			break;
		case 2:
			selection(arr, n);
			break;
		case 3:
			insertion(arr, n);
			break;
		case 4:
			binsrch(arr, n);
	}
	cout<<"Continue? ";
	cin>>op;
	} while(op == 'y');
}