#include<stdio.h>
#include<stdlib.h>
void merge(int arr[], int temp[], int l1, int h1, int l2, int h2)
{
    int k=l1;
    while(l1<=h1 && l2<=h2)
    {
        if(arr[l1]<=arr[l2])
            temp[k++]=arr[l1++];
        else
            temp[k++]=arr[l2++];
    }
    while(l1<=h1)
        temp[k++]=arr[l1++];
    while(l2<=h2)
        temp[k++]=arr[l2++];
}

void copy(int arr[], int temp[], int low, int high)
{
    int i;
	for(i=low;i<=high;i++)
        arr[i]=temp[i];
}
void mergesort(int arr[], int low, int high)
{
    if(low<high)
    {
        int mid=(low+high)/2, temp[50];
        mergesort(arr, low, mid);
        mergesort(arr, mid+1, high);
        merge(arr, temp, low, mid, mid+1, high);
        copy(arr, temp, low, high);
    }
}

int main()
{
    int *arr, n,i;
    printf("ENTER THE SIZE OF THE ARRAY: ");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    
    printf("ENTER THE %d VALUES\n",n);
    for(i=0;i<n;i++)
        scanf("%d,",&arr[i]);
        
    mergesort(arr, 0, n-1);
    printf("\nARRAY AFTER SORTING: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}
