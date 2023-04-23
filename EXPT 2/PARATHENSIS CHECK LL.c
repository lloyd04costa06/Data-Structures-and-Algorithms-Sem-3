#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char temp[50];


struct node{
	char letter; 
	struct node *link;
}*top=NULL;



void StrINPUT()
{
	printf("ENTER A EXPRESSION\n");
	gets(temp);
}

int isEmpty(){

	struct node *p;
	if(top==NULL)
	return 1;
	else
	return 0;
}

void push(char  x){
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("STACK OVERFLOW\n");
		return;
	}
	temp->letter=x;
	temp->link=top;
	top=temp;

   
}
void display(){
	
	if(isEmpty())
	{
		printf("STACK EMPTY\n");
		return;
	}
	struct node *p;
	int count1=0,count2=0;
	p=top;
		while(p!=NULL)
		{
			if(p->letter=='}'||p->letter==')')
		count1++;
		
		if(p->letter=='{'||p->letter=='(')
		count2++;
			p=p->link;
		}
	
	if(count1==count2)
	printf("VALID EXPRESSION\n");
	else
	printf("INVALID EXPRESSION\n");
}

int main()
{
	int i;
	StrINPUT();
	for(i=0;temp[i]!='\0';i++)
	{
		push(temp[i]);
	}
	display();
}