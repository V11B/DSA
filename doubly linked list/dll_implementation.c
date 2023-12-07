#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *pre;
    struct node *next;
};
struct node *head = NULL;
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
void traverse_front()
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
    traverse_front();
    printf("\nReverse\n");
    return 0;
}