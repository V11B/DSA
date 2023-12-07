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

void delete()
{
    struct node *t;
    if (head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        t = head;
        head = head->next;
        head->pre = NULL;
        t->next = NULL;
        free(t);
    }
}
int main()
{
    insert();
    printf("Before deletion \n");
    traverse();
    delete ();
    printf("After Deletion");
    traverse();
    return 0;
}