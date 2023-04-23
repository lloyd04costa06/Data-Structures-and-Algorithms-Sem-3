#include<stdio.h>
#include<stdlib.h>
struct DLL
{
	struct DLL *prev;
	int data;
	struct DLL *next;
}*start=NULL;

struct CLL
{
	int data;
	struct CLL *next;
}*last=NULL;

void addtoCLL(int data)
{
	struct CLL *t=(struct CLL*)malloc(sizeof(struct CLL));
	t->data=data;
	if(last==NULL)
	{
		t->next=t;
		last=t;
	}
	else
	{
		t->next=last->next;
		last->next=t;
		last=t;
	}
}
void addtoDLL(int data)
{
	struct DLL *t=(struct DLL*)malloc(sizeof(struct DLL)), *p=start;
	t->data=data;
	if(start==NULL)
	{
		t->prev=NULL;
		t->next=NULL;
		start=t;
	}
	else
	{
		while(p->next!=NULL)
			p=p->next;
		p->next=t;
		t->prev=p;
		t->next=NULL;
	}
}
void add()
{
	struct CLL *p=last->next, *q=p->next;
	if(p==q)
	{
		addtoDLL(p->data);
		return;
	}
	do
	{
		addtoDLL(p->data+q->data);
		p=q->next;
		q=p->next;
	}while(p!=last->next && q!=last->next);
	if(q==last->next)
	{
		addtoDLL(last->data);
	}
}
void display()
{
	struct DLL *t=start;
	printf("AFTER ADDING CONSECUTIVE NODES: ");
	while(t!=NULL)
	{
		printf("%d ",t->data);
		t=t->next;
	}
}
int main()
{
	 long int n;
	printf("ENTER THE NUMBER: ");
	scanf("%d",&n);
	while(n!=0)
	{
		addtoCLL(n%10);
		n/=10;
	}
	add();
	display();
	return 0;
}
