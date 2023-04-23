#include<stdio.h>
#include<stdlib.h>
struct node
{
	int bits;
	struct node *link;
}*front=NULL,*rear=NULL;

struct reverseStack
{
	int data; 
	struct reverseStack *link;
}*top=NULL;


void insert(int item)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("NO ENOUGH MEMORY\n");
		return;
	}	
	temp->bits=item;
	temp->link=NULL;
	if(front==NULL)
	front=temp;
	else
	rear->link=temp;
	rear=temp;

}


void convert(int dec)
{
	while(dec!=0)
	{
		insert(dec%2);
		dec=dec/2;
	}
	
}



void Rpush(int x)
{	 

	struct reverseStack *temp;
	temp=(struct reverseStack*)malloc(sizeof(struct reverseStack));
	temp->data=x;
	temp->link=top;
	top=temp;
	
 
}
void Rpop()
{
	struct reverseStack *temp,*p;
	p=top;
	while(p!=NULL)
	{
		
		insert(p->data);
		p=p->link;
	}		
}


void display()
{
	struct node *temp;
	
	while(front!=NULL)
	{
		Rpush(front->bits);
			temp=front;

		front=front->link;
		free(temp);
	}
	
	Rpop();
	
	struct node *p=front;
	while(p!=NULL)
	{
		printf("%d",p->bits);
		p=p->link;
	}
	
}

int main()
{
	int decimal;
	printf("ENTER A DECIMAL NUMBER: ");
	scanf("%d",&decimal);
	convert(decimal);
	display();
	
}