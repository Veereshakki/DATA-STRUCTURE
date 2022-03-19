
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *previous;
};

typedef struct Node *node;
node getnode();
node insert_front(node head);
node insert_rear(node head);
node delete_front(node head);
node delete_rear(node head);
node insert_pos(node head);
node delete_pos(node head);
void display_forward(node head);
void display_reverse(node head);

int main()
{
    node head = NULL;
    int choice;
    while (1)
    {
        printf("\nEnter 1.Insert_front\t2.Insert_rear\t3.Delete_front\t4.Delete_rear\t5.Insert_pos\t6.Delete_pos\t7.Display_forward\t8.display_reverse\t9.Exit\n");
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
            head = insert_pos(head);
            break;
        case 6:
            head = delete_pos(head);
            break;
        case 7:
            printf("\n==================================================================================================================================\n");
            printf("displaying entered data:\t");
            display_forward(head);
            printf("\n==================================================================================================================================\n");
            break;
        case 8:
            printf("\n==================================================================================================================================\n");
            printf("displaying entered data in reverse order:\t");
            display_reverse(head);
            printf("\n==================================================================================================================================\n");
            break;
        case 9:
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
    new->previous = NULL;
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
    new->next = head;
    head->previous = new;
    head = head->previous;
    return head;
}

node insert_rear(node head)
{
    node new, c = head;
    new = getnode();
    if (head == NULL)
    {
        return new;
    }
    while (c->next != NULL)
    {
        c = c->next;
    }
    c->next = new;
    new->previous = c;
    return head;
}

node delete_front(node head)
{
    node c = head;
    if (head == NULL)
    {
        printf("Empty list!!\n");
        return head;
    }

    head = head->next;
    head->previous = NULL;
    c->next = NULL;
    printf("\ndeleted data is %d\n", c->data);
    free(c);
    return head;
}

node delete_rear(node head)
{
    node c = head;
    if (head == NULL)
    {
        printf("Empty list!!\n");
        return head;
    }

    while (c->next != NULL)
    {
        c = c->next;
    }
    c->previous->next = NULL;
    c->previous = NULL;
    printf("\ndeleted data is %d\n", c->data);
    free(c);
    return head;
}

node insert_pos(node head)
{
    node new, c = head;
    int pos;
    new = getnode();
    printf("Enter the position\n");
    scanf("%d", &pos);

    if (head == NULL && pos == 1)
    {
        return new;
    }

    if (head == NULL && pos != 1)
    {
        printf("Invalid position,enter 1 as position\n");
        return;
    }

    if (head != NULL && pos == 1)
    {
        new->next = head;
        head->previous = new;
        head = head->previous;
        return head;
    }

    int count = 1;
    while (c->next != NULL && count != pos)
    {
        c = c->next;
        count++;
    }

    if (count == pos)
    {
        new->next = c;
        c->previous->next = new;
        new->previous = c->previous;
        c->previous = new;
        return head;
    }

    if (pos == count + 1)
    {
        while (c->next != NULL)
        {
            c = c->next;
        }
        c->next = new;
        new->previous = c;
        return head;
    }

    if (pos > count + 1)
    {
        printf("\nInvalid position\n");
        return head;
    }
}

node delete_pos(node head)
{
    node c = head;
    int pos;
    printf("Enter position\n");
    scanf("%d", &pos);
    if (head == NULL)
    {
        printf("Empty list!!\n");
        return head;
    }

    if (head->next == NULL && pos == 1)
    {
        return NULL;
    }

    if (head->next != NULL && pos == 1)
    {
        head = head->next;
        head->previous = NULL;
        c->next = NULL;
        printf("\ndeleted data is %d\n", c->data);
        free(c);
        return head;
    }

    int count = 1;

    while (c->next != NULL && count != pos)
    {
        c = c->next;
        count++;
    }

    if (count == pos)
    {
        c->previous->next = c->next;
        c->next->previous = c->previous;
        c->next = NULL;
        c->previous = NULL;
        printf("\ndeleted data is %d\n", c->data);

        free(c);
        return head;
    }

    if (pos > count)
    {
        printf("\nInvalid position\n");
        return head;
    }
}

void display_forward(node head)
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

void display_reverse(node head)
{
    node c = head;
    if (head == NULL)
    {
        printf("Empty list!!\n");
    
    }

    while (c->next != NULL)
    {
        c = c->next;
    }

    while (c->previous != NULL)
    {
        printf("%d\t", c->data);
        c = c->previous;
    }
    printf("%d\t", c->data);
}
   