#include<stdio.h>

void read_array(int a[], int n);
void print_array(int a[], int n);
void add(int a[], int n, int m);
void main()
{
    int a[20], m, n;
    printf("enter number of elements in an array\n");
    scanf("%d", &n);
    printf("enter value of m\n");
    scanf("%d", &m);
    printf("Enter array elements\n");
    read_array(a, n);
    printf("Array elements are\n");
    print_array(a, n);
    add(a, n, m);
}

void read_array(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void print_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void add(int a[], int n, int m)
{
    int i, j, sum;
    for (i = 0; i < n - m; i++)
    {
        sum = 0;
        for (j = i + 1; j <= i + m; j++)
        {
            sum = sum + a[j];
        }

        printf("Sum of next %d numbers from %d is %d\n", m, a[i], sum);
    }
}