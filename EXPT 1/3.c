#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n;
typedef struct vaccine{
	char name[30];
	int age;
	char gender[6];
	char vaccineName[20];
	int d1,m1,y1;
	int d2,m2,y2;
}vaccine;

void input(vaccine p1[])
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("ENTER DETAILS OF PERSON %d\n",i+1);
		printf("ENTER YOUR NAME: ");
		scanf("%s",&p1[i].name);
		printf("ENTER YOUR AGE: ");
		scanf("%d",&p1[i].age);
		printf("ENTER YOUR GENDER: ");
		scanf("%s",&p1[i].gender);
		printf("ENTER VACCINE NAME: ");
		scanf("%s",&p1[i].vaccineName);
		printf("ENTER DATE OF FIRST DOSE (DD-MM-YY): ");
		scanf("%d-%d-%d",&p1[i].d1,&p1[i].m1,&p1[i].y1);
		printf("ENTER DATE OF SECOND DOSE (DD-MM-YY): ");
		scanf("%d-%d-%d",&p1[i].d2,&p1[i].m2,&p1[i].y2);
		printf("\n");
	}
}

void output(vaccine p1[])
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("NAME: %s\n",p1[i].name);
		printf("AGE: %d\n",p1[i].age);
		printf("GENDER: %s\n",p1[i].gender);
		printf("VACCINE NAME: %s\n",p1[i].vaccineName);
		printf("DATE OF FIRST DOSE: %d-%d-%d\n",p1[i].d1,p1[i].m1,p1[i].y1);
		printf("DATE OF FIRST DOSE: %d-%d-%d\n",p1[i].d2,p1[i].m2,p1[i].y2);
	}
}


int main()
{
	
	int i;
	printf("ENTER NUMBER OF PEOPLE WHOSE DATA NEEDS TO BE ENTERED\n");
	scanf("%d",&n);
	
	vaccine *p1=malloc(n*sizeof(vaccine));
	input(p1);
	output(p1);
}