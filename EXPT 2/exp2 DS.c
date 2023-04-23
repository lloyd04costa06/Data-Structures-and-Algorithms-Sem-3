/*Expt 2
write a program to implement stacks usin array

a) push
b) pop
c) display top elemt of stack
d) display all stack elements
e) reverse a stack usig two stacks*/


#include<stdio.h>
#define MAX 6
int array[MAX];
int array1[MAX];
int top=-1;
int top1=-1;




int isFull()
{
	if(top==MAX-1)
	return 1;
	else
	 return 0;
}

int isEmpty()
{
	if(top==-1)
	return 1;
	else
	return 0;
}

void display()
{
	int i;
	if(isEmpty())
	{
		printf("STACK IS EMPTY\n");
		return;
	}
	printf("STACK ELEMENTS:\n");
	for(i=top;i>=0;i--)
	{
		printf("%d ",array[i]);
	}
}
void push()
{
	int x;
	printf("ENTER ELEMENT: ");
	scanf("%d",&x);
	if(isFull())
	{
		printf("STACK OVERFLOW\n");
		return;
	}
	top++;
	array[top]=x;

}

void pop()
{
	int x;
	if(isEmpty())
	{
		printf("STACK UNDERFLOW\n");
		return;
	}
	
	x=array[top];
	top--;
	printf("ITEM POPPED IS: %d\n",x);
	
}

void peek()
{
	if(isEmpty())
	{
		printf("STACK UNDERFLOW\n");
		return;
	}
	printf("TOP ELEMENT: %d\n",array[top]);
}




void display2()
{
	int i;
	if(isEmpty())
	{
		printf("STACK IS EMPTY\n");
		return;
	}

	for(i=top1;i>=0;i--)
	{
		printf("%d ",array1[i]);
	}
}
void push2(int x)
{

	top1++;
	array1[top1]=x;
}

void reverse()
{
     int i;
	 for(i=top;i>=0;i--)
	{
		push2(array[i]);
	}
	
}


int main()
{
	int c;
	while(1)
	{
		printf("\n\n************STACKS*************\n");
		printf("ENTER THE CORRESSPONDING CHOICE\n");
		printf("PUSH...........................1\n");
		printf("POP............................2\n");
		printf("DISPLAY THE TOP ELEMENT........3\n");
		printf("DISPLAY ALL ELEMENTS...........4\n");
		printf("REVERSE THE STACK..............5\n");
		printf("EXIT...........................0\n");
		
		printf("ENTER YOUR CHOICE: ");
		scanf("%d",&c);
		printf("\n\n");
		switch(c)
		{
			case 1:
			
			push();
			break;
			
			case 2:
			pop();
			break;
			
			case 3:
			peek();
			break;
			
			case 4:
			display();
			break;
			
			case 5:
			printf("\nBEFORE REVERSING: \n");
			display();
			reverse();
			printf("\nAFTER REVERSING: \n");
			display2();
			break;
			
			case 0:
			return 0;
			break;
			
			default:
			printf("INVALID CHOICE\n");
			
		}
		
	}
	
}
