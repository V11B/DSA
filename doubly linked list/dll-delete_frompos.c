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
int count()
{
    struct node *tempa;
    tempa = head;
    int c;
    while (tempa != NULL)
    {
        c++;
        tempa = tempa->next;
    }
    return c;
}
void delete(int pos)
{
    int i = 1;
    struct node *t;
    t = head;

    if (pos > count())
    {
        printf("Invalid Position");
    }
    else
    {
        while (i < pos)
        {
            t = t->next;
            i++;
        }
        t->pre->next = t->next;
        t->next->pre = t->pre;
        free(t);
    }
}
int main()
{
    insert();
    printf("Before deletion\n");
    traverse();
    delete (3);
    printf("\nAfter Traverse \n");
    traverse();
}
