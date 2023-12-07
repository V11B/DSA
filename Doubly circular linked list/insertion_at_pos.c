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
void insert_at_first()
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    printf("\nenter the data for new node:");
    scanf("%d", &new->data);
    if (head == NULL)
    {
        create();
    }
    else
    {
        new->next = head;
        head->pre = new;
        tail->next = new;
        new->pre = tail;
        head = new;
    }
}

void insert_at_pos()
{
    struct node *new, *current;
    int pos;
    new = (struct node *)malloc(sizeof(struct node));
    printf("enter  the postion:");
    scanf("%d", &pos);
    if (pos == 1)
    {
        insert_at_first();
    }
    else
    {
        current = head;
        printf("enter the data you want in newnode:");
        scanf("%d", &new->data);
        int i = 1;
        while (i < pos - 1)
        {
            current = current->next;
            i++;
        }
        new->pre = current;
        new->next = current->next;
        current->next->pre = new;
        current->next = new;
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
    printf("before insertion :");
    traverse();
    insert_at_pos();
    printf("after insertion :");
    traverse();
}