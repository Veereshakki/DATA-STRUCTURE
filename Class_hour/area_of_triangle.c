#include <stdio.h>

int main()
{
    int *pb, *ph, b, h;
    float *Area, A;
    pb = &b;
    ph = &h;
    Area = &A;
    printf("Enter hieght and base of triangle :");
    scanf(" %d %d", ph, pb);
    *Area = 0.5 * (*pb) * (*ph);
    printf("Area of the triangle : %0.2f", *Area);

    return 0;
}