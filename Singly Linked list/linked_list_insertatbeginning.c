#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void insert_at_beginning()
{
    struct node *new, *temp;
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data you want to enter in new node :");
    scanf("%d", &new->data);
    if (head == NULL)
    {
        head = new;
        new->next = NULL;
    }
    else
    {
        new->next = head;
        head = new;
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
    insert_at_beginning();
    traverse();
}