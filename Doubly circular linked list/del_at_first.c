#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next, *pre;
} *head = NULL, *tail = NULL;

void create()
{
    struct node *newnode;
    int ch = 1;
    while (ch)
    {

        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter the data of the newnode:");
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
            newnode->next = head;
            newnode->pre = tail;
            head->pre = newnode;
            tail = newnode;
        }
        printf("enter the choice :");
        scanf("%d", &ch);
    }
}

void traversal()
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

void delete_at_first()
{
    struct node *temp;
    temp = head;
    if (head == NULL)
    {
        printf("CDLL is empty.........");
    }
    else if (head->next == head)
    {
        tail = head = NULL;
        free(temp);
    }
    else
    {
        head = head->next;
        tail->next = head;
        head->pre = tail;
        free(temp);
    }
}

int main()
{
    create();
    printf("\nBefore deleting\n");
    traversal();
    delete_at_first();
    printf("\nAfter deleting\n");
    traversal();
}