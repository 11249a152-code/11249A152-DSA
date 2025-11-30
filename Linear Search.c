//AIM:- To perform Linear Search operation in DSA using C programming

#include<stdio.h>
#include<stdbool.h>
int main()
{
    int i,n,key;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements in array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the value to be searched\n");
    scanf("%d",&key);
    bool flag;
    flag=false;
    for(i=0;i<n;i++)
    {
       if(arr[i]=key)
       {
           printf("Element found at position %d,%d\n",arr[i]);
           flag=true;
           break;
       }
    }
    if(flag)
    {
         printf("Element not found");
    }
    return 0;
}
