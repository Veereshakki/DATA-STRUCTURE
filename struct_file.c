#include <stdio.h>
#include <stdlib.h>
int main()
{
    int roll_no, n, i;
    char arr[10];
    FILE *fp;
    fp = fopen("student1.txt", "w");
    if (fp == NULL)
    {
        printf("Error in opening the file\n");
        exit(0);
    }
    printf("Enter the number of students\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the name of %d student\n", i + 1);
        scanf("%s", &arr);

        printf("Enter the roll number of %d student\n", i + 1);
        scanf("%d", &roll_no);

        printf("Data entered successfully\n");
        fprintf(fp, "Student name is %s\n Roll no is %d\n", arr, roll_no);
    }
    fclose(fp);
    return 0;
}