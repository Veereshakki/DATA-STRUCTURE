#include <stdio.h>
#include <stdlib.h>
void read(int A[], int n);
void display(int A[], int n);
void swap(int A[],int B[],int);
int main()
{
    int A[30], B[30], n;
    printf("\nEnter size of an array:");
    scanf("%d", &n);
    if (n <= 0 || n > 30)
    {
        printf("Invalid Array Size");
        exit(0);
    }
    read(A, n);
    read(B, n);
    swap(A,B,n);
    display(A, n);
    display(B, n);
}

void read(int A[], int n)
{
    int i;
    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
}
void display(int A[], int n)
{
    int i;
    printf("\nThe array elements after swaping :\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", A[i]);
    }
}
void swap(int A[],int B[],int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        temp=A[i];
        A[i]=B[i];
        B[i]=temp;
    }
    

}
