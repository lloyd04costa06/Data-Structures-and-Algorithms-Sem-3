#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int rollNo;
	char name[20];
	int marks[3];
	int total;
	float avg;
	struct node *link;
}*s1,*s2;


void print(struct node *start)
{
	int i;

	printf("\nNAME: %s\n",start->name);
	printf("ROLL NUMBER: %d\n",start->rollNo);
	printf("MARKS OF 3 SUBJECTS: ");
	for(i=0;i<3;i++)
	printf("%d ",start->marks[i]);
	printf("\nAVERAGE = %f",start->avg);
	printf("\n");
}

struct node* del(struct node* start,struct node *x)
{
	
	struct node* p=start;
	while(p->link!=NULL)
	{
		if(p->link==x)
		{
			p->link=p->link->link;
			break;
		}
		p=p->link;
	}
	printf("Yjj");
	return start;
}

struct node *addEND(struct node *start)
{
	struct node *temp,*p;
	int i;
	float sum=0;
	p=start;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("ENTER NAME: ");
		scanf("%s",&temp->name);
		printf("ENTER THE ROLL NUMBER: ");
		scanf("%d",&temp->rollNo);
		printf("ENTER MARKS OF 3 SUBJECTS:\n");
		for(i=0;i<3;i++)
		{
			scanf("%d",&temp->marks[i]);
			sum+=temp->marks[i];
		}
		
		temp->avg=sum/3;
		
	while(p->link!=NULL)
	p=p->link;
	
	p->link=temp;
	temp->link=NULL;

	return start;
	
}


struct node *createList(struct node *start)
{
	int i,n,sum=0;
	
	printf("ENTER NUMBER OF STUDENTS\n");
	scanf("%d",&n);
	
	start=NULL;
	if(n==0)
	return start;
	

	
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
		printf("ENTER NAME: ");
		scanf("%s",&temp->name);
		printf("ENTER THE ROLL NUMBER: ");
		scanf("%d",&temp->rollNo);
		printf("ENTER MARKS OF 3 SUBJECTS:\n");
		for(i=0;i<3;i++)
		{
			scanf("%d",&temp->marks[i]);
			sum+=temp->marks[i];
		}
		temp->avg=sum/3;
	
	temp->link=start;
	start=temp;
	
	for(i=2;i<=n;i++)
	{
		start=addEND(start);
	}
	return start;
	
}

void display(struct node *start)
{
     
	struct node *p;
	int i;
	if(start==NULL)
	{
		printf("LIST EMPTY\n");
		return;
	}
	p=start;
	while(p!=NULL)
	{
	    printf("\nNAME: %s\n",p->name);
	    printf("ROLL NUMBER: %d\n",p->rollNo);
	    printf("MARKS OF 3 SUBJECTS: ");
	    for(i=0;i<3;i++)
	    {
    		printf("%d ",p->marks[i]);
    	
	    }
	   	printf("AVERAGE: %f\n",p->avg);
	    p=p->link;
	    
	}

}

struct node *LARGE(struct node *start)
{
	struct node *temp,*temp2,*p;
	
	float max=start->avg;
	temp=start->link;

	while(temp->link!=NULL)
	{
		if((temp->avg)>max)
		{
			max=temp->avg;
			p=temp;
			printf("%f\n",max);
		}
		temp=temp->link;
	}
	if(p==start)
	{
		start=start->link;
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		temp->link=p;
		p->link=NULL;
		return start;
	}
	else if(p!=start)
	{
		temp2=start;
		while(temp2->link!=NULL)
		{
		if(temp2->link->avg==max)
			temp2->link=p->link;
		
		
			temp2=temp2->link;
		}
		temp2->link=p;
		p->link=NULL;
		return start;
	}
}
	

struct node *split(struct node *start)
{
	int r;
	printf("ENTER THE ROLL NUMBER FROW WHERE YOU WANT TO SPLIT\n");
	scanf("%d",&r);
	
	struct node *p1,*p2;
	if(start->rollNo==r)
	{
		printf("\nList cannot be splitted\n");
		return start;;
	}
	p1=start;
	
	while(p1!=NULL)
	{
		if(p1->rollNo==r)
		{
			p2=p1->link;
			p1->link=NULL;
			break;
		}
		p1=p1->link;
	}
	printf("\nLIST 1: \n");
	display(start);
	s1=start;
	printf("\nLIST 2: \n");
	display(p2);
	s2=p2;
}

struct node *swap(struct node *start)
{
	struct node *prev=NULL, *next, *cur=start;
	if(start!=NULL && start->link==NULL)
		return start;
	start=start->link;
	while(cur!=NULL && cur->link!=NULL)
	{
		next=cur->link;
		cur->link=next->link;
		next->link=cur;
		if(prev!=NULL)
			prev->link=next;
		prev=cur;
		cur=cur->link;
	}
	display(start);
}


struct node *merge()
{
	struct node *a,*b;
	a=s1;
	b=s2;
	while(a->link!=NULL)
	{
		a=a->link;
	}

	printf("BEFORE MERGING: \n");
	printf("LIST 1:\n");
	display(s1);
	printf("LIST 2:\n");
	display(s2);
	a->link=b;
	printf("\n\nAFTER MERGING\n");
	return(s1);
}
struct node *sort(struct node *start)
{
	struct node *t;
     struct node *s;
     int x;
     t=start;
     while(t!=NULL)
     {
          s=t->link;
          while(s!=NULL)
          {
               if(t->rollNo>s->rollNo)
               {
                    x=t->rollNo;
                    t->rollNo=s->rollNo;
                    s->rollNo=x;
               }
               s=s->link;
          }
          t=t->link;
      }
    
    
    return start;
}


int main()
{
	struct node *start;
	int choice,marks[3],i,rollNo;
	char x[20];
	do{
		printf("\n\nSTUDENTS\n");
		printf("CREATE STUDENT LIST........................1\n");
		printf("SORT STUDENT LIST..........................10\n");
		printf("DISPLAY CONTENT............................2\n");
		printf("FIND THE LARGEST AND SMALLEST..............3\n");
		printf("SPLIT INTO LIST............................4\n");
		printf("SWAP CONTENTS..............................5\n");
		printf("MERGE 2 LISTS..............................6\n");
		
		printf("ENTER THE CHOICE: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
			
			start=createList(start);
			
			break;
			
			case 2:
			display(start);
			break;
			
			case 3:
			start=LARGE(start);
			break;
			
			case 4:
			split(start);
			break;
			
			case 5:
			start=swap(start);
			printf("SWAPPED SUCCESSFULLY\n");
			break;
			
			case 6:
			start=merge();
			display(start);
			break;
			
			case 10:
			start=sort(start);
			break;
			default:
			printf("INVALID CHOICE\n");
				
		}
	}while(1);
}
