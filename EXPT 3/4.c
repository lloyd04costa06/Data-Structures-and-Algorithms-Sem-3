#include<stdio.h>
#include<stdlib.h>
#define max 5

int Cqueue[max];
int front = -1;
int rear = -1;


int isEmpty()
{
	if(front==-1)
	return 1;
	else 
	return 0;
}

int isFull()
{
	if((front==0 && rear==max-1)||(front==rear+1))
	return 1;
	else
	return 0;
}

int peek()
{
	if(isEmpty())
	{
		printf("QUEUE UNDERFLOW\n");
		exit(1);
	}
	return Cqueue[front];
}

void display()
{
	int i;
	if(isEmpty())
	{
		printf("QEUEU IS EMPTY	\n");
		return;
	}
	printf("QUEUE IS: ");
	
	i=front;
	if(front<=rear)
	{
		while(i<=rear)
		printf("%d ",Cqueue[i++]);
	}
	else{
		while(i<=max-1)
		printf("%d ",Cqueue[i++]);
		i=0;
		while(i<=rear)
		printf("%d ",Cqueue[i++]);
		
	}
	printf("\n\n");
}

void insert(int item)
{
	if(isFull())
	{
		printf("QUEUE OVERFLOW\n");
		return;
	}
	if(front == -1)
	front=0;
	
	if(rear==max-1)
	rear=0;
	else
	rear=rear+1;
	Cqueue[rear]=item;
}
	
	
int del()
{
	int item;
	if(isEmpty())
	{
		printf("QUEUE UNDERFLOW\n");
		exit(1);
	}
	item=Cqueue[front];
	
	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else if(front== max-1)
	{
		front=0;
	}
	else
	front=front+1;
	return item;
}



int main()
{
	int choice,item;
	while(1)
	{
		printf("\n\nARRAY IMPLEMENTATION OF A CIRCULAR QUEUE\n");
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