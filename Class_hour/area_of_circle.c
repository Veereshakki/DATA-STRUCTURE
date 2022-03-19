#include <stdio.h>
#define PI 3.142

int main()
{
    int *pb, b;
    float *Area, A;
    pb = &b;
    Area = &A;
    printf("Enter radius of circle :");
    scanf("%d",pb);
    *Area = PI* (*pb) * (*pb);
    printf("Area of the triangle : %0.2f", *Area);

    return 0;
}