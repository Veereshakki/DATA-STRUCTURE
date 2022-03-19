#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node *node;
/*node getnode();
node insert_front(node first);
node insert_rear(node first);
void display(node first);
node delete_front(node first);
node delete_rear(node first);*/

node getnode()
{
    node t;
    int item;
    t = (node)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("memory not allocated\n");
    }
    printf("Enter item to be inserted\n");
    scanf("%d", &item);
    t->data = item;
    t->next = NULL;
    return t;
}

node insert_front(node first)
{
    node t;
    t = getnode();
    if (first == NULL)
    {
        return t;
    }
    t->next = first;
    return t;
}

node insert_rear(node first)
{

    node t;
    node c;
    t = getnode();
    if (first == NULL)
    {
        return t;
    }
    c = first;
    while (c->next != NULL)
    {
        c = c->next;
    }
    c->next = t;
    return first;
}

void display(node first)
{
    node c;
    if (first == NULL)
    {
        printf("list is empty\n");
    }

    else
        c = first;
    printf("elements in the list are\n");
    while (c != NULL)

    {
        printf("%d->", c->data);
        c = c->next;
    }
}

node delete_front(node first)
{

    node c;

    if (first == NULL)
    {

        printf("list is empty\n");
        return first;
    }
    c = first;
    first = first->next;
    printf("element deleted is %d\n", c->data);
    c->next = NULL;
    free(c);
    return first;
}

node delete_rear(node first)
{

    node c;
    node prev;
    c = first;
    if (first == NULL)
    {

        printf("List is empty\n");
        exit(0);
    }
    while (c->next != NULL)
    {
        prev = c;
        c = c->next;
    }
    prev->next = NULL;
    free(c);
    return first;
}
node delete_specific(node first)
{
    node temp, p;
    int pos, i = 1;
    if (first == NULL)
    {
        printf("\nThe List is Empty !\n");
        exit(0);

    }
    printf("\nEnter the position to delete the element: ");
    scanf("%d", &pos);
    temp = first;
    if(pos==1)
    {
        p=first;
        first=p->next;
        printf("Deleted element is %d ",p->data);
        free(p);
        return first;
    }
    while (i <= pos - 1)
    {
        temp = temp->next;
        i++;
    }
    p = temp->next;
    temp->next = p->next;
    printf("Deleted element is :%d", temp->data);
    free(temp);
    return first;
}

int main()
{
    node first = NULL;
    int choice;
    while (1)
    {
        printf("\nEnter\n1-Insert front\t2-Insert rear\t3-display\t4-delete front\t5-delete rear\t6-delete specific\t7-exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            first = insert_front(first);
            break;
        case 2:
            first = insert_rear(first);
            break;
        case 3:
            display(first);
            break;

        case 4:
            first = delete_front(first);
            break;
        case 5:
            first = delete_rear(first);
            break;
        case 6:
            first = delete_specific(first);
            break;

        case 7:
            exit(0);
            // break;
        }
    }
}