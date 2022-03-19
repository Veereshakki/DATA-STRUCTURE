#include<stdio.h>
void read_array(int a[],int n);
void print_array(int a[],int n);
void add(int a[],int n);

void main()
{
    int a[20],n;
    printf("enter number of elements in an array\n");
    scanf("%d",&n);
    printf("Enter array elements\n");
    read_array(a,n);
    printf("Array elements are\n");
    print_array(a,n);
    add(a,n);
}

void read_array(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}

void print_array(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}

void add(int a[],int n)
{
    int i,j,k,l,r,flag=0;
    for(i=0;i<n-1;i++)
    {
        int rs=0,ls=0;
        l=i-1;
        r=i+1;

        while(l>=0)               //for(j=l;j>=0;j--)
        {
            ls=ls+a[l];
            l--;
        }

        while(r<n)                //for(k=r;k<n;k++)
        {
            rs=rs+a[r];
            r++;
        }
        if(ls==rs)
        {
            printf("Equilibrium index= %d\n",i);
            flag=1;
        }
    }

    if(flag==0)
    {
        printf("There is no equilibrium index in the  array\n");
    }
}