#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head = NULL, *tail = NULL;

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

void reverse()
{
    struct node *current, *previous, *nextnode;
    current = head;
    nextnode = current->next;
    if (head == NULL)
    {
        printf("LL is empty.............");
    }
    while (current != tail)
    {
        previous = current;
        current = nextnode;
        nextnode = current->next;
        current->next = previous;
    }
    nextnode->next = tail;
    head = tail;
    tail = nextnode;
}

void traverse()
{
    struct node *t;
    t = head;
    while (t->next != head)
    {
        printf("%d\t", t->data);
        t = t->next;
    }
    printf("%d\t", t->data);
}
int main()
{
    create();
    printf("Before reverse :\n");
    traverse();
    reverse();
    printf("After reverse :\n");
    traverse();
}