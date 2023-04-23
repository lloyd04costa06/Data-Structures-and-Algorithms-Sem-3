#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10
#define HASH(x)(x%MAX)
#define DUPLICATE printf("DUPLICATE ELEMENT\n")
#define SPACE printf("          ")
#define LINE printf("----------------------------------")


struct candidate
{
	char name[20];
	int idd;
};

struct record
{
	struct candidate info;
	struct record *link;
};

int search(struct record *table[],int key)
{
	int i;
	int h,location;
	struct record *ptr;
	h=HASH(key);
	ptr=table[h];
	
	while(ptr!=NULL)
	{
		if(ptr->info.idd==key)
		return h;
		
		ptr=ptr->link;
	}
	return -1;	
}


void insert(struct candidate x,struct record *table[])
{
	int i,key,h;
	struct record *temp;
	key=x.idd;
	h=HASH(x.idd);
	
	if(search(table,key)!=-1)
	{
		printf("DUPLICATE KEY\n");
		return;
	}
	
	temp=(struct record *)malloc(sizeof(struct record));
	temp->info=x;
	temp->link=table[h];
	table[h]=temp;
		
}

void display(struct record *table[])
{
	int i;
	struct record *ptr;
	printf("\n_________CANDIDATE LIST___________\n");
	
	for(i=0;i!=MAX;i++)
	{
		printf("%d---->",i);
		ptr=table[i];
		while(ptr!=NULL)
		{
			printf("|%d %s|",ptr->info.idd,ptr->info.name);
			if(ptr->link!=NULL)
			printf("-->");
			ptr=ptr->link;
		}
		printf("\n");
		
	}
	LINE;
}


void del(struct record *table[])
{
	int i,key,h;
	int location;
	struct record *temp,*ptr;
	printf("ENTER THE KEY TO BE DELETED: ");
	scanf("%d",&key);
	h=HASH(key);
	if(table[h]==NULL)
	{
		printf("KEY NOT FOUND\n");
		return;
	}
	
	if(table[h]->info.idd==key)
	{
		temp=table[h];
		table[h]=table[h]->link;
		free(temp);
		return;
	}
	ptr=table[h];
	
	while(ptr!=NULL)
	{
		if(ptr->link->info.idd==key)
		{
			temp=ptr->link;
			ptr->link=temp->link;
			free(temp);
			return;
		}
		ptr=ptr->link;
	}
	printf("KEY NOT FOUND\n");
}

int main()
{
	int i,c,l,z;
	struct record *table[MAX];
	struct candidate x;
	for(i=0;i<MAX;i++)
	table[i]=NULL;
	
	
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
				printf("NAME: %s\tID: %d\n",table[z]->info.name,table[z]->info.idd);
			}
			
			break;
			
			case 4:
			del(table);
			break;
		}
	
	}
	
}