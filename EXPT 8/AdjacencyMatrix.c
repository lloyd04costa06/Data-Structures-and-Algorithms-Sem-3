#include<stdio.h>
#include<string.h>
#define MAX 50
#define LINE printf("~");
#define GCHECK(x)(x<0||x>=n)

int n;
int adj[MAX][MAX];

void DESIGN(int n)
{int i; for(i=0;i<n;i++)LINE;}

void DESIGN2(int n)
{
	int i;
	printf("       ");
	for(i=0;i<5;i++)
	printf(" ");
	DESIGN(n-5);
}

 void createGraph()
 {
     int i, maxEdges,origin,destin;
     printf("ENTER NUMBER OF VERTICES: ");
     scanf("%d",&n);
     maxEdges=n*(n-1);

     for(i=1;i<maxEdges;i++)
     {
         printf("ENTER EDGE %d (-1,-1 to exit):  ",i);
         scanf("%d,%d",&origin,&destin);

         if(origin==-1&&destin==-1)
         break;

         if(GCHECK(origin)||GCHECK(destin))
         {
         	printf("INVALID EDGE\n");
         	i--;
         }
         else
         adj[origin][destin]=1;
     }
 }

void insertEdge(int origin,int destin)
{
	if(GCHECK(origin))
	{printf("ORIGIN VERTEXT DOES NOT EXIST\n");return;}
	
	if(GCHECK(destin))
	{printf("DESTINATION VERTEXT DOES NOT EXIST\n");return;}
	
	adj[origin][destin]=1;
}

void delEdge(int origin,int destin)
{
	if(GCHECK(origin)||GCHECK(destin)||adj[origin][destin]==0)
	{
		printf("NO EDGE EXISTS\n");
		return;
	}
	adj[origin][destin]=0;
}

void delVertex(int vert)
{
	int i,TEMP=vert;
	if(n==0)
	{
		printf("GRAPH EMPTY\n");
		return;
	}
	if(GCHECK(vert))
	{
		printf("INVALID VERTEX\n");
		return;
	}
	
	while(vert<n)
	{
		for(i=0;i<n;i++)
		adj[i][vert]=adj[i][vert+1];
		
		for(i=0;i<n;i++)
		adj[vert][i]=adj[vert+1][i];
		
		vert++;
	}
	printf("THE VERTEX DELETED WAS: %d\n",TEMP);
	n--;
}
void display()
{
	int i,j;
	printf("       ");
	for(i=0;i<n;i++)
	printf("%6d",i);
	printf("\n");
	
	DESIGN2(n*6);
	printf("\n");
	
	for(i=0;i<n;i++)
	{
		printf("    %2d|",i);
		for(j=0;j<n;j++)
		printf("%6d",adj[i][j]);
		printf("\n");
	}
}
int main()
{
    int c, origin, destin,d;
    createGraph();
	while(1)
	{
	    printf("\n\n");
	    DESIGN(37);printf("\nDIRECTED GRAPH USING ADJACENCY MATRIX\n");DESIGN(37);
	    printf("\n    1: INSERT A EDGE\n");
	    printf("    2: INSERT A NEW VERTEX\n");
	    printf("    3: DELETE AN EDGE\n");
	     printf("    4: DELETE AN VERTEX\n");
	    printf("    5: DISPLAY ADJACENCY MATRIX\n");
	    printf("    ENTER YOUR CHOICE: ");
	    scanf("%d",&c);
	    
	    switch(c)
	    {
	    	case 1:
	        	printf("ENTER NEW EDGE (Format x,y):  ");
	         scanf("%d,%d",&origin,&destin);
	         insertEdge(origin,destin);
	    	break;
	    	
	    	case 2:
	    	n++;
	    	printf("NEW VERTEX ADDED\n");
	    	break;
	    	
	    		case 3:
	    	printf("ENTER EDGE TO BE DELETED (Format x,y):  ");
	         scanf("%d,%d",&origin,&destin);
	         delEdge(origin,destin);
	    	break;
	    	
	    	case 4:
	    	printf("ENTER THE VERTEX TO BE DELETED: ");
	    	scanf("%d",&d);
	    	delVertex(d);
	    	break;
	    	
	    	case 5:
	    	display();
	    	break;
	    }
	}
	
}
