#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int a[],int start,int end)
{
	int pivotelement  = a[end];                       // pivotelement = last element
	int pivotindex = start;
	int i;
	for(i=start;i<end;i++)
	{
		if(a[i]<pivotelement)
		{
			swap(&a[i],&a[pivotindex]);
			pivotindex++;
		}
	}
	swap(&a[pivotindex],&a[end]);

	return pivotindex;
}

void quickSort(int a[],int start,int end)
{
    if(start<end)
    {
		int partitionindex = partition(a,start,end);
	    quickSort(a,start,partitionindex-1);
	    quickSort(a,partitionindex+1,end);
    }
}

int main()
{
	int a[5]={11,2,4,12,3};
	int n=5,i;
	quickSort(a,0,n-1);          

	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	
	return 0;
}






