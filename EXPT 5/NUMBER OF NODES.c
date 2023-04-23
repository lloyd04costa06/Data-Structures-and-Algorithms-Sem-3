//write a program to display the width of binary search tree and also the level
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
int width(struct node* root, int level);
int height(struct node* root);
int main()
{
	int n, i, h, data;
	struct node* root=NULL;
	printf("ENTER NUMBER OF NODES: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("ENTER THE DATA: ");
		scanf("%d",&data);
		root=insert(root, data);
	}
	h=height(root);
	for(i=0;i<h;i++)
		printf("\nLEVEL %d NUMBER OF NODES %d\n",i, width(root, i));
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
		printf("DUPLICATE\n");
	return p;
}
int width(struct node* root, int level)
{
	if(root==NULL)
		return 0;
	else if(level==0)
		return 1;
	else 
		return width(root->left, level-1) + width(root->right, level-1);
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