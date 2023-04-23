#include<stdio.h>
#include<stdlib.h>

void restoredown(int arr[], int i, int n)
{
    int left=2*i, right=left+1, num=arr[i];
    while(right<=n)
    {
        if(num>=arr[left] && num>=arr[right])
        {
            arr[i]=num;
            return;
        }
        else if(arr[left]>arr[right])
        {
            arr[i]=arr[left];
            i=left;
        }
        else
        {
            arr[i]=arr[right];
            i=right;
        }
        left=2*i;
        right=left+1;
    }
    if(left==n && num<arr[left])
    {
        arr[i]=arr[left];
        i=left;
    }
    arr[i]=num;
}

void buildheap(int arr[], int n)
{
    int i;
	for(i=n/2;i>=1;i--)
        restoredown(arr, i, n);
}

int del(int arr[], int *n)
{
    int max=arr[1];
    arr[1]=arr[*n];
    (*n)--;
    restoredown(arr,1,*n);
    return max;
}

void heapsort(int arr[], int n)
{
    int max;
    buildheap(arr, n);
    // printf("\nHEAP: ");
    // for(int i=1;i<=n;i++)
    //     printf("%d ",arr[i]);
    // printf("\n");
    while(n>1)
    {
        max=del(arr, &n);
        arr[n+1]=max;
    }
}
int main()
{
    int *arr, n,i;
    printf("ENTER THE SIZE OF THE ARRAY: ");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    
    printf("ENTER THE %d VALUES\n",n);
    for(i=1;i<=n;i++)
        scanf("%d,",&arr[i]);
        
    heapsort(arr, n);
    printf("\nARRAY AFTER SORTING: ");
    for(i=1;i<=n;i++)
        printf("%d ",arr[i]);
        printf("\n");
    return 0;
}
