#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

void insert()
{
    struct node *new, *temp;
    int choice;
    while (1)
    {
        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data of new node:");
        scanf("%d", &new->data);
        if (head == 0)
        {
            head = temp = new;
            new->next = NULL;
        }
        else
        {
            temp->next = new;
            temp = new;
            new->next = NULL;
        }
        printf("Enter your choice 1 to continue and 0 to exit");
        scanf("%d", &choice);
        if (choice == 0)
        {
            break;
        }
    }
}
void delete_at_pos()
{
    struct node *t, *n;
    int pos;
    printf("Enter the position you want to delete :");
    scanf("%d", &pos);
    head = t;
    if (head == NULL)
    {
        printf("LL is already empty");
    }
    else
    {
        int i = 1;
        while (i < pos - 1)
        {
            t = t->next;
            i++;
        }
        n = t->next;
        t->next = n->next;
        free(n);
    }
}
void traverse()
{
    struct node *tempa;
    tempa = head;
    while (tempa != NULL)
    {
        printf("%d\t", tempa->data);
        tempa = tempa->next;
    }
}
int main()
{
    insert();
    delete_at_pos();
    traverse();
}