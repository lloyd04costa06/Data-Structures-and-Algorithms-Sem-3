#include<stdio.h>
#include<stdlib.h>
void selectionsort(int arr[], int n)
{
    int pos, temp,i,j;
    for(i=0;i<n-1;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[pos])
                pos=j;
        }
        if(i!=pos)
        {
            temp=arr[i];
            arr[i]=arr[pos];
            arr[pos]=temp;
        }
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
    selectionsort(arr, n);
    
    printf("\nARRAY AFTER SORTING: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
