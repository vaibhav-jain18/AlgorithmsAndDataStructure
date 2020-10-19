#include<stdio.h>
#define max 13;
int a[11] = {10, 14, 19, 26, 27, 31, 33, 35, 42, 44, 0 };
int b[10];
int mid;
int merge(int a[],int lb,int mid,int ub)
{
    int i=lb;
    int j=mid+1;
    int k=lb;
    while(i<=mid&&j<=ub)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            k++;
            i++;
        }
        else{
            b[k]=a[j];
            j++;
            k++;
        }
    }

    if(i>mid)
    {
        while(j<=ub)
        {
            b[k]=a[j];
            k++;
            j++;
        }
    }

    else{
        while(i<=mid)
        {
            b[k]=a[i];
            i++;
            j++;
        }
    }

    for(k=lb;k<=ub;k++)
        a[k]=b[k];
}

int mergesort(int a[],int lb,int ub)
{
    if(lb<ub)
    {
       int mid=(lb+ub)/2;
       mergesort(a,lb,mid);
       mergesort(a,mid+1,ub);
       merge(a,lb,mid,ub);
    }
}

int main()
{
    int i,lb,ub;

   printf("array before sorting\n");
   
   for(i = 0; i <= 10; i++)
      printf("%d ", a[i]);

   mergesort(a,0,10);

   printf("\narray after sorting\n");
   
   for(i = 0; i <= 10; i++)
      printf("%d ", a[i]);
}

