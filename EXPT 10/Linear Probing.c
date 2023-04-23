#include<stdio.h>
#include<string.h>
#define MAX 5
#define HASH(x)(x%MAX)
#define DUPLICATE printf("DUPLICATE ELEMENT\n")
#define SPACE printf("          ")
#define LINE printf("----------------------------------")

enum RecordType{EMPTY,OCCUPIED,DELETED};

struct candidate
{
	char name[20];
	int idd;
};

struct record
{
	struct candidate info;
	enum RecordType status;
};

void insert(struct candidate x,struct record table[])
{
	int location;
	int i,key,h;
	key=x.idd;
	
	h=HASH(x.idd);
	location=h;
	
	for(i=1;i!=MAX;i++)
	{
		if((table[location].status==EMPTY)||(table[location].status==DELETED))
		{
			table[location].info.idd=x.idd;
			strcpy(table[location].info.name,x.name);
			printf("RECORD ENTERED SUCCESSFULLY\n\n");
			table[location].status=OCCUPIED;
			return;
		}
		if(table[location].info.idd==key)
		{DUPLICATE;return;}
	
	
	location=(h+i)%MAX;
	
	}
	printf("TABLE OVERFLOW\n");
}

void display(struct record table[])
{
	int i;
	printf("\n_________CANDIDATE LIST___________\n");
	printf("HASH ");SPACE;
	printf("ID");SPACE;
	printf("NAME\n");
	
	for(i=0;i!=MAX;i++)
	{
		printf("%d ",i);
		if(table[i].status==OCCUPIED)
		{
			printf("%14.d",table[i].info.idd);SPACE;
			printf(" %s",table[i].info.name);
			printf("\n");
		}
		else if(table[i].status==DELETED)
		{
			SPACE;SPACE;
			printf("     DELTED\n");
		}
		else
		{
			SPACE;SPACE;
			printf("     EMPTY\n");
		}
		
	}
	LINE;
}

int search(struct record table[],int key)
{
	int i;
	int h,location;
	h=HASH(key);
	location=h;
	
	for(i=1;i!=MAX;i++)
	{
		if(table[location].info.idd==key)
		return location;
		else if(table[location].status==EMPTY)
		return -1;
		location=(h+i)%MAX;
	}
	return -1;
}

void del(struct record table[])
{
	int i,key;
	int location;
	
	printf("ENTER CANDIDATE ID NUMBER TO BE DELETED: ");
	scanf("%d",&key);
	location=search(table,key);
	if(location==-1)
	printf("CANDIDATE NAME NOT PRSENT IN THE LIST\n");
	else
	{
	  table[location].status=DELETED;
	  printf("RECORD DELETED\n");
	}
}

int main()
{
	int i,c,l,z;
	struct record table[MAX];
	struct candidate x;
	for(i=0;i<MAX;i++)
	table[i].status=EMPTY;
	
	
	while(1)
	{
		printf("\n____ELECTION CANDIDATE LIST______\n");
		printf("\n1: INSERT\n");
		printf("2: DISPLAY:\n");
		printf("3: SEARCH\n");	
		printf("4: DELETE\n");LINE;
		printf("\nENTER CHOICE: ");
		scanf("%d",&c);
		printf("\n");
		
		switch(c)
		{
			case 1:
			printf("ENTER CANDIDATE NAME: ");
			scanf("%s",&x.name);
			printf("ENTER CANDIDATE ID: ");
			scanf("%d",&x.idd);
			insert(x,table);
			break;
			
			case 2:
			display(table);
			break;
			
			case 3:
			printf("ENTER ID: ");
			scanf("%d",&l);
			z=search(table,l);
			
			if(z==-1)
			printf("EMPLOYEE DEETS NOT PRESENT: ");
			else
			{
				printf("NAME: %s\tID: %d\n",table[z].info.name,table[z].info.idd);
			}
			
			break;
			
			case 4:
			del(table);
			break;
		}
	
	}
	
}
