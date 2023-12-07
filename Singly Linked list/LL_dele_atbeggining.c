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
void delete_at_first()
{
    struct node *temp;
    int d;
    temp = head;
    if (head == NULL)
    {
        printf("LL is empty\n");
    }
    else
    {
        head = head->next;
        free(temp);
    }
}
void traverse()
{
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}
int main()
{
    insert();
    delete_at_first();
    traverse();
}