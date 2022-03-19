#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

typedef struct Node *node;
node getnode();
node insert_front(node head);
node insert_rear(node head);
node delete_front(node head);
node delete_rear(node head);
void display(node head);

int main()
{
    node head = NULL;
    int choice;
    while (1)
    {
        printf("\nEnter 1.Insert_front\t2.Insert_rear\t3.Delete_front\t4.Delete_rear\t5.Display\t6.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head = insert_front(head);
            break;
        case 2:
            head = insert_rear(head);
            break;
        case 3:
            head = delete_front(head);
            break;
        case 4:
            head = delete_rear(head);
            break;
        case 5:
            display(head);
            break;
        case 6:
          exit(0);
        
        }
    }
}

node getnode()
{
    node new;
    new = (node)malloc(sizeof(struct Node));
    if (new == NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    printf("enter data\n");
    scanf("%d", &new->data);
    new->next = NULL;
    new->prev = NULL;
    return new;
}
node insert_front(node head)
{
    node new;
    new = getnode();
    if (head == NULL)
    {
        return new;
    }
    head->prev = new;
    new->next = head;
    return new;
}
node insert_rear(node head)
{
    node cur, new;
    new = getnode();
    if (head == NULL)
    {
        return new;
    }
    cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = new;
    new->prev = cur;
    return head;
}
node delete_front(node head)
{
    node cur=head;
    if (head == NULL)
    {
        printf("List is Empty !\n");
        return head;
    }
    head = head->next;
    head->prev = NULL;
    cur->next = NULL;
    printf("Deleted Data is %d ", cur->data);
    free(cur);
    return head;
}
node delete_rear(node head)
{
     if (head == NULL)
    {
        printf("List is Empty! \n");
        return head;
    }
    node cur=head;
    node prev=NULL;
    while (cur->next != NULL)
    {
        prev=cur;
        cur = cur->next;
    }
    prev->next=NULL;
    cur->prev = NULL;
    cur->next = NULL;
    free(cur);
    return head;
}
void display(node head)
{
    node c = head;
    if (head == NULL)
    {
        printf("empty list\n");
    }

    while (c->next != NULL)
    {
        printf("%d\t", c->data);
        c = c->next;
    }
   printf("%d\t", c->data);
}
