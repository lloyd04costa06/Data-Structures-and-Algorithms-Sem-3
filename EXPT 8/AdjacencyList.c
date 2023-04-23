#include<stdio.h>
#include<stdlib.h>
#define LINE printf("*");

int count=0;

struct edge;
struct vertex
{
	int info;
	struct vertex *nextVertex;
	struct edge *firstEdge;
}*start=NULL;

struct edge
{
	struct vertex *destVertex;
	struct edge *nextEdge;
};

void DESIGN(int n)
{int i; for(i=0;i<n;i++)LINE;}

void VertDisp()
{
	struct vertex *p;
	struct edge *q;
	printf("\n\n");DESIGN(10);printf("GRAPH");DESIGN(10);printf("\n");
	p=start;
	while(p!=NULL)
	{
		printf("%d-> ",p->info);
		q=p->firstEdge;
		while(q!=NULL)
		{
			printf("|%d|",q->destVertex->info);
			if(q->nextEdge!=NULL)
			printf("->");
			q=q->nextEdge;
		}
		printf("\n");
		p=p->nextVertex;
	}
	DESIGN(25);
}

void createVertex()
{
	struct vertex *temp,*p;
	temp=(struct vertex *)malloc(sizeof(struct vertex));
	temp->nextVertex=NULL;
	temp->firstEdge=NULL;
	temp->info=count++;
	if(start==NULL)
	{
		start=temp;
		return;
	}
	p=start;
	while(p->nextVertex!=NULL)
	{
		p=p->nextVertex;
	}
	p->nextVertex=temp;
}

void addEnd(struct edge *q,struct vertex *x1,struct vertex *x2)
{
	
	struct edge *ptr;
	q->destVertex=x2;
	if(x1->firstEdge==NULL)
	{
		x1->firstEdge=q;
		return;
	}
	ptr=x1->firstEdge;
	while(ptr->nextEdge!=NULL)
      ptr=ptr->nextEdge;
	
	ptr->nextEdge=q;
}

void insertEdge(int x, int y)
{
	struct edge *q;
	struct vertex *ptr,*x1,*y1;
	int F1=0,F2=0;	
	q=(struct edge *)malloc(sizeof(struct edge));
	q->nextEdge=NULL;
	ptr=start;

	while(ptr!=NULL)
	{
		if(ptr->info==x){x1=ptr;F1=1;}
		
		if(ptr->info==y){y1=ptr;F2=1;}
		ptr=ptr->nextVertex;
	}
	
	printf("%d %d",F1,F2);
	if((F1==0&&F2==1) || (F1==1&&F2==0) )
	{
		printf("\nINVALID EDGE CREATION\n");
		return;
	}
	
	
	addEnd(q,x1,y1);
	VertDisp();
}

int main()
{
    int c, origin, destin,d;
	while(1)
	{
	    printf("\n\n");
	    DESIGN(37);printf("\nDIRECTED GRAPH USING ADJACENCY LIST\n");DESIGN(37);
	    printf("\n    1: INSERT A VERTEX\n");
	    printf("    2: INSERT EDGES\n");
	    printf("    3: DISPLAY ADJANCENCY LIST\n");
	    printf("    ENTER YOUR CHOICE: ");
	    scanf("%d",&c);
	    
	    switch(c)
	    {
	    	case 1:
	           createVertex();
			   VertDisp();
	    	break;
	    	
	    	case 2:
            do{
                printf("ENTER EDGE TO BE INSERTED (ENTER -1,-1 TO EXIT INSERT OF EDGES1) (Format x,y):  ");
	            scanf("%d,%d",&origin,&destin);
	             insertEdge(origin,destin);

            }while(origin!=-1&&destin!=-1);
	    	
	    	break;
	    	
	    	case 3:
	    	VertDisp();
	    	break;
	    }
	}
	
}