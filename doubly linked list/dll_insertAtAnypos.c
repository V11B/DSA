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
}
void insert()
{
    struct node *newnode, *temp;
    int ch;
    while (1)
    {

        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data for newnode:");
        scanf("%d", &newnode->data);

        if (head == NULL)
        {
            head = temp = newnode;
            newnode->next = NULL;
            newnode->pre = NULL;
        }
        else
        {
            temp->next = newnode;
            newnode->pre = temp;
            temp = newnode;
            newnode->next = NULL;
        }
        printf("Enter the choice 1 to continue or 0 to exit :");
        scanf("%d", &ch);
        if (ch == 0)
        {
            printf("\n Nodes Successfully Added.............\n");
            break;
        }
    }
}
void insert_at_pos(int l)
{
    int ch, p;
    printf("Enter the position :");
    scanf("%d", &p);
    if (l < p)
    {
        printf("Invalid position....");
    }
    else if (p == 1)
    {
        insert_at_first();
    }
    else
    {
        struct node *newnode, *temp = head;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data for new node:");
        scanf("%d", &newnode->data);
        int i = 1;
        while (i < p - 1)
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
    insert();
    insert_at_pos(length());
    traverse();
}