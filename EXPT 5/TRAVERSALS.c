#include<stdio.h>
#include<stdlib.h>

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


void preorder(struct node *p)
{
    if(p==NULL)
    return;

    printf("%d ",p->data);
    preorder(p->left);
    preorder(p->right);
}

void inorder(struct node *p)
{
    if(p==NULL)
    return;

    inorder(p->left);
    printf("%d ",p->data);
    inorder(p->right);
}

void postorder(struct node *p)
{
    if(p==NULL)
    return;
    postorder(p->left);
     postorder(p->right);
    printf("%d ",p->data);
   
}
int height(struct node *ptr)
{
    int Hleft,Hright;
    if(ptr==NULL)
    return 0;
    Hleft=height(ptr->left);
    Hright=height(ptr->right);
    if(Hleft > Hright)
    return Hleft+1;
    else
    return Hright+1;  
}



void displaygivenlevel(struct node *ptr, int level)
{
    if(ptr==NULL)
    return;
    if(level==1)
    printf("%d ",ptr->data);
    else if(level>1)
    {
    displaygivenlevel(ptr->left,level-1);

    displaygivenlevel(ptr->right,level-1);

    }
}
void levelorder(struct node *ptr)
{
    int h=height(ptr);
    int i;
    for(i=1;i<=h;i++)
    displaygivenlevel(ptr,i);
}


int main()
{
    struct node *root=NULL;
    int choice,i,data;

    while(1)
    {
        printf("\n\n1: ENTER A NODE\n");
        printf("2: PREORDER TRAVERSAL\n");
        printf("3: INORDER TRAVERSAL\n");
        printf("4: POSTORDER TRAVERSAL\n");
        printf("5: LEVELORDER TRAVERSAL\n");
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
            printf("PREORDER: ");
            preorder(root);
            break;

            case 3:
            printf("INORDER: ");
            inorder(root);
            break;

            case 4:
            printf("POSTORDER: ");
            postorder(root);
            break;

            case 5:
            printf("LEVEL ORDER: ");
            levelorder(root);
            break;
        }
    }
}