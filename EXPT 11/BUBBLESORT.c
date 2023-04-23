#include<stdio.h>
#include<stdlib.h>

void bubblesort(int arr[], int n)
{
    int flag,i,j;
    for(i=0;i<n-1;i++)
    {
        flag=1;
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=0;
            }
        }
        if(flag)
            return;
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
    bubblesort(arr, n);
    printf("\nARRAY AFTER SORTING: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
        printf("\n");
    return 0;
}
