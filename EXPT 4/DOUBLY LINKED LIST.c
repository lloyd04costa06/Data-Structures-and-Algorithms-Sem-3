#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *prev;
	int data;
	struct node *next;	
};

struct node* addAfter(struct node *start,int item,int data)
{
	struct node *temp,*p;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	p=start;
	p=start;
	while(p!=NULL)
	{
		if(p->data==item)
		{
			temp->prev=p;
			temp->next=p->next;
			if(p->next!=NULL)
			p->next->prev=temp;
			p->next!=temp;
			return start;
		}
		p=p->next;
	}
}
struct node* del(struct node *start,int data)
{
	struct node*temp;
	if(start==NULL)
	{
		printf("LIST IS EMPTY\n");
		return start;
	}
	
	if(start->next==NULL)
	{
		temp=start;
		start=NULL;
		free(temp);
		return start;
		
	}
	else
	{
		printf("ELEMENT NO FOUND\n");
		return start;
	}
	if(start->data==data)
	{
		temp=start;
		start=start->next;
		start->prev=NULL;
		free(temp);
		return start;
	}
	
	temp=start->next;
	while(temp->next!=NULL)
	{
		if(temp->data==data)
		{	temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		free(temp);
		return start;
			
		}
		temp=temp->next;	
	}
	
	if(temp->data==data)
	{
		temp->prev->next=NULL;
		free(temp);
		return start;
	}
	printf("THE ELEMENT IS NOT FOUND\n");
	return start;
}
struct node *addBefore(struct node *start, int item,int data)
{
	struct node *temp,*p;
	if(start==NULL)
	{
		printf("THE LIST IS EMPTY\n");
		return start;
	}
	if(start->data==item)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->data=data;
		temp->prev=NULL;
		temp->next= start;
		start->prev=temp;
		start=temp;
		return start;
		
	}
	p=start;
	while(p!=NULL)
	{
		if(p->data==item)
		{
			temp=(struct node *)malloc(sizeof(struct node));
			temp->data=data;
			temp->prev=p->prev;
			temp->next=p;
			p->prev->next=temp;
			p->prev=temp;
			return start;
		}
		p=p->next;	
	}
	printf("ELEMENT IS NOT FOUND\n");
	
}
struct node *addBeg(struct node *start,int data)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->prev=NULL;
	temp->next=start;
	start->prev=temp;
	start=temp;
	return start;
}
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
	struct node *p;
	p=start;
	
	if(start==NULL)
	{
		printf("LINKED LIST EMPTY\n");
		return;
		
	}
	printf("\n\n");
	while(p!=NULL)
	{
		printf("%d ",p->data);
	    p=p->next;
	}
	printf("\n");
}


int main()
{
	int choice,key,data,item;
	struct node *start;
	
	while(1){
		
	printf("_________________________________\n");
	printf("1: CREATE A DOUBLY LINKEDLIST\n");
	printf("2: DISPLAY LINKEDLIST\n");
	printf("3: ADD  TO EMPTY LIST\n");
	printf("4: ADD AT BEGINNING\n");
	printf("5: ADD AT THE END\n");
	printf("6: ADD AFTER A NODE\n");
	printf("7: ADD BEFORE A NODE\n");
	printf("8: DELETE A NODE\n");
	printf("0: PROGRAM END\n");
	printf("_________________________________\n");
	printf("ENTER THE CHOICE\n");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
		start=createList(start);
		break;
		
		case 2:
		display(start);
		break;
		
		case 3:
		printf("ENTER NODE DATA: ");
		scanf("%d",&item);
		start=addEmpty(start,item);
		break;
		
		case 4:
		printf("ENTER NODE DATA: ");
		scanf("%d",&item);
		start=addBeg(start,item);
		break;
		
		case 5:
		printf("ENTER NODE DATA: ");
		scanf("%d",&item);
		start=addEnd(start,item);
		break;
		
		case 6:
		printf("ENTER THE ELEMENT AFTER WHICH YOU WANT TO ADD A NEW ELEMENT\n");
		scanf("%d",&key);
		printf("ENTER THE DATA OF THE NEW NODE\n");
		scanf("%d",&item);
		start=addAfter(start,key,item);
		break;
		
		case 7:
		printf("ENTER THE ELEMENT BEFORE WHICH YOU WANT TO ADD A NEW ELEMENT\n");
		scanf("%d",&key);
		printf("ENTER THE DATA OF THE NEW NODE\n");
		scanf("%d",&item);
		start=addBefore(start,key,item);
		
		case 8:
		printf("ENTER THE ELEMENT TO BE DELETED\n");
		scanf("%d",&key);
		start=del(start,key);
		
		case 0:
		return 0;
		
		default:
		printf("INVLID OPTION\n");
	}
	
	}
}
