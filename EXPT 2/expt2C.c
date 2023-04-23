/*Write a program to convert infix to postfix and evaluate the postfix expression*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
}*top=NULL;
void push(int symbol);
int pop();
void toPostfix();
int evaluate();
int inpriority(char symbol);
int priority(char symbol);
char infix[50], postfix[50];

int main()
{
    printf("ENTER INFIX EXPRESSION : ");
    gets(infix);
    toPostfix();
    printf("POSTFIX : %s\n",postfix);
    printf("VALUE OF EXPRESSION: %d\n",evaluate());
    return 0;
}

void toPostfix()
{
    int i,j=0;
    char ch, symbol;
    for(i=0;i<strlen(infix);i++)
    {
        symbol=infix[i];
        if(symbol!=' ' || symbol!='\t')
        {
            switch(symbol)
            {
                case '(':
                    push(symbol);
                    break;
                case ')':
                    while((ch=pop())!='(')
                        postfix[j++]=ch;
                    break;
                case '+': case '-': case '*': case '/': case '%': case '^':
                    while(top!=NULL && inpriority(top->data)>=priority(symbol))
                        postfix[j++]=pop();
                	push(symbol);
                    break;
                default:
                    postfix[j++]=symbol;
            }
        }
    }
    while(top!=NULL)
        postfix[j++]=pop();
    postfix[j]='\0';
}

int inpriority(char symbol)
{
    switch(symbol)
    {
	    case '(':
	        return 0;
	    case '+': case '-':
	        return 1;
	    case '*': case '/': case '%':
	        return 2;
	    case '^':
	        return 3;
    }
}

int priority(char symbol)
{
    switch(symbol)
    {
	    case '(':
	        return 0;
	    case '+': case '-':
	        return 1;
	    case '*': case '/': case '%':
	        return 2;
	    case '^':
	        return 4;
    }
}

void push(int symbol)
{
    struct node *t=(struct node*) malloc(sizeof(struct node));
	if(t==NULL){
		printf("Stack Overflow");
		return;
	}
	t->data=symbol;
	t->link=top;
	top=t;
}

int pop()
{
    struct node *t=top;
	int data;
	if(top==NULL){
		printf("Stack Underflow");
		exit(1);
	}
	data=top->data;
	top=top->link;
	free(t);
	return data;
}

int evaluate()
{
    int a,b,temp,i;
    for(i=0;i<strlen(postfix);i++)
    {
        if(postfix[i]<='9' && postfix[i]>='0')
            push(postfix[i]-'0');
        else
        {
            a=pop();
            b=pop();
        	switch(postfix[i])
            {
                case '+': temp=b+a; break;
                case '-': temp=b-a; break;
                case '*': temp=b*a; break;
                case '/': temp=b/a; break;
                case '%': temp=b%a; break;
                case '^': temp=pow(b,a);
            }
            push(temp);
        }
    }
    int x;
    x=pop();
    return x;
}
