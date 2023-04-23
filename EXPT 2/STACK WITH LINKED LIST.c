/*WRITE PROGRAM TO IMPLEMENT STACK USING LL
1 PUSH
2 POP
3 DISPLAY TOP ELEMENT 
4 DISPLAY ALL STACK ELEMENT
5 REVERSE STACK USING TWO STACK

II WAP FOR CONVERSION OF INFIX TO POSTFIX & EVALUATION OF POSTFIX EXPRESSION
III "  TO REVERSE THE STRING USING STACK
IV TO CHECK NESTING PARENTHENISIS USING STACKS*/


#include<stdio.h>
#include<stdlib.h>

struct node{
	int data; 
	struct node *link;
}*top=NULL,*top2=NULL;


int isEmpty(int flag){

	struct node *p;
	if(flag==0) p=top; else  p=top2;
	if(p==NULL)
	return 1;
	else
	return 0;
}

void push(int x, int flag){
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("STACK OVERFLOW\n");
		return;
	}
	
	
	temp->data=x;
	if(flag==0)
	{
		 temp->link=top;
    	top=temp;
	}
	else
	{
		 temp->link=top2;
   		 top2=temp;
	}
   
}


void pop(){
	
	struct node *temp;
	temp=top;
	if(isEmpty(0))
	{
		printf("STACK UNDERFLOW\n");
		return;
	}
	printf("POPPED: %d",top->data);
	top=top->link;
	free(temp);
}



void display(int flag){
	if(isEmpty(flag))
	{
		printf("STACK EMPTY\n");
		return;
	}
		struct node *p;
		
		if(flag==0)	p=top;	else  p=top2;
		
		while(p!=NULL)
		{
			printf("%d ",p->data);
			p=p->link;
		}
	
}

void reverse()
{

	struct node *p=top;
	while(p!=NULL)
	{
		push(p->data,1);
		p=p->link;
	}
	display(1);
}


int main()
{
	int choice,e;
	
	 
	 while(1)
	 {
	 	printf("\n\nENTER THE CORRESPONDING NUMBER TO ACCESS IT:\n");
 		printf("1: PUSH\n");
 		printf("2: POP\n");
 		printf("3: DISPLAY TOP ELEMENT\n");
 		printf("4: DISPLAY ALL ELEMENTS\n");
 		printf("5: REVERSE THE STACK\n");
 		printf("\nENTER YOU CHOICE: ");
 		scanf("%d",&choice);
 		
 		switch(choice)
 		{
		 	case 1:
		 	printf("ENTER THE ELEMENT\n");
		 	scanf("%d",&e);
		 	push(e,0);
		 	break;
		 	
		 	case 2:
		 	pop();
		 	break;
		 	
		 	case 3:
		 	printf("TOP ITEM: %d\n",top->data);
		 	break;
		 	
		 	case 4:
		 	display(0);
		 	break;
		 	
		 	case 5:
		 	reverse();
		 	break;
		 }
 	}
}

