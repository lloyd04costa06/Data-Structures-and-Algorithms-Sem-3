#include<stdio.h>
#include<stdlib.h>

struct node{
	int info;
	struct node *link;
}*rear=NULL;

int isEmpty()
{
	if(rear==NULL)
	return 1;
	else
	return 0;
}
void insert(int item)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->info=item;
	if(temp==NULL)
	{
		printf("QUEUE UNDERFLOW\n");
		exit(1);
	}
	if(isEmpty())
	{
		rear=temp;
		temp->link=rear;
	}
	else{
		temp->link=rear->link;
		rear->link=temp;
		rear=temp;
	}
}
int del()
{
	int item;
	struct node *temp;
	if(isEmpty())
	{
		printf("QUEUE UNDERFLOW	\n");
		exit(1);
	}
	if(rear->link==rear)
	{
		temp=rear;
		rear=NULL;
	}
	else{
		temp=rear->link;
		rear->link=rear->link->link;
	}
	item=temp->info;
	free(temp);
	return item;
	
}
void display(){
	struct node *p;
	if(isEmpty())
	{
		printf("QUEUE IS EMPTY\n");
		return;
	}
	printf("QUEUE IS: ");
	p=rear->link;
	do{
		printf("%d ",p->info);
		p=p->link;
		
	}while(p!=rear->link);
	printf("\n");
}

int peek(){
	if(isEmpty())
	{
		printf("QUEUE UNDERFLOW\n");
		exit(1);
	}
	return rear->link->info;
}

int main()
{
	int choice,item;
	while(1)
	{
		printf("\n\nLINKED LIST IMPLEMENTATION OF A CIRCULAR QUEUE\n");
		printf("1: TO INSERT ELEMENTS INTO THE QUEUE\n");
		printf("2: TO DELETE ELEMENTS FROM THE QUEUE\n");
		printf("3: TO DISPLAY THE FRONT ELEMENT OF THE QUEUE\n");
		printf("4: DISPLAY ALL THE ELEMENTS OF THE QUEUE\n");
		printf("\nENTER YOUR CHOICE\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
			printf("ENTER THE ELEMENT: ");
			scanf("%d",&item);
			insert(item);
			break;
			
			case 2:
			item=del();
			printf("%d deleted",item);
			break;
			
			case 3:
			item=peek();
			printf("FRONT ELEMENT: %d",item);
			break;
			
			case 4:
			display();
			break;
		}
	}
}
