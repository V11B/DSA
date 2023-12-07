#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *pre, *next;
};
struct node *head = NULL;
struct node *tail = NULL;
void insert()
{
    int choice;
    while (1)
    {
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data for new node :");
        scanf("%d", &newnode->data);
        if (head == NULL)
        {
            head = tail = newnode;
            head->pre = NULL;
            head->next = NULL;
        }
        else
        {
            tail->next = newnode;
            newnode->pre = tail;
            tail = newnode;
        }
        printf("Enter the choice 0 to break :");
        scanf("%d", &choice);
        if (choice == 0)
        {
            break;
        }
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

void reverse()
{
    struct node *current, *newnode;
    current = head;
    while (current != NULL)
    {
        newnode = current->next;
        current->next = current->pre;
        current->pre = newnode;
        current = newnode;
    }
    current = head;
    head = tail;
    tail = current;
}

int main()
{
    insert();
    printf("Before reverse :\n");
    traverse();
    reverse();
    printf("\nAfter reverse\n");
    traverse();
}