#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
int count = 0;
void insert_at_position()
{
    struct node *new, *temp;
    int p;
    new = (struct node *)malloc(sizeof(struct node));
    printf("enter the data you want to add in  a node :");
    scanf("%d", &new->data);
    printf("Enter the position at which you want to add node :");
    scanf("%d", &p);
    // if (count < p)
    // {
    //     printf("Invalid position");
    // }
    if (head == NULL)
    {
        head = temp = new;
        new->next = NULL;
    }
    else
    {
        temp = head;
        int i = 1;
        while (i < p)
        {
            temp = temp->next;
            i++;
        }
        new->next = temp->next;
        temp->next = new;
    }
    count++;
}
void insert_at_end()
{
    struct node *new, *temp;
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data for the new node :");
    scanf("%d", &new->data);
    if (head == NULL)
    {
        head = temp = new;
        new->next = NULL;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->next = NULL;
    }
    count++;
}
void traverse()
{
    struct node *temp;
    temp = head;
    while (temp != 0)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}
int main()
{
    insert_at_end();
    insert_at_end();
    insert_at_end();
    insert_at_end();
    insert_at_end();
    insert_at_position();
    traverse();
}