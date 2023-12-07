#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head = NULL;
void create()
{
    struct node *newnode, *temp;
    int choice;
    while (1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data for newnode :");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        temp->next = head;
        printf("enter your choice:");
        scanf("%d", &choice);
        if (choice == 0)
        {
            break;
        }
    }
}
void traverse()
{
    struct node *t;
    if (head == NULL)
    {
        printf("cll is empty.......... ");
    }
    else
    {
        t = head;
        while (t->next != head)
        {
            printf("%d\t", t->data);
            t = t->next;
        }
        printf("%d", t->data);
    }
}
int main()
{
    create();
    traverse();
}