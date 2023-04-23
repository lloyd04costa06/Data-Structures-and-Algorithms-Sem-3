#include<stdio.h>
#include<stdlib.h>

void LINEARSEARCH(int arr[], int n, int val)
{
	int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==val)
        {
            printf("ELEMENT FOUND AT LOCATION %d\n",i+1);
            return;
        }
    }
    printf("ELEMENT NOT FOUND\n");
}
int main()
{
    int *arr, n, val, i;
    printf("ENTER THE SIZE OF THE ARRAY: ");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    printf("ENTER THE %d VALUES\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d,",&arr[i]);
    }
    while(1)
    {
        printf("\nENTER THE SEARCH KEY: ");
        scanf("%d",&val);
        LINEARSEARCH(arr,n,val);
        return 0;
    }
    return 0;
}
