#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *last = NULL;

// Insert at beginning
void insertBeginning(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;

    if (last == NULL)
    {
        last = newNode;
        newNode->next = last;
    }
    else
    {
        newNode->next = last->next;
        last->next = newNode;
    }

    printf("Node inserted at beginning.\n");
}

// Insert at end
void insertEnd(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;

    if (last == NULL)
    {
        last = newNode;
        newNode->next = last;
    }
    else
    {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }

    printf("Node inserted at end.\n");
}

// Insert after a given node
void insertAfter(int key, int value)
{
    if (last == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = last->next;

    do
    {
        if (temp->data == key)
        {
            struct Node *newNode =
                (struct Node *)malloc(sizeof(struct Node));

            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;

            if (temp == last)
                last = newNode;

            printf("Node inserted after %d.\n", key);
            return;
        }

        temp = temp->next;

    } while (temp != last->next);

    printf("Given node not found.\n");
}

// Delete first node
void deleteFirst()
{
    if (last == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *first = last->next;

    if (first == last)
    {
        last = NULL;
    }
    else
    {
        last->next = first->next;
    }

    free(first);

    printf("First node deleted.\n");
}

// Delete last node
void deleteLast()
{
    if (last == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = last->next;

    if (temp == last)
    {
        free(last);
        last = NULL;
    }
    else
    {
        while (temp->next != last)
        {
            temp = temp->next;
        }

        temp->next = last->next;
        free(last);
        last = temp;
    }

    printf("Last node deleted.\n");
}

// Delete node after a given node
void deleteAfter(int key)
{
    if (last == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = last->next;

    do
    {
        if (temp->data == key)
        {
            struct Node *del = temp->next;

            // Only one node
            if (del == temp)
            {
                last = NULL;
            }
            else
            {
                temp->next = del->next;

                if (del == last)
                    last = temp;
            }

            free(del);

            printf("Node after %d deleted.\n", key);
            return;
        }

        temp = temp->next;

    } while (temp != last->next);

    printf("Given node not found.\n");
}

// Display list
void display()
{
    if (last == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = last->next;

    printf("Circular Linked List: ");

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("(back to first node)\n");
}

// Main function
int main()
{
    int choice, value, key;

    do
    {
        printf("\n--- SINGLY CIRCULAR LINKED LIST ---\n");
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
            scanf("%d", &value);
            insertBeginning(value);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertEnd(value);
            break;

        case 3:
            printf("Enter node after which to insert: ");
            scanf("%d", &key);

            printf("Enter value: ");
            scanf("%d", &value);

            insertAfter(key, value);
            break;

        case 4:
            deleteFirst();
            break;

        case 5:
            deleteLast();
            break;

        case 6:
            printf("Enter node after which to delete: ");
            scanf("%d", &key);

            deleteAfter(key);
            break;

        case 7:
            display();
            break;

        case 8:
            printf("Program terminated.\n");
            break;

        default:
            printf("Invalid choice.\n");
        }

    } while (choice != 8);

    return 0;
}