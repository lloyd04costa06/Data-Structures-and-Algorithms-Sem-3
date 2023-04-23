#include<stdio.h>
//FUNCTION DECLARATION
int FACT(int n);
	
int main() 
{
    int n;   								//VARIABLE DECLARATION
    printf("Enter a positive integer: ");   //INPUT N
    scanf("%d",&n);
    printf("%d! = %d\n", n, FACT(n));		//FACTORIAL OUTPUT
    return 0;
}

//FUNCTION TP FIND THE FACTORIAL
int FACT(int x)
{
    if (x==1) //BASE CASE
    return 1;
    else
    return (x*FACT(x-1));
}