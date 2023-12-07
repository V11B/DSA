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
    printf("Before insertion at first:\n");
    traverse();
    insert_at_first();
    printf("After insertion at first:\n");
    traverse();
}
