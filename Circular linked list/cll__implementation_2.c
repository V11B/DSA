#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *tail = NULL;
// with head node:
// void insert()
// {
//     struct node *newnode;
//     int choice;
//     while (1)
//     {
//         newnode = (struct node *)malloc(sizeof(struct node));
//         printf("Enter the data for newnode :");
//         scanf("%d", &newnode->data);
//         newnode->next = NULL;
//         if (head == NULL)
//         {
//             head = tail = newnode;
//         }
//         else
//         {
//             tail->next = newnode;
//             tail = newnode;
//         }
//         tail->next = head;
//         printf("Enter the choice :");
//         scanf("%d", &choice);
//         if (choice == 0)
//         {
//             break;
//         }
//     }
// }

// void traverse()
// {
//     struct node *temp;
//     temp = head;
//     while (temp->next != head)
//     {
//         printf("%d\t", temp->data);
//         temp = temp->next;
//     }
//     printf("%d\t", temp->data);
// }
// without head
void insert()
{
    struct node *newnode;
    int choice;
    while (1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data for newnode :");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (tail == NULL)
        {
            tail = newnode;
            tail->next = newnode;
        }
        else
        {
            newnode->next = tail->next;
            tail->next = newnode;
            tail = newnode;
        }
        printf("Enter the choice :");
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
    temp = tail->next;
    while (temp->next != tail->next)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("%d\t", temp->data);
}

int main()
{
    insert();
    traverse();
}