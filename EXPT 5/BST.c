#include<stdio.h>
#include<stdlib.h>
#define CNT 10
int key,x=0;
struct node{

    struct node *left;
    int data;
    struct node *right;
};
struct node* insert(struct node *p,int data)
{

    if(p==NULL)
    {
        
        p=(struct node*)malloc(sizeof(struct node));
        p->data=data;
        p->left=NULL;
        p->right=NULL;
    }
    else if(data < p->data)
    p->left=insert(p->left,data);
    
   else if(data > p->data)
    p->right=insert(p->right,data);
    else
    printf("DUPLICATE VALUE\n");

    return p;
    
}

void search(struct node* p, int data)
{
	if(p==NULL)
		printf("DATA NOT FOUND\n");
	else if(p->data > data)
		search(p->left, data);
	else if(p->data < data)
		search(p->right, data);
	else
		printf("DATA FOUND\n");
}

struct node *del(struct node *p,int key)
{
    struct node *temp,*succ;
    if(p==NULL)
    {
        printf("%d IS NOT PRESENT IN THE TREE\n",key);
        return p;
    }
    if(key < p->data)
    p->left=del(p->left,key);
    else if(key > p->data)
    p->right=del(p->right,key);
    else{
        if(p->left!=NULL&&p->right!=NULL)
        {
            succ=p->right;
            while(succ->left!=NULL)
            succ=succ->left;
            p->data=succ->data;
            p->right=del(p->right,succ->data);
        }
        else
        {
            temp=p;
            if(p->left!=NULL)
            p=p->left;
            else if(p->right!=NULL)
            p=p->right;
            else
            p=NULL;
            free(temp);
        }
          
    }
    return p;
}

void display(struct node *root,int space)
{
	
    int i;
	space+=CNT;
    if(root==NULL)
    return;
	display(root->right,space);
	printf("\n");
	for(i=CNT;i<space;i++)
	printf(" ");
	printf("%d\n",root->data);
	display(root->left,space);
	
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

            case 2:
            printf("ENTER THE ELEMENT TO BE DELETED\n");
            scanf("%d",&key);
            root=del(root,key);
            break;

            case 3:
            printf("ENTER A SEARCH KEY: ");
            scanf("%d",&key);
            search(root,key);
            break;

            case 4:
             display(root,0);
            break;
        }
    }
}