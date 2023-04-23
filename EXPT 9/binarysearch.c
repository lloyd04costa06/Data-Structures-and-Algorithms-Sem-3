#include<stdio.h>
#include<stdlib.h>
void BINARYSEARCH(int arr[], int l, int h, int val)
{
    if(l<=h)
    {
        int mid=(l+h)/2;
        if(val==arr[mid])
        {
            printf("ELEMENT FOUND AT POSITION %d\n",mid+1);
            return;
        }
        else if(val < arr[mid])
            BINARYSEARCH(arr,l,mid-1,val);
        else
            BINARYSEARCH(arr,mid+1,h,val);
    }
    else
        printf("ELEMENT NOT FOUND\n");
}

int main()
{
    int *arr, n, val,i;
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
        printf("ENTER THE SEARCH KEY: ");
        scanf("%d",&val);
   
        BINARYSEARCH(arr,0,n-1,val);
    }
    return 0;
}
