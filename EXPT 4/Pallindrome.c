#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *prev;
	int data;
	struct node *next;	
};

struct  node *addEmpty(struct node *start,int x)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	temp->prev=NULL;
	start=temp;	
	return start;
}

struct node *addEnd(struct node *start, int x)
{
	struct node *temp,*p;
	temp=(struct node*)malloc(sizeof(struct node));
	
	temp->data=x;
	p=start;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	
	p->next=temp;
	temp->prev=p;
	temp->next=NULL;
	return start; 		
}

struct node *createList(struct node *start)
{
	int i,data,n;
	printf("ENTER NUMBER OF NODES\n");
	scanf("%d",&n);
	
	
	start=NULL;
	if(n==0)
	{
		return start;
	}
	
	printf("ENTER THE DATA OF THE NODE: ");
	scanf("%d",&data);
	
	start=addEmpty(start,data);
	
	
	for(i=2;i<=n;i++)
	{
		printf("ENTER DATA OF THE NODE: ");
		scanf("%d",&data);
		start=addEnd(start,data);
		
	}
	return start;		
}


void display(struct node *start)
{
	struct node *p,*r;
	
	if(start==NULL)
	{
		printf("LINKED LIST EMPTY\n");
		return;
		
	}
    p=start;
	r=start;

    while(r->next!=NULL)
    {
        r=r->next;
    }
	while(p!=NULL)
	{
		
        if(p->data != r->data)
        {
            printf("DOUBLY LINKED LIST NOT PALLINDROME\n");
            return;
        }
     ;
	    p=p->next;
        r=r->prev;
	}
    printf("DOUBLY LINKED LIST IS PALLINDROME\n");
	printf("\n");

}


int main()
{
    struct node *start;
    start=createList(start);
    display(start);
}
