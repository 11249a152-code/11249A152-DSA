//AIM:-To perform Stack Operations(Push,Pop,Exit) in DSA using C programming

#include<stdio.h>
int main()
{
    int n,op,top,item;
    top=-1;
    printf("Enter the size of the stack);
    scanf("%d",&n);
    int arr[n];
    while(op<3)
   {
        printf("Choose the operation:{1.Push,2.Pop,3.Exit}\n");
        scanf("%d",&op);
        switch(op)
        {
            Case 1;
            if(top==n-1)
            {
                printf("Stack Overflow");
            }
            else
            {
                printf("Enter the element to be inserted:\n");
                scanf("%d",&item);
                top += 1;
                arr[top]=item;
            }
            break;

            Case 2:
            if(top==-1)
            {
                 printf("Stack Underflow");
            }
            else
            {
                item=arr[top];
                top=top-1;
                printf("The item is:%d\n",item);
            }
            break;

            Case 3:
            return 0;
            default:
            printf("No such operation is included\n");
       }
   }
   return 0;
}