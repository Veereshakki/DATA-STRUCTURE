#include <stdio.h>
void biggest(int *, int *);
int main()
{
    int a, b, *p1, *p2;
    p1 = &a;
    p2 = &b;
    printf("Enter two numbers: \n");
    scanf("%d%d", p1, p2); 
     //call by reference :we pass address form actual parameter to formal parameter
    biggest(p1,p2);
    return 0;
}
void biggest(int *p1, int *p2)
{
    if (*p1 > *p2)
    {
        printf("%d is biggest ", *p1);
    }
    else
    {
        printf("%d is smallest ", *p2);
    }
}