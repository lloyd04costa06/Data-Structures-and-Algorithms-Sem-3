#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct node
{
	struct node* left;
	int data;
	struct node* right;
};
struct node* insert(struct node* p, int data);
void levelnode(struct node* root, int lv);
int height(struct node* root);
int main()
{
	int n, i, data, lv;
	struct node* root=NULL;
	printf("ENTER NUMBER OF NODES: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("ENTER THE DATA: ");
		scanf("%d",&data);
		root=insert(root, data);
	}
	while(1)
	{
		printf("\nENTER THE LEVEL (ENTER NEGATIVE NUMBER TO EXIT): ");
		scanf("%d",&lv);
		if(lv<0)
			break;
		levelnode(root, lv);
	}
	return 0;
}
struct node* insert(struct node* p, int data)
{
	if(p==NULL)
	{
		p=(struct node*)malloc(sizeof(struct node));
		p->data=data;
		p->left=NULL;
		p->right=NULL;
	}
	else if(p->data > data)
		p->left=insert(p->left, data);
	else if(p->data < data)
		p->right=insert(p->right, data);
	else
		printf("Duplicate data\n");
	return p;
}
void levelnode(struct node* root, int lv)
{
	if(root==NULL)
		return;
	else if(lv==0)
		printf("%d ",root->data);
	else{
		levelnode(root->left, lv-1);
		levelnode(root->right, lv-1);
	}
}
int height(struct node* root)
{
	int lheight, rheight;
	if(root==NULL)
		return 0;
	lheight=height(root->left);
	rheight=height(root->right);
	if(lheight > rheight)
		return lheight+1;
	else
		return rheight+1;
}
