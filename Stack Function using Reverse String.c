//AIM:- To perform Stack Operations (Push,Pop,Exit) using Reverse String operation in DSA using C programming

#include<stdio.h>
#include<stdlib.h>
int TOP=-1,MAX;
char*STACK;
void PUSH(char item)
{
    if(TOP==MAX-1)
    {
        printf("Stack Overflow");
    }
    else
    {
        TOP=TOP+1;
        STACK[TOP]=item;
    }
}
char POP()
{
    char item;
    if(TOP==-1)
    {
        printf("Stack Underflow/empty\n");
        return '\0';
    }
    else
    {
        item=STACK[TOP];
        TOP=TOP-1;
        return item;
    }
}
int main()
{
    printf("Enter the size of string to reverse:");
    scanf("%d",&MAX);
    char stringToReverse[MAX];
    STACK=(char*)malloc(MAX*sizeof (char));
    printf("Please enter the string of size %d to reverse:",MAX);
    scanf("%s",stringToReverse);
    for(int i=0;i<MAX;i++)
    {
        PUSH(stringToReverse[i]);
    }
    printf("Reversed String:");
    for(int c=0;c<MAX;c++)
    {
        printf("%c",POP());
    }
    return 0;
}
