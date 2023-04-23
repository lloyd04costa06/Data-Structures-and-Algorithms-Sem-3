#include<stdio.h>
#include<stdlib.h>
void insertionsort(int arr[], int n)
{
    int j, temp,i;
    for(i=1;i<n;i++)
    {
        j=i-1;
        temp=arr[i];
        while(arr[j]>temp && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

int main()
{
    int n, *arr,i;
	printf("ENTER THE SIZE OF THE ARRAY: ");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    
    printf("ENTER THE %d VALUES\n",n);
    for(i=0;i<n;i++)
        scanf("%d,",&arr[i]);
        
    insertionsort(arr, n);
    printf("\nARRAY AFTER SORTING: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
        printf("\n");
    return 0;
}
