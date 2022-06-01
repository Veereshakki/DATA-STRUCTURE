#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;

};
struct node *top=0;
void push()
{
    struct node *newn;
    newn=(struct node*)malloc(sizeof(struct node));
    if(newn==NULL)
    {
        printf("Memory Error!!!");
        exit(0);
    }
    printf("Enter the data :");
    scanf("%d",&newn->data);
    newn->next=NULL;
    if(top==0)
    {
        top=newn;
    }
    else
    {
        newn->next=top;
        top=newn;
    }
}
void pop()
{
    struct node *temp;
    if(top==NULL)
    {
        printf("Stack is empty !!!\n");
    }
    else
    {
        temp=top;
    printf("Poped element is :%d ",top->data);
       top= top->next;
       free(temp);


    }
}
void display()
{
    struct node* temp;
    if(top==0)
    {
        printf("stack is empty !");

    }
    else
    {
    temp=top;
    while(temp!=NULL)
    {
    printf("%d->",temp->data);
    temp=temp->next;
    }
    printf("NULL");
    }
}
int main()
{
    int ch;
    while(1)
    {
    printf("\nEnter your choice :\n 1:push\n  2:pop  \n 3:display\n 4:exit;\n");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1:push();
            break;
        case 2:pop();
            break;
        case 3:display();
              break;
        case 4:exit(0);
            break;
        default :
            printf("\ninvalid choice\n");
    }
    }
    return 0;
}
