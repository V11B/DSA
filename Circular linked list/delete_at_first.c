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
void delete_at_first()
{
    struct node *te;
    te = head;
    if (head == NULL)
    {
        printf("Node is empty....");
    }
    else
    {
        head = head->next;
        tail->next = head;
        free(te);
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
    printf("Before deletion\n");
    traverse();
    delete_at_first();
    printf("\nAfter deletion\n");
    traverse();
}