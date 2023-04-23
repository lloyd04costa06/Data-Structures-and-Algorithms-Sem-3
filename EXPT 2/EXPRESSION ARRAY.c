#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int top=-1;
int top1=-1;
char temp[50];
char *STACK;


void StrINPUT()
{
	printf("ENTER AN EXPRESSION\n");
	gets(temp);
}



int isFull()
{
	if(top==strlen(STACK))
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
	int i,count1=0,count2=0;
	if(isEmpty())
	{
		printf("STACK IS EMPTY\n");
		return;
	}


	for(i=top;i>=0;i--)
	{
		if(STACK[i]=='}'||STACK[i]==')')
		count1++;
		
		if(STACK[i]=='{'||STACK[i]=='(')
		count2++;	
	}
	
	if(count1==count2)
	printf("VALID EXPRESSION\n");
	else
	printf("INVALID EXPRESSION\n");
}
void push(char x)
{
	
	if(isFull())
	{
		printf("STACK OVERFLOW\n");
		return;
	}
	top++;
	STACK[top]=x;

}

void pop()
{
	int x;
	if(isEmpty())
	{
		printf("STACK UNDERFLOW\n");
		return;
	}
	
	x=STACK[top];
	top--;
	printf("ITEM POPPED IS: %d\n",x);
	
}


int main()
{
	int i;
	StrINPUT();
	
	STACK=(char *)malloc(strlen(temp)*sizeof(char));
	for(i=0;temp[i]!='\0';i++)
	{
		push(temp[i]);
	}
	display();
}