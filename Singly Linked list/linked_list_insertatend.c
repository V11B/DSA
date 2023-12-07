#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
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
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->next = NULL;
    }
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
    traverse();
}