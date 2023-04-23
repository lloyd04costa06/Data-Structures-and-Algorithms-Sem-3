#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define CNT 10
struct node
{
    int data;
    bool Lthread,Rthread;

    struct node *left;
    struct node *right;

};

struct node *del(struct node *root,int ikey);
struct node *caseA(struct node *root, struct node *par, struct node *ptr);
struct node *caseB(struct node *root, struct node *par, struct node *ptr);
struct node *caseC(struct node *root, struct node *par, struct node *ptr);
struct node *inSucc(struct node *ptr);
struct node *inPred(struct node *ptr);
void inorder(struct node *p);
void preorder(struct node *p);

struct node *insert(struct node *root,int ikey)
{
    struct node *temp,*par,*ptr;
    int found=0;
    ptr=root;
    par=NULL;
    while(ptr!=NULL)
    {
        if(ikey==ptr->data)
        {
            found=1;
            break;
        }
        par=ptr;
        if(ikey<ptr->data)
        {
            if(ptr->Lthread==false)
            ptr=ptr->left;
            else
            break;
        }
        else
        {
            if(ptr->Rthread==false)
            ptr=ptr->right;
            else
            break;

        }   
    }
    if(found)
        printf("DUPLICATE KEY\n");
    else
    {
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=ikey;
        temp->Lthread=true;
        temp->Rthread=true;
        if(par==NULL)
        {
            root=temp;
            temp->left=NULL;
            temp->right=NULL;
        }
        else if(ikey<par->data)
        {
            temp->left=par->left;
            temp->right=par;
            par->Lthread=false;
            par->left=temp;
        }
        else
        {
            temp->left=par;
            temp->right=par->right;
            par->Rthread=false;
            par->right=temp;
        }
    }
    return root;
}

struct node *del(struct node *root, int ikey)
{
    struct node *par,*ptr;
    int found=0;
    ptr=root;
    par=NULL;
    while(ptr!=NULL)
    {
        if(ikey==ptr->data)
        {
            found=1;
            break;
        }
        par=ptr;
        if(ikey<ptr->data)
        {
            if(ptr->Lthread==false)
            ptr=ptr->left;
            else
            break;
        }
        else
        {
            if(ptr->Rthread==false)
            ptr=ptr->right;
            else
            break;

        }
    }
        if(!found)
        printf("dKEY NOT PRESENT IN TREE\n");
        else if(ptr->Lthread==false&&ptr->Rthread==false)
        root=caseC(root,par,ptr);
        else if(ptr->Lthread==false)
        root=caseB(root,par,ptr);
        else if(ptr->Rthread==false)
        root=caseB(root,par,ptr);
        else
        root=caseA(root,par,ptr);
    
    return root;

}

void display(struct node *root,int space)
{
	int i;
	space+=CNT;
	if(root->Rthread==false)
	display(root->right,space);
	printf("\n");
	for(i=CNT;i<space;i++)
	printf(" ");
	printf("%d\n",root->data);
	if(root->Lthread==false)
	display(root->left,space);
	
}
int main()
{
    int choice,num,space=0;
    struct node *root=NULL;
    while(1)
    {
        printf("\n");
        printf("1: INSERT\n");
        printf("2: DELETE\n");
        printf("3: DISPLAY\n");
         printf("4: INORDER\n");
          printf("5: PREORDER\n");
        printf("ENTER THE CHOICE\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            printf("ENTER THE NUMBER TO INSERTED\n");
            scanf("%d",&num);
            root=insert(root,num);
            break;
            case 2:
            printf("ENTER THE NUMBER TO BE DELETED\n");
            scanf("%d",&num);
            root=del(root,num);
            break;
            
            case 3:
            display(root,0);
            break;

            case 4:
            printf("INORDER: ");
            inorder(root);
            break;

            case 5:
            printf("PREORDER: ");
            preorder(root);
            break;
            
        }
    }

}

struct node *caseA(struct node *root, struct node *par, struct node *ptr)
{
    if(par==NULL)
        root=NULL;
    else if(ptr==par->left)
    {
        par->Lthread=true;
        par->left=ptr->left;
    }
    else
    {
        par->Rthread=true;
        par->right=ptr->right;
    }
    free(ptr);
    return root;

}

struct node *caseB(struct node *root, struct node *par, struct node *ptr)
{
    struct node *child,*s,*p;
    if(ptr->Lthread==false)
    child=ptr->left;
    else
    child=ptr->right;
    if(par==NULL)
    root=child;
    else if(par->left==ptr)
    par->left=child;
    else
    par->right=child;
    s=inSucc(ptr);
    p=inPred(ptr);
    if(ptr->Lthread==false)
    p->right=s;
    else
    {
        if(ptr->Rthread==false)
        s->left=p;
    }
    free(ptr);
    return root;
}

struct node *caseC(struct node *root, struct node *par, struct node *ptr)
{
    struct node *succ,*parsucc;
    parsucc=ptr;
    succ=ptr->right;

    while(succ->left!=NULL)
    {
        parsucc=succ;
        succ=succ->left;
    }
    ptr->data=succ->data;
    if(succ->Lthread==true&&succ->Rthread==true)
    root=caseA(root,parsucc,succ);
    else
    root=caseB(root,parsucc,succ);
    return root;
}

struct node *inSucc(struct node *ptr)
{
    if(ptr->Rthread==true)
    return ptr->right;
    else
    {
        ptr=ptr->right;
        while(ptr->Lthread==false)
        ptr=ptr->left;
        return ptr;
    }
}
struct node *inPred(struct node *ptr)
{
    if(ptr->Lthread==true)
    {
        return ptr->left;
    }
    else
    {
        ptr=ptr->left;
        while(ptr->Rthread==false)
        ptr=ptr->right;
        return ptr;   
    }
}

void inorder(struct node *p)
{
	struct node *ptr=p;
	while(ptr->Lthread==false)
		ptr=ptr->left;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=inSucc(ptr);
	}
}
void preorder(struct node *p)
{
	struct node *ptr=p;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		if(ptr->Lthread==false)
			ptr=ptr->left;
		else if(ptr->Rthread==false)
			ptr=ptr->right;
		else
		{
			while(ptr!=NULL && ptr->Rthread==true)
				ptr=ptr->right;
			if(ptr!=NULL)
				ptr=ptr->right;
		}
	}
}

