#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int Qarray[MAX];
int rear=-1;
int front=-1;

int isFull()
{
	if(rear==MAX-1)
	return 1;
	else
	return 0;
}
int isEmpty()
{
	if(front==-1 ||front==rear+1)
	return 1;
	else
	return 0;
}
void insert(int item)
{
	if(isFull())
	{
		printf("QUEUE OVERFLOW\n");
		return;
	}
	if(front==-1)
	front=0;
	rear++;
	Qarray[rear]=item;
}

int del()
{	
	int item;
	if(isEmpty())
	{
		printf("QUEUE UNDERFLOW\n");
		exit(1);
	}
	item=Qarray[front];
	front++;
	return item;
	
}
int peek()
{
	if(isEmpty())
	{
		printf("QUEUE UNDERFLOW\n");
		exit(1);
	}
	return(Qarray[front]);
}
void display()
{
	int i;
	if(isEmpty())
	{
		printf("QUEUE IS EMPTY\n");
		return;
	}
	printf("QUEUE IS : ");
	for(i=front; i<=rear;i++)
	{
		printf("%d ",Qarray[i]);
		
	}
	printf("\n\n");
}

int main()
{
	int choice,item;
	while(1)
	{
		printf("\n\nARRAY IMPLEMENTATION OF A QUEUE\n");
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

