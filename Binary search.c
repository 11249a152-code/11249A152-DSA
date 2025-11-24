//AIM:- To perform Binary Search operation in DSA using C programming

#include<stdio.h>
int main()
{
    int n,key;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements in sorted order:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the value to be searched:");
    scanf("%d",&key)
    int start=0,end=n-1,mid;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(arr[mid]==key)
        {
            printf("Element found at index %d",mid);
            return 0;
        }
        else if(arr[mid]<key)
        {
             start=mid+1;
        }
        else
        {
            end=mid-1;
        }
   }
   printf("Element %d not found in given array",key);
}