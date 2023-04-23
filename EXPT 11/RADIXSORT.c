#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
}*start=NULL, *front[10], *rear[10];

int largedigit()
{
    int large=0, n=0;
    struct node *p=start;
    while(p!=NULL)
    {
        if(large<p->data)
            large=p->data;
        p=p->link;
    }
    while(large!=0)
    {
        large/=10;
        n++;
    }
    return n;
}
int digit(int num, int k)
{
    int i;
	for(i=1;i<k;i++)
        num/=10;
    return num%10;
}

void radixsort()
{
    int least_sig=1, most_sig=largedigit(), dig,i,k;
    struct node *p;
    for(k=least_sig;k<=most_sig;k++)
    {
        for(i=0;i<10;i++)
        {
            front[i]=NULL;
            rear[i]=NULL;
        }
        for(p=start;p!=NULL;p=p->link)
        {
            dig=digit(p->data, k);
            if(front[dig]==NULL)
                front[dig]=p;
            else
                rear[dig]->link=p;
            rear[dig]=p;
        }
        int i=0;
        while(front[i]==NULL)
            i++;
        start=front[i];
        while(i<9)
        {
            if(rear[i+1]!=NULL)
                rear[i]->link=front[i+1];
            else
                rear[i+1]=rear[i];
            i++;
        }
        rear[9]->link=NULL;
    }
}

int main()
{
    struct node *t, *p;
    int *arr, n,i;
    printf("ENTER THE SIZE OF THE ARRAY: ");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    
    printf("ENTER THE %d VALUES\n",n);
    
    for(i=0;i<n;i++)
    {
        t=(struct node*)malloc(sizeof(struct node));
        scanf("%d,",&t->data);
        t->link=NULL;
        if(start==NULL)
            start=t;
        else{
            p=start;
            while(p->link!=NULL)
                p=p->link;
            p->link=t;
        }
    }
    radixsort();
       printf("\nARRAY AFTER SORTING: ");
    p=start;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->link;
    }
    return 0;
}
