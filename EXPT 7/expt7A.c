#include<stdio.h>
#include<stdlib.h>
#define CNT 10
#define TRUE 1
#define FALSE 0
struct node
{
    int data;
    struct node* left;
    struct node* right;
    int balance;
};
struct node* rightRotate(struct node* pptr);
struct node* leftRotate(struct node* pptr);
struct node* insert(struct node* p, int data);
struct node* insert_left_check(struct node* pptr, int *taller);
struct node* leftbalance(struct node* pptr);
struct node* insert_right_check(struct node* pptr, int *taller);
struct node* rightbalance(struct node* pptr);
struct node* del(struct node* p, int data);
struct node* del_left_check(struct node* pptr, int *shorter);
struct node* del_leftbalance(struct node* pptr, int *shorter);
struct node* del_right_check(struct node* pptr, int *shorter);
struct node* del_rightbalance(struct node* pptr, int *shorter);
void display(struct node *root, int space);
int main()
{
    struct node *root=NULL;
    int ch, data;
    do
    {
        printf("Press 1. INSERT NODE\n");
		printf("Press 2. DELETE A NODE\n");
		printf("Press 3. DISPLAY\n");
		printf("Press 4. EXIT\n");
		printf("ENTER YOUR CHOICE: ");
		scanf("%d",&ch);
        switch(ch)
		{
			case 1:
				printf("ENTER THE DATA: ");
				scanf("%d",&data);
				root=insert(root, data);
				break;
			case 2:
				printf("ENTER THE DATA: ");
				scanf("%d",&data);
				root=del(root, data);
				break;
			case 3:
				display(root, 0);
				break;
			case 4:
				break;
			default:
				printf("INVALID INPUT");
		}
		printf("\n\n");
    } while(ch!=4);
    return 0;
}
struct node* rightRotate(struct node* pptr)
{
    struct node* aptr=pptr->left;
    pptr->left=aptr->right;
    aptr->right=pptr;
    return aptr;
}
struct node* leftRotate(struct node* pptr)
{
    struct node* aptr=pptr->right;
    pptr->right=aptr->left;
    aptr->left=pptr;
    return aptr;
}
struct node* insert(struct node* p, int data)
{
    static int taller;
	if(p==NULL)
	{
		p=(struct node*)malloc(sizeof(struct node));
		p->data=data;
		p->left=NULL;
		p->right=NULL;
        p->balance=0;
        taller=TRUE;
	}
	else if(p->data > data)
    {
        p->left=insert(p->left, data);
        if(taller==TRUE)
            p=insert_left_check(p, &taller);
    }
	else if(p->data < data)
    {
        p->right=insert(p->right, data);
        if(taller==TRUE)
            p=insert_right_check(p, &taller);
    }
	else
    {
        printf("DUPLICATE DATA\n");
        taller=FALSE;
    }
	return p;
}
struct node* insert_left_check(struct node* pptr, int *taller)
{
    switch(pptr->balance)
    {
        case 0:
            pptr->balance=1;
            break;
        case -1:
            pptr->balance=0;
            *taller=FALSE;
            break;
        case 1:
            pptr=leftbalance(pptr);
            *taller=FALSE;
            break;
    }
    return pptr;
}
struct node* leftbalance(struct node* pptr)
{
    struct node *aptr=pptr->left, *bptr;
    if(aptr->balance==1)
    {
        aptr->balance=0;
        pptr->balance=0;
        pptr=rightRotate(pptr);
    }
    else
    {
        bptr=aptr->right;
        switch (bptr->balance)
        {
            case -1:
                aptr->balance=1;
                pptr->balance=0;
                break;
            case 1:
                aptr->balance=0;
                pptr->balance=-1;
                break;
            case 0:
                aptr->balance=0;
                pptr->balance=0;
                break;
        }
        bptr->balance=0;
        pptr->left=leftRotate(aptr);
        pptr=rightRotate(pptr);
    }
    return pptr;
}
struct node* insert_right_check(struct node* pptr, int *taller)
{
    switch(pptr->balance)
    {
        case 0:
            pptr->balance=-1;
            break;
        case 1:
            pptr->balance=0;
            *taller=FALSE;
            break;
        case -1:
            pptr=rightbalance(pptr);
            *taller=FALSE;
            break;
    }
    return pptr;
}
struct node* rightbalance(struct node* pptr)
{
    struct node *aptr=pptr->right, *bptr;
    if(aptr->balance==-1)
    {
        aptr->balance=0;
        pptr->balance=0;
        pptr=leftRotate(pptr);
    }
    else
    {
        bptr=aptr->left;
        switch (bptr->balance)
        {
            case -1:
                aptr->balance=0;
                pptr->balance=1;
                break;
            case 1:
                aptr->balance=-1;
                pptr->balance=0;
                break;
            case 0:
                aptr->balance=0;
                pptr->balance=0;
                break;
        }
        bptr->balance=0;
        pptr->right=rightRotate(aptr);
        pptr=leftRotate(pptr);
    }
    return pptr;
}
struct node* del(struct node* p, int data)
{
    static int shorter;
	struct node* t;
	if(p==NULL)
    {
        printf("DATA NOT FOUND\n");
        shorter=FALSE;
    }
	else if(p->data > data)
	{
        p->left=del(p->left, data);
        if(shorter==TRUE)
            p=del_left_check(p, &shorter);
    }
	else if(p->data < data)
	{
        p->right=del(p->right, data);
        if(shorter==TRUE)
            p=del_right_check(p, &shorter);
    }
	else
	{
		if(p->left!=NULL && p->right!=NULL)
		{
			t=p->right;
			while(t->left!=NULL)
				t=t->left;
			p->data=t->data;
			p->right=del(p->right, t->data);
            if(shorter==TRUE)
                p=del_right_check(p, &shorter);
		}
		else
		{
			t=p;
			if(p->left!=NULL)
				p=p->left;
			else if(p->right!=NULL)
				p=p->right;
			else
				p=NULL;
            shorter=TRUE;
			free(t);
		}
	}
	return p;
}
struct node* del_left_check(struct node* pptr, int *shorter)
{
    switch(pptr->balance)
    {
        case 0:
            pptr->balance=-1;
            *shorter=FALSE;
            break;
        case 1:
            pptr->balance=0;
            break;
        case -1:
            pptr=del_rightbalance(pptr, shorter);
            break;
    }
    return pptr;
}
struct node* del_rightbalance(struct node* pptr, int *shorter)
{
    struct node *aptr=pptr->right, *bptr;
    if(aptr->balance==0)
    {
        aptr->balance=1;
        pptr->balance=-1;
        *shorter=FALSE;
        pptr=leftRotate(pptr);
    }
    else if(aptr->balance==-1)
    {
        aptr->balance=0;
        pptr->balance=0;
        pptr=leftRotate(pptr);
    }
    else
    {
        bptr=aptr->left;
        switch(bptr->balance)
        {
            case 0:
                aptr->balance=0;
                pptr->balance=0;
                break;
            case 1:
                aptr->balance=-1;
                pptr->balance=0;
                break;
            case -1:
                aptr->balance=0;
                pptr->balance=1;
        }
        bptr->balance=0;
        pptr->right=rightRotate(aptr);
        pptr=leftRotate(pptr);
    }
    return pptr;
}
struct node* del_right_check(struct node* pptr, int *shorter)
{
    switch(pptr->balance)
    {
        case 0:
            pptr->balance=1;
            *shorter=FALSE;
            break;
        case -1:
            pptr->balance=0;
            break;
        case 1:
            pptr=del_leftbalance(pptr,shorter);
            break;
    }
    return pptr;
}
struct node* del_leftbalance(struct node* pptr, int *shorter)
{
    struct node *aptr=pptr->left, *bptr;
    if(aptr->balance==0)
    {
        aptr->balance=-1;
        pptr->balance=1;
        *shorter=FALSE;
        pptr=rightRotate(pptr);
    }
    else if(aptr->balance==1)
    {
        aptr->balance=0;
        pptr->balance=0;
        pptr=rightRotate(pptr);
    }
    else
    {
        bptr=aptr->right;
        switch(bptr->balance)
        {
            case 0:
                aptr->balance=0;
                pptr->balance=0;
                break;
            case 1:
                aptr->balance=0;
                pptr->balance=-1;
                break;
            case -1:
                aptr->balance=1;
                pptr->balance=0;
        }
        bptr->balance=0;
        pptr->left=leftRotate(aptr);
        pptr=rightRotate(pptr);
    }
    return pptr;
}
void display(struct node *root, int space)
{
	int i;
    if(root==NULL)
    	return;
    space+=CNT;
    display(root->right, space);
    printf("\n");
    for(i=CNT;i<space;i++)
        printf(" ");
    printf("%d\n",root->data);
    display(root->left, space);
}