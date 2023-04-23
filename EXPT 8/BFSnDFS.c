// WAP to implement BFS and DFS in directed graph
#include<stdio.h>
#include<stdlib.h>
#define LINE printf("~");
#define GCHECK(x)(x<0||x>=n)
#define INITIAL 1
#define WAITING 2
#define VISITED 3
#define MAX 30

int adj[MAX][MAX];
int state[MAX];
int n;
int qarr[MAX];
int front=-1, rear=-1;
void insert(int data);
int del();
int isEmpty();
void BFS_travseral();
void BFS(int u);
void DFS_travseral();
void DFS(int u);
void display();

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
    int u, v,i;
    printf("ENTER THE NUMBER OF VERTICES: ");
    scanf("%d",&n);
    int max_edges=n*(n-1);
    for(i=1;i<=max_edges;i++)
    {
        printf("ENTER THE SOURCE AND DESTINATION((-1,-1) TO EXIT): ");
        scanf("%d,%d",&u,&v);
        if(u==-1 && v==-1)
            break;
        if(GCHECK(u)|GCHECK(v))
        {
            printf("INVALID VERTEX\n\n");
            i--;
        }
        else
            adj[u][v]=1;
    }
    display();
    printf("\n\n");
    DFS_travseral();
    BFS_travseral();
    return 0;
}
void BFS(int v)
{
	int i;
	insert(v);
	state[v]=WAITING;
	while(!isEmpty())
	{
		v=del();
		printf("%d ",v);
		state[v]=VISITED;
		for(i=0;i<n;i++)
		{
			
			if(adj[v][i]==1&&state[v]==INITIAL)
			{
				insert(i);
				state[i]=WAITING;
			}
		}
	}
}

void BFS_travseral()
{
	int v;
	for(v=0;v<n;v++)
	{
		state[v]=INITIAL;
	}
	printf("ENTER THE STARTING VERTEX\n");
	scanf("%d",&v);
	BFS(v);
}
void DFS_travseral()
{
    int u,i;
    for(i=0;i<n;i++)
        state[i]=INITIAL;
    printf("\n");DESIGN(10);printf("DEPTH FIRST SEARCH");DESIGN(10);printf("\n");
    printf("ENTER THE STARTING VERTEX: ");
    scanf("%d",&u);
    printf("\nDFS: ");
    DFS(u);
}
void DFS(int u)
{
	int i;
    if(state[u]==INITIAL)
    {
        printf("%d ",u);
        state[u]=VISITED;
    }
    for(i=0;i<n;i++)
    {
        if(adj[u][i]==1 && state[i]==INITIAL)
            DFS(i);
    }
}

void insert(int data)
{
	if(rear==MAX-1)
	{
		printf("Queue Overflow\n");
		return;
	}
	if(front==-1)
	{
		qarr[++front]=data;
		rear=0;
	}
	else
		qarr[++rear]=data;
}
int del()
{
	if(isEmpty())
	{
		printf("Queue Underflow\n");
		exit(0);
	}
	return qarr[front++];
}
int isEmpty()
{
    if(front==-1||front>rear)
        return 1;
    return 0;
}
