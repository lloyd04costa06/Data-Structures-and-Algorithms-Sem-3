#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *prev;
	int data;
	struct node *next;	
}*last=NULL;

void addEmpty(int data)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    last=temp;
    temp->next=temp;
    temp->prev=temp;
}
void addEnd(int data)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    
    temp->prev=last;
    temp->next=last->next;
    temp->next->prev=temp;
    last->next=temp;
    last=temp;
}

void display()
{
    struct node *p;
   
    if(last==NULL)
    {
        printf("\nTHE LIST IS EMPTY\n");
        return;
    }
    p=last->next;
    printf("THE LIST IS CIRCULAR DOUBLY LINKED LIST: ");
    do{
        printf("%d ",p->data);
        p=p->next;
    }while(p!=last->next);

}

void createList()
{
	int i,remainder,x,n,data;
    printf("ENTER A NUMBER: ");
    scanf("%d",&n);
    
    x=n;
    data=x%10;
    x=x/10;
	addEmpty(data);
	
	while(x!=0)
    {
        data=x%10;
        addEnd(data);
        x=x/10;
    }
	return;		
}


struct node *adEnd(struct node *start, int x)
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
struct  node *adEmpty(struct node *start,int x)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	temp->prev=NULL;
	start=temp;	
	return start;
}
struct node *createLt(struct node *start)
{
	int i,data,n;
    struct node *temp=last->next;
    data= (temp->data) + (temp->next->data);
	start=adEmpty(start,data);

    temp=temp->next;
    while(temp->next!=last->next)
    {
       data= (temp->data)+(temp->next->data);
        start=adEnd(start,data);
        temp=temp->next;
    }
	return start;		
}
void displayDLL(struct node *start)
{
	struct node *p;
	p=start;
	
	if(start==NULL)
	{
		printf("LINKED LIST EMPTY\n");
		return;
		
	}
	
	while(p!=NULL)
	{
		printf("%d ",p->data);
	    p=p->next;
	}
	printf("\n");
}


int main()
{
    struct node *start;
    createList();
    display();
    start=createLt(start);
    printf("\nAFTER ADDING SUBSEQUENT ELEMENTS OF CIRCULAR LINKED LIST: ");
    displayDLL(start);

    
}