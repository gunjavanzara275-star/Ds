#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct node *first = NULL;


/* Function to create a new node */
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
    struct node *t, *p;

    t = create_node(x);

    if (first == NULL)
    {
        first = t;
        t->next = first;
    }
    else
    {
        p = first;

        while (p->next != first)
        {
            p = p->next;
        }

        t->next = first;
        p->next = t;
        first = t;
    }

    printf("%d inserted at beginning.\n", x);
}


/* 2. Insert at end */
void insert_last(int x)
{
    struct node *t, *p;

    t = create_node(x);

    if (first == NULL)
    {
        first = t;
        t->next = first;
    }
    else
    {
        p = first;

        while (p->next != first)
        {
            p = p->next;
        }

        p->next = t;
        t->next = first;
    }

    printf("%d inserted at end.\n", x);
}


/* 3. Insert after a given node */
void insert_after(int value, int x)
{
    struct node *t, *p;

    if (first == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    p = first;

    do
    {
        if (p->info == value)
        {
            t = create_node(x);

            t->next = p->next;
            p->next = t;

            printf("%d inserted after %d.\n", x, value);
            return;
        }

        p = p->next;

    } while (p != first);

    printf("Given node %d not found.\n", value);
}


/* 4. Delete first node */
void delete_first()
{
    struct node *p, *temp;

    if (first == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    /* Only one node */
    if (first->next == first)
    {
        printf("%d deleted from beginning.\n", first->info);

        free(first);
        first = NULL;
    }
    else
    {
        p = first;

        while (p->next != first)
        {
            p = p->next;
        }

        temp = first;

        first = first->next;
        p->next = first;

        printf("%d deleted from beginning.\n", temp->info);

        free(temp);
    }
}


/* 5. Delete last node */
void delete_last()
{
    struct node *p, *temp;

    if (first == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    /* Only one node */
    if (first->next == first)
    {
        printf("%d deleted from end.\n", first->info);

        free(first);
        first = NULL;
    }
    else
    {
        p = first;

        while (p->next->next != first)
        {
            p = p->next;
        }

        temp = p->next;

        p->next = first;

        printf("%d deleted from end.\n", temp->info);

        free(temp);
    }
}


/* 6. Delete node after a given node */
void delete_after(int value)
{
    struct node *p, *temp;

    if (first == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    p = first;

    do
    {
        if (p->info == value)
        {
            /* Only one node */
            if (p->next == p)
            {
                printf("No node available after %d.\n", value);
                return;
            }

            temp = p->next;

            /* If deleting the first node */
            if (temp == first)
            {
                first = first->next;
            }

            p->next = temp->next;

            printf("%d deleted after %d.\n", temp->info, value);

            free(temp);

            return;
        }

        p = p->next;

    } while (p != first);

    printf("Given node %d not found.\n", value);
}


/* 7. Display all nodes */
void display()
{
    struct node *p;

    if (first == NULL)
    {
        printf("Circular Linked List: EMPTY\n");
        return;
    }

    p = first;

    printf("Circular Linked List: ");

    do
    {
        printf("%d -> ", p->info);
        p = p->next;

    } while (p != first);

    printf("(back to first)\n");
}


/* Main function */
int main()
{
    int choice;
    int x, value;

    do
    {
        printf("\n========================================\n");
        printf("       SINGLY CIRCULAR LINKED LIST\n");
        printf("========================================\n");

        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After Given Node\n");
        printf("4. Delete First Node\n");
        printf("5. Delete Last Node\n");
        printf("6. Delete Node After Given Node\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);


        switch (choice)
        {
            /* Insert at beginning */
            case 1:

                printf("Enter value: ");
                scanf("%d", &x);

                insert_first(x);

                /* Automatically display */
                display();

                break;


            /* Insert at end */
            case 2:

                printf("Enter value: ");
                scanf("%d", &x);

                insert_last(x);

                /* Automatically display */
                display();

                break;


            /* Insert after given node */
            case 3:

                printf("Enter node value after which to insert: ");
                scanf("%d", &value);

                printf("Enter new value: ");
                scanf("%d", &x);

                insert_after(value, x);

                /* Automatically display */
                display();

                break;


            /* Delete first node */
            case 4:

                delete_first();

                /* Automatically display */
                display();

                break;


            /* Delete last node */
            case 5:

                delete_last();

                /* Automatically display */
                display();

                break;


            /* Delete node after given node */
            case 6:

                printf("Enter node value after which to delete: ");
                scanf("%d", &value);

                delete_after(value);

                /* Automatically display */
                display();

                break;


            /* Display */
            case 7:

                display();

                break;


            /* Exit */
            case 8:

                printf("\nProgram ended.\n");

                break;


            default:

                printf("Invalid choice!\n");
        }

    } while (choice != 8);


    return 0;
}