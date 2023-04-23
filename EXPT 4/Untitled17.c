#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*last=NULL;


void addatemp()
{
	struct node *t=(struct node*)malloc(sizeof(struct node));
	printf("ENTER THE DATA: ");
	scanf("%d",&t->data);
	t->next=t;
	last=t;
}

void addatend()
{
	struct node *t=(struct node*)malloc(sizeof(struct node));
	printf("ENTER THE DATA: ");
	scanf("%d",&t->data);
	t->next=last->next;
	last->next=t;
	last=t;
}


void create(int n)
{
	int i;
	if(n==0)
		return;
	addatemp();
	for(i=1;i<n;i++)
		addatend();
}
void display()
{
	if(last==NULL)
	{
		printf("EMPTY LIST\n");
		return;
	}
	struct node *t=last->next;
	do
	{
		printf("%d ",t->data);
		t=t->next;
	}while(t!=last->next);
}

void addatbeg()
{
	struct node *t=(struct node*)malloc(sizeof(struct node));
	printf("ENTER THE DATA: ");
	scanf("%d",&t->data);
	t->next=last->next;
	last->next=t;
}

void addafter()
{
	int item;
	struct node *p=last->next;
	printf("ENTER THE ELEMENT AFTER WHICH YOU WANT TO ADD A NEW ELEMENT: ");
	scanf("%d",&item);
	do
	{
		if(p->data==item)
		{
			struct node *t=(struct node*)malloc(sizeof(struct node));
			printf("ENTER THE DATA: ");
			scanf("%d",&t->data);
			t->next=p->next;
			p->next=t;
			if(p==last)
				last=t;
			return;
		}
		p=p->next;
	}while(p!=last->next);
	printf("ELEMENT NOT FOUND");
}
void addbefore()
{
	int item;
	printf("ENTER THE ELEMENT BEFORE WHICH YOU WANT TO ADD A NEW ELEMENT: ");
	scanf("%d",&item);
	if(last==NULL)
	{
		printf("LIST IS EMPTY\n");
		return;
	}
	struct node *p=last->next;
	if(last->next->data==item)
	{
		addatbeg();
		return;
	}
	do
	{
		if(p->next->data==item)
		{
			struct node *t=(struct node*)malloc(sizeof(struct node));
			printf("ENTER THE DATA: ");
			scanf("%d",&t->data);
			t->next=p->next;
			p->next=t;
			return;
		}
		p=p->next;
	}while(p->next!=last->next);
	printf("ELEMENT NOT FOUND");
}
void delnode()
{
	int data;
	struct node *t, *p;
	if(last==NULL)
	{
		printf("LIST IS EMPTY");
		return;
	}
	printf("ENTER THE DATA: ");
	scanf("%d",&data);
	if(last->next==last)
	{
		if(last->data==data)
		{
			free(last);
			last=NULL;
			return;
		}
		printf("DATA NOT FOUND\n");
		return;
	}
	if(last->next->data==data)
	{
		t=last->next;
		last->next=t->next;
		free(t);
		return;
	}
	p=last->next;
	while(p->next!=last)
	{
		if(p->next->data==data)
		{
			t=p->next;
			p->next=t->next;
			free(t);
			return;
		}
		p=p->next;
	}
	if(last->data==data)
	{
		last=p;
		t=p->next;
		p->next=t->next;
		free(t);
		return;
	}
	printf("DATA NOT FOUND\n");
}
int main()
{
	int ch, n;
	do
	{
			printf("\n\n_________________________________\n");	
		printf("1: CREATE A CIRCULAR LINKEDLIST\n");
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
		
		scanf("%d",&ch);
		printf("\n");
		switch(ch)
		{
			case 1:
				printf("ENTER HOW NODES YOU WANT: ");
				scanf("%d",&n);
				create(n);
				break;
			case 2:
				display();
				break;
			case 3:
				addatemp();
				break;
			case 4:
				addatbeg();
				break;
			case 5:
				addatend();
				break;
			case 6:
				addafter();
				break;
			case 7:
				addbefore();
				break;
			case 8:
				delnode();
				break;
			case 9:
				break;
			default:
				printf("INVALID CHOICE");
		}
		printf("\n\n\n");
	}while(ch!=9);
}
