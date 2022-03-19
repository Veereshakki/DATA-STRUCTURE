#include <stdio.h>
void add(int *, int *, int *);
int main()
{
    int a, b, c, *p1, *p2, *p3;
    p1 = &a;
    p2 = &b;
    p3 = &c;
    printf("Enter two numbers :\n");
    scanf("%d%d", p1, p2);
    add(p1, p2, p3);
    printf("\nSum of two numbers : %d", *p3);

    return 0;
}
void add(int *p1, int *p2, int *p3)
{
    *p3 = *p1 + *p2;
}