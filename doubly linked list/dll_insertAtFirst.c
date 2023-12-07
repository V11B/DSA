#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *pre;
};
struct node *head = NULL;
// struct node *tail = NULL;
void insert_at_first()
{
    struct node *newnode;
    int ch;
    while (1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data for new node:");
        scanf("%d", &newnode->data);
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            head->pre = newnode;
            newnode->next = head;
            head = newnode;
            head->pre = NULL;
        }
        printf("Enter the choice 1 to continue and 0 to break :");
        scanf("%d", &ch);
        if (ch == 0)
        {
            break;
        }
    }
}
void traverse()
{
    struct node *t;
    t = head;
    while (t != NULL)
    {
        printf("%d\t", t->data);
        t = t->next;
    }
}
int main()
{
    insert_at_first();
    traverse();
}