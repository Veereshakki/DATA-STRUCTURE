#include <stdio.h>
#define MAXSIZE 100
void display(int[], int);
int main()
{
    int n;
    int Arr[MAXSIZE];
    printf("Enter the size of an array :");
    scanf("%d", &n);
    printf("Enter the array elements :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &Arr[i]);
    }
    display(Arr, n); // always pass by reference
}
void display(int x[], int n)
{
    printf("Array elements in the reverse order is:\n");
    for (int i=(n - 1); i >= 0; --i)
    {
        printf("%d\n", x[i]);
    }
}
