#include <stdio.h>

int main()
{
    int Arr[20], i, j, temp,n;
    printf("Enter the size of an array :\n");
    scanf("%d", &n);
    printf("\nEnter the array Elements :\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &Arr[i]);
    }
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < (n - 1); j++)
        {
            if(Arr[j]>Arr[j+1])
            {
                temp=Arr[j];
                Arr[j]=Arr[j+1];
                Arr[j+1]=temp;
            }
        }
    }
    printf("The sorted elements are :\t");
    for ( i = 0; i < n; i++)
    {
        printf("%d\t",Arr[i]);
    }
    

    return 0;
}