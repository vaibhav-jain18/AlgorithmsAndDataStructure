
// time complexcity = n^2

#include<stdio.h>
int main()                                     
{                                              
    int i,val,size,j,index;
    int a[100];
    scanf("%d",&size);
    for(i=0;i<size;i++)
        scanf("%d",&a[i]);
    for(i=1;i<size;i++)
    {
        val=a[i];
        index=i;
        while(index>=0&&val<a[index-1])             
        {
            a[index]=a[index-1];
            index=index-1;
        }
        a[index]=val;
    }
    for(i=0;i<size;i++)
    printf("%d ",a[i]);
}



  
