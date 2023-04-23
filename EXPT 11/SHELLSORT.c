#include<stdio.h>
#include<stdlib.h>

void shellsort(int arr[], int incre, int n)
{
    int j,k,i;
    while(incre>=1)
    {
        for(i=incre;i<n;i++)
        {
            k=arr[i];
            for(j=i-incre;j>=0 && arr[j]>k;j=j-incre)
                arr[j+incre]=arr[j];
            arr[j+incre]=k;
        }
        incre-=2;
    }
}

int main()
{
    int *arr, n,incre,i;
    printf("ENTER THE SIZE OF THE ARRAY: ");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    
    printf("ENTER THE %d VALUES\n",n);
    for(i=0;i<n;i++)
        scanf("%d,",&arr[i]);
        
    printf("ENTER MAXIMUM INCREMENT(ODD VALUE): ");
    scanf("%d",&incre);
    shellsort(arr, incre, n);
    printf("\nARRAY AFTER SORTING: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
         printf("\n");
    return 0;
}
