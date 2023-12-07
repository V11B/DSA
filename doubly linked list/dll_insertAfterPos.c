#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *pre;
};
struct node *head = NULL;
void insert_at_pos(int l)
{
    int ch, p;
    printf("Enter the position :");
    scanf("%d", &p);
    if (l < p)
    {
        printf("Invalid position....");
    }
    else
    {
        struct node *newnode, *temp = head;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data for new node:");
        scanf("%d", &newnode->data);
        int i = 1;
        while (i < p)
        {
            temp = temp->next;
            i++;
        }
        newnode->pre = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->next->pre = newnode;
    }
}
int length()
{
    int count = 0;
    struct node *l;
    l = head;
    while (l != NULL)
    {
        count++;
        l = l->next;
    }
    return count;
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
    insert_at_pos(length());
    traverse();
}