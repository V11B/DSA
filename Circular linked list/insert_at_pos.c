#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head = NULL, *tail = NULL;
// with head node:
void create()
{
    struct node *newnode;
    int choice;
    while (1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data for newnode :");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        tail->next = head;
        printf("Enter the choice :");
        scanf("%d", &choice);
        if (choice == 0)
        {
            break;
        }
    }
}

void insert_at_first()
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    printf("\nenter the data of the new node:");
    scanf("%d", &new->data);
    new->next = NULL;
    if (head == NULL)
    {
        head = tail = new;
    }
    else
    {
        new->next = head;
        head = new;
    }
    tail->next = head;
}
void insert_at_pos()
{
    struct node *new, *temp;
    int pos;
    printf("Enter the position at which you want to add data:");
    scanf("%d", &pos);
    printf("invalid position........");
    if (pos == 1)
    {
        insert_at_first();
    }
    else
    {
        new = (struct node *)malloc(sizeof(struct node));
        printf("\nenter the data of the new node:");
        scanf("%d", &new->data);
        int i = 1;
        new->next = NULL;
        temp = head;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        new->next = temp->next;
        temp->next = new;
    }
}
void traverse()
{
    struct node *temp;
    temp = head;
    while (temp->next != head)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("%d\t", temp->data);
}

int main()
{
    create();
    printf("Before insertion at pos:\n");
    traverse();
    insert_at_pos();
    printf("After insertion at pos:\n");
    traverse();
}
