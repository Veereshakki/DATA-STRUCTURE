#include <stdio.h>
#include<stdlib.h>
struct employee
{
    int id;
    char name[50];
};

int main()
{
    int n;
    struct employee e1[10];
    printf("Enter total number of employees :");
    scanf("%d",&n);
    printf("Enter the employee details:");
    for (int  i = 0; i < n; i++)
    {
        scanf("%d%s",&e1[i].id,&e1[i].name);
    }
    for (int i = 0; i < n; i++)
    {
        printf("Employee Id : %d",e1[i].id);
        printf("Employee Name :%s",e1[i].name);
    }
    
    
    return 0;
}