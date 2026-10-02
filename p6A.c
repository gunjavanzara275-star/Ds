#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct node *first = NULL;


/* Create a new node */
struct node *create_node(int x)
{
    struct node *temp;

    temp = (struct node *)malloc(sizeof(struct node));

    temp->info = x;
    temp->next = NULL;

    return temp;
}


/* 1. Insert at beginning */
void insert_first(int x)
{
    struct node *t;

    t = create_node(x);

    t->next = first;
    first = t;
}


/* 2. Insert at end */
void insert_last(int x)
{
    struct node *t, *p;

    t = create_node(x);

    if (first == NULL)
    {
        first = t;
    }
    else
    {
        p = first;

        while (p->next != NULL)
        {
            p = p->next;
        }

        p->next = t;
    }
}


/* 3. Insert after a given node */
void insert_after(int value, int x)
{
    struct node *t, *p;

    p = first;

    while (p != NULL)
    {
        if (p->info == value)
        {
            t = create_node(x);

            t->next = p->next;
            p->next = t;

            return;
        }

        p = p->next;
    }

    printf("Given node not found\n");
}


/* 4. Delete first node */
void delete_first()
{
    struct node *temp;

    if (first == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = first;
        first = first->next;

        free(temp);
    }
}


/* 5. Delete last node */
void delete_last()
{
    struct node *p, *temp;

    if (first == NULL)
    {
        printf("List is empty\n");
    }
    else if (first->next == NULL)
    {
        free(first);
        first = NULL;
    }
    else
    {
        p = first;

        while (p->next->next != NULL)
        {
            p = p->next;
        }

        temp = p->next;
        p->next = NULL;

        free(temp);
    }
}


/* 6. Delete node after a given node */
void delete_after(int value)
{
    struct node *p, *temp;

    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }

    p = first;

    while (p != NULL)
    {
        if (p->info == value)
        {
            if (p->next == NULL)
            {
                printf("No node exists after given node\n");
                return;
            }

            temp = p->next;
            p->next = temp->next;

            free(temp);

            return;
        }

        p = p->next;
    }

    printf("Given node not found\n");
}


/* 7. Display all nodes */
void display()
{
    struct node *p;

    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }

    p = first;

    printf("Linked List: ");

    while (p != NULL)
    {
        printf("%d -> ", p->info);
        p = p->next;
    }

    printf("NULL\n");
}


/* Main function */
int main()
{
    int choice, x, value;

    do
    {
        printf("\n--- Singly Linked List ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After Given Node\n");
        printf("4. Delete First Node\n");
        printf("5. Delete Last Node\n");
        printf("6. Delete Node After Given Node\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                insert_first(x);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &x);
                insert_last(x);
                break;

            case 3:
                printf("Enter node value: ");
                scanf("%d", &value);

                printf("Enter new value: ");
                scanf("%d", &x);

                insert_after(value, x);
                break;

            case 4:
                delete_first();
                break;

            case 5:
                delete_last();
                break;

            case 6:
                printf("Enter node value: ");
                scanf("%d", &value);

                delete_after(value);
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 8);

    return 0;
}