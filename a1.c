#include <stdio.h>
#include <stdlib.h>

// Structure of a doubly linked list node
struct node
{
    int info;
    struct node *prev;
    struct node *next;
};

struct node *first = NULL;

// Function to create a new node
struct node* create_node(int value)
{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->info = value;
    newnode->prev = NULL;
    newnode->next = NULL;

    return newnode;
}

// 1. Insert element at any position
void insert_at_position(int value, int position)
{
    struct node *newnode, *p;
    int i;

    newnode = create_node(value);

    // Insert at first position
    if (position == 1)
    {
        newnode->next = first;

        if (first != NULL)
            first->prev = newnode;

        first = newnode;

        printf("Element inserted successfully.\n");
        return;
    }

    // If list is empty
    if (first == NULL)
    {
        printf("Invalid position! List is empty.\n");
        free(newnode);
        return;
    }

    p = first;

    // Move to node before required position
    for (i = 1; i < position - 1 && p->next != NULL; i++)
    {
        p = p->next;
    }

    // Position does not exist
    if (i != position - 1)
    {
        printf("Invalid position!\n");
        free(newnode);
        return;
    }

    newnode->next = p->next;
    newnode->prev = p;

    if (p->next != NULL)
        p->next->prev = newnode;

    p->next = newnode;

    printf("Element inserted successfully.\n");
}

// 2. Delete element from any position
void delete_at_position(int position)
{
    struct node *p;
    int i;

    if (first == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    p = first;

    // Move to required position
    for (i = 1; i < position && p != NULL; i++)
    {
        p = p->next;
    }

    if (p == NULL)
    {
        printf("Invalid position!\n");
        return;
    }

    // If deleting first node
    if (p->prev == NULL)
    {
        first = p->next;

        if (first != NULL)
            first->prev = NULL;
    }
    else
    {
        p->prev->next = p->next;

        if (p->next != NULL)
            p->next->prev = p->prev;
    }

    free(p);

    printf("Element deleted successfully.\n");
}

// 3. Display from Left to Right
void display_left_to_right()
{
    struct node *p;

    if (first == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    p = first;

    printf("Left to Right: ");

    while (p != NULL)
    {
        printf("%d ", p->info);
        p = p->next;
    }

    printf("\n");
}

// 3. Display from Right to Left
void display_right_to_left()
{
    struct node *p;

    if (first == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    p = first;

    // Go to last node
    while (p->next != NULL)
    {
        p = p->next;
    }

    printf("Right to Left: ");

    while (p != NULL)
    {
        printf("%d ", p->info);
        p = p->prev;
    }

    printf("\n");
}

// Main function
int main()
{
    int choice, value, position;

    while (1)
    {
        printf("\n========== DOUBLY LINKED LIST ==========\n");
        printf("1. Insert element at any position\n");
        printf("2. Delete element from any position\n");
        printf("3. Display Left to Right\n");
        printf("4. Display Right to Left\n");
        printf("5. Display in Both Orders\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);

                printf("Enter position: ");
                scanf("%d", &position);

                insert_at_position(value, position);

                printf("\n");
                display_left_to_right();
                display_right_to_left();
                break;

            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);

                delete_at_position(position);

                printf("\n");
                display_left_to_right();
                display_right_to_left();
                break;

            case 3:
                display_left_to_right();
                break;

            case 4:
                display_right_to_left();
                break;

            case 5:
                display_left_to_right();
                display_right_to_left();
                break;

            case 6:
                printf("Program terminated.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}