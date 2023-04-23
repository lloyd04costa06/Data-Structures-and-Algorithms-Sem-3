#include<stdio.h>
#include<stdlib.h>
int search;
struct node
{
	struct node *prev;
	int data;
	struct node *next;	
}*last=NULL;



void addEmpty(int data)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    last=temp;
    temp->next=temp;
    temp->prev=temp;
}

void addBeg(int data)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=last->next;
    last->next->prev=temp;
    temp->prev=last;
    last->next=temp;
}
void addEnd(int data)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    
    temp->prev=last;
    temp->next=last->next;
    temp->next->prev=temp;
    last->next=temp;
    last=temp;
}


void display()
{
    struct node *p;
   
    if(last==NULL)
    {
        printf("\nTHE LIST IS EMPTY\n");
        return;
    }
    p=last->next;
    printf("THE LIST IS: ");
    do{
        printf("%d ",p->data);
        p=p->next;
    }while(p!=last->next);

}

void displayREV()
{
    struct node *p;
    p=last;
     if(last==NULL)
    {
        printf("THE LIST IS EMPTY\n");
        return;
    }
    printf("\nTHE REVERSE LIST IS: ");
    do{
        printf("%d ",p->data);
        p=p->prev;
    }while(p!=last);
    
}

void addAfter()
{
    int key,data;
    printf("ENTER THE ELEMENT AFTER WHICH YOU WANT TO INSERT THE NEW ELEMENT: ");
    scanf("%d",&key);
    printf("ENTER NODE DATA: ");
    scanf("%d",&data);

    struct node *temp,*p;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;

    if(last->data==key)
    {
        temp->prev=last;
        temp->next=last->next;
        last->next->prev=temp;
        last->next=temp;
        last=temp;
        return;  
    }


    p=last->next;
    do{
        if(p->data==key)
        {
            temp->prev=p;
            temp->next=p->next;
            p->next=temp;
            temp->next->prev=temp;
            return;
        }
        p=p->next;
    }while(p!=last->next);
    printf("ELEMENT NOT FOUND\n");

}

void addBefore(){

    int data,key;
    printf("ENTER THE ELEMENT BEFORE WHICH YOU WANT TO INSERT THE NEW NODE: ");
    scanf("%d",&key);
    printf("ENTER THE NODE DATA: ");
    scanf("%d",&data);

    struct node *temp,*p;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;

    if(last->next->data==key)
    {
        temp->next=last->next;
        temp->prev=last;
        last->next->prev=temp;
        last->next=temp;
        return;
    }
    p=last->next;
    do{
        if(p->data==key)
        {
            temp->next=p;
            temp->prev=p->prev;
            p->prev->next=temp;
            p->prev=temp;
        }
        p=p->next;

    }while(p!=last->next);
    printf("ELEMENT NOT FOUND\n");
}

void createList()
{
    int i,data,n;
	printf("ENTER NUMBER OF NODES\n");
	scanf("%d",&n);
	
	if(n==0)
	return ;
	
	
	printf("ENTER THE DATA OF THE NODE: ");
	scanf("%d",&data);
	
	addEmpty(data);
	
	for(i=2;i<=n;i++)
	{
		printf("ENTER DATA OF THE NODE: ");
		scanf("%d",&data);
		addEnd(data);
		
	}
	return;
}

void del()
{
    struct node *temp,*p;
    int key;
    printf("ENTER THE ELEMENT TO BE DELETED: ");
    scanf("%d",&key);

    if(last==NULL)
    {
        printf("LIST EMPTY\n");
        return;
    }

    
    if(last->data==key&&last->next==last)
    {
        printf("%d DELETED SUCCESFULLY\n",last->data);
        temp=last;
        last=NULL;
        free(temp);
        return;
    }

    if(last->next->data==key)
    {
        temp=last->next;
        printf("%d DELETED SUCCESFULLY\n",temp->data);
        temp->next->prev=last;
        last->next=temp->next;
        free(temp);
        return;
    }
    if(last->data==key)
    {
        temp=last;
        last->prev->next=last->next;
        last->next->prev=last->prev;
        last=last->prev;
        free(temp);
        return;

    }
    p=last->next;
    do{
        if(p->data==key)
        {
            temp=p;
            printf("%d DELETED SUCCESFULLY\n",temp->data);
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            free(temp);
            return;
        }
        p=p->next;
    }while(p!=last->next);
    printf("ELEMENT NOT FOUND\n");


}

int main()
{
    int i,choice,data;
    struct node *last=NULL;

    while(1)
    {
        printf("\n\n_________________________________\n");	
        printf("1: CREATE A DOUBLY LINKEDLIST\n");
        printf("2: DISPLAY LINKED LIST\n");
        printf("3: DISPLAY LINKED LIST IN REVERSE\n");
        printf("4: ADD  TO EMPTY LIST\n");
        printf("5: ADD AT BEGINNING\n");
        printf("6: ADD AT THE END\n");
        printf("7: ADD AFTER A NODE\n");
        printf("8: ADD BEFORE A NODE\n");
        printf("9: DELETE A NODE\n");
        printf("0: PROGRAM END\n");
        printf("_________________________________\n");

        printf("ENTER THE CHOICE\n");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
            createList();
            break;

            case 2:
            display();
            break;

           case 3:
            displayREV();
            break;

            case 4:
            printf("ENTER THE DATA OF THE NODE: ");
	        scanf("%d",&data);
            addEmpty(data);
            break;

            case 5:
            printf("ENTER THE DATA OF THE NODE: ");
	        scanf("%d",&data);
            addBeg(data);
            break;

            case 6:
            printf("ENTER THE DATA OF THE NODE: ");
	        scanf("%d",&data);
            addEnd(data);
            break;

            case 7:
            addAfter();
            break;

            case 8:
            addBefore();
            break;

            case 9:
            del();
            break;

            case 0:
            return 0;
            
            default:
            printf("INVALID OPTION\n");


        }
    }
    
}