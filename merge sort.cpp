#include<iostream>
using namespace std;

void merge(int a[],int p,int q,int r)
{
	int temp[50], i=p, j=q+1, k=p, l=p;
	
	while((i<=q)&&(j<=r))
	{
		if(a[i]<a[j])
		{
     		temp[k]=a[i];
      		i=i+1;
     		k=k+1;
		}	
		else
		{
     		temp[k]=a[j];
      		j=j+1;
      		k=k+1;
		}
	}
	while(i<=q)
	{
    	temp[k] =a[i];
    	i++;
    	k++;
	}
	while(j<=r)
	{
    	temp[k]=a[j];
    	j++;
    	k++;
	}
	while(l<=r)
	{
		a[l]=temp[l];
		l++;
	}
}

void mergesort(int a[],int p,int r)
{
     if(p<r)
    {
         int q=(p+r)/2;
         mergesort(a,p,q);
         mergesort(a,q+1,r) ;
         merge(a,p,q,r);
     }
}

int main()
{
	int a[50],p,q,r,i,n;
	cout<<"Enter the number of elements(max 50): ";
	cin>>n;
	p=0;
	r=n-1;
	cout<<"Enter the array: ";
	for(i=0;i<n;i++)
		cin>>a[i];
	mergesort(a,p,r);
	cout<<"The sorted array is:\n";
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
}