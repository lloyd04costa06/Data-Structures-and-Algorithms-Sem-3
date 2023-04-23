#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
 struct	node *link;
}*front=NULL,*rear=NULL;

int isEmpty()
{
	if(front==NULL)
	return 1;
	else
	return 0;
}
void insert(int item)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("NO ENOUGH MEMORY\n");
		return;
	}	
	temp->info=item;
	temp->link=NULL;
	if(front==NULL)
	front=temp;
	else
	rear->link=temp;
	rear=temp;
}

int del()
{
	struct node *temp;
	int item;
	if(isEmpty())
	{
		printf("QUEUE UNDERFLOW\n");
		exit(1);
	}
	temp=front;
	item=temp->info;
	front=front->link;
	free(temp);
	return item;
	
}
int peek()
{
	if(isEmpty())
	{
		printf("QUEUE UNDERFLOW\n");
		exit(1);
	}
	return(front->info);
	
}

void display()
{
	struct node *p;
	p=front;
	if(isEmpty())
	{
		printf("QUEUE UNDERFLOW\n");
		exit(1);
	}
	printf("QUEUE ELEMENTS: ");
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->link;
	}
	printf("\n");
}

int main()
{
	int choice,item;
	while(1)
	{
		printf("\n\nLINKED LIST IMPLEMENTATION OF A QUEUE\n");
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