#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int front=-1;
int rear = -1;
int q[MAX];

int isFull()
{
	if(rear==MAX-1)
	return 1;
	else
	return 0;
}

int isEmpty()
{
	if(front == -1 || front==rear+1)
	return 1;
	else
	return 0;
}
void insert()
{
	if(isFull())
	{
		printf("QUEUE OVERFLOW\n");
		return;
	}
	
	if(front==-1)
	front=0;
	
	rear++;
	int x;
	printf("ENTER ITEM: ");
	scanf("%d",&x);
	q[rear]=x;
}
void del()
{
	int x;
	if(isEmpty())
	{
		printf("QUEUE UNDERFLOW\n");
		return;
	}
	
	x=q[front];
	front++;
	printf("ITEM DELETED: %d",x);
}

void displayFront()
{
	if(isEmpty())
	{
		printf("QUEUE UNDERFLOW\n");
		return;
	}
	printf("FRONT ELEMENT: %d",q[front]);
}

void display()
{
	int i;
	if(isEmpty())
	{
		printf("QUEUE EMPTY\n");
		return ;
	}
	
	printf("THE QUEUE IS: ");
	for(i=front;i<=rear;i++)
	printf("%d ",q[i]);
	printf("\n");
}
int main()
{
	int choice;
	
	
	while(1)
	{
		printf("\n\nENTER THE CORRESPONDING CHOICES\n");
		printf("1: INSERT AN ELEMENT\n");
		printf("2: DELETE AN ELEMENT\n");
		printf("3: DISPLAY FRONT ELEMENT\n");
		printf("4: DISPLAY ALL THE ELEMENTS\n");
		printf("ENTER YOUR CHOICE: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
			insert();
			break;
			
			case 2:
			del();
			break;
			
			case 3:
			displayFront();
			break;
			
			case 4:
			display();
			break;
			
			default:
			printf("INVALID CHOICE\n");	
		}
	}	
}