#include<stdio.h>
#include<stdlib.h>
#define count 10
int i;
typedef struct node
{
	int info;
	node *left;
	node *right;
};

node *insert(node *root,int key)
{
	if(root==NULL)
	{
		root=(node *)malloc(sizeof(node));
		root->info=key;
		root->left=NULL;
		root->right=NULL;
	}
	else if(key>root->info)
	root->right=insert(root->right,key);
	else if(key<root->info)
	root->left=insert(root->left,key);
	else
	{
		printf("DUPLOCATE KEY\n");
	}
	return root;
}

void display(node *root, int space)
{

	space=space+count;
	if(root==NULL)
	return;
	display(root->right,space);
	printf("\n");
	for(i=count;i<space;i++)
	printf(" ");
	printf("%d\n",root->info);
	display(root->left,space);
}

node *del(node *root,int key)
{
	if(root==NULL)
	{
		printf("KEY NOT PRESENT\n");
		return root;
	}
	else if(key>root->info)
	root->right=del(root->right,key);
	else if(key<root->info)
	root->left=del(root->left,key);
	else
	{
		if(root->right!=NULL&&root->left!=NULL)
		{
			node *succ;
			succ=root->right;
			while(root->left)
			succ=root->left;
			
			root->info=succ->info;
			root->right=del(root->right,succ->info);
		}
		else
		{
			node *temp=root;
			if(root->left!=NULL)
			root=root->left;
			else if(root->right!=NULL)
			root=root->right;
			else
			root=NULL;
			free(temp);
		}
	}
	return root;
}
int main()
{
	 struct node *root=NULL;
    int choice,i,data,key;
    while(1)
    {
        printf("\n\nBINARY SEARCH TREE\n");
        printf("---------------------\n");
        printf("1: INSERT A NODE\n");
        printf("2: DELETE A NODE\n");
        printf("3: SEARCH A NODE\n");
        printf("4: DISPLAY THE TREE\n");
        printf("\n\nENTER YOUR CHOICE: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            printf("ENTER THE NODE DATA: ");
            scanf("%d",&data);
            root=insert(root,data);
            break;
            
            case 4:
             display(root,0);
            break; 

            case 2:
            printf("ENTER THE ELEMENT TO BE DELETED\n");
            scanf("%d",&key);
            root=del(root,key);
            break;
/*
            case 3:
            printf("ENTER A SEARCH KEY: ");
            scanf("%d",&key);
            search(root,key);
            break;*/

            
        }
    }
}