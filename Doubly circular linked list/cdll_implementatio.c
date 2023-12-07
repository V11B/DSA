#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *pre, *next;
} *head = NULL, *tail = NULL;

void create()
{
    struct node *newnode;
    int choice = 1;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter the data for newnode :");
        scanf("%d", &newnode->data);
        if (head == NULL)
        {
            head = tail = newnode;
            head->next = head;
            head->pre = head;
        }
        else
        {
            tail->next = newnode;
            newnode->pre = tail;
            newnode->next = head;
            head->pre = newnode;
            tail = newnode;
        }
        printf("Enter the choice 1 to continue and 0 to exit:");
        scanf("%d", &choice);
    }
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
    traverse();
    printf("\n");
    return 0;
}