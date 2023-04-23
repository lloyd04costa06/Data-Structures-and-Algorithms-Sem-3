#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *prev;
	int info;
	struct node *next;
}
struct node *create(struct node *start)
{
	
}
void display(struct node *start)
{
	struct node *p;
	if(start==NULL)
	{
		printf("LIST IS EMPTY\n");
		return;
	}
	p=start;
	printf("THE LIST IS: ");
	while(p!=NULL)
	{
		printf("%d",p->data)
		p=p->link;
	}
	printf("\n");
}
struct node *addEmpty(struct node *start,int data)
{
	struct node *temp;
	temp->info=data;
	temp->prev=NULL;
	temp->next=NULL;
	start=temp;
	return start;
	
}
struct node *addBeg(struct node *start,int data)
{
		struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->info=data;
	temp->prev=NULL;
	temp->next=start;
	start->prev=temp;
	start=temp;
	return start;
}
struct node *addEnd(struct node *start,int data)
{
	struct node *temp,*p;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	p=start;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=temp;
	temp->next=NULL;
	temp->prev=p;
	return start;
	
}
struct node *addAfter(struct node *start, int data)
{
	struct node *temp,*p;
	temp=(struct node *)malloc(sizeof())
}
struct node *addBefore(struct node *start, int data, int item);
struct node *del(struct node *start,int data);

int main()
{
	
}