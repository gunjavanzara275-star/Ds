#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

/* Insert at Beginning */
void insertBeginning()
{
    int value;
    struct Node *newNode;

    printf("Enter value: ");
    scanf("%d", &value);

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = head;
    head = newNode;

    printf("Value %d inserted successfully at beginning!\n", value);
}

/* Insert at End */
void insertEnd()
{
    int value;
    struct Node *newNode, *temp;

    printf("Enter value: ");
    scanf("%d", &value);

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        printf("Value %d inserted successfully at end!\n", value);
        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;

    printf("Value %d inserted successfully at end!\n", value);
}

/* Insert After Given Node */
void insertAfter()
{
    int after, value;
    struct Node *newNode, *temp;

    printf("Enter node value after which to insert: ");
    scanf("%d", &after);

    temp = head;

    while (temp != NULL && temp->data != after)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Node %d not found!\n", after);
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;

    printf("Value %d inserted successfully after %d!\n", value, after);
}

/* Delete First Node */
void deleteFirst()
{
    struct Node *temp;
    int value;

    if (head == NULL)
    {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    temp = head;
    value = temp->data;

    head = head->next;
    free(temp);

    printf("Value %d deleted successfully from beginning!\n", value);
}

/* Delete Last Node */
void deleteLast()
{
    struct Node *temp, *prev;
    int value;

    if (head == NULL)
    {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    if (head->next == NULL)
    {
        value = head->data;
        free(head);
        head = NULL;

        printf("Value %d deleted successfully from end!\n", value);
        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    value = temp->data;

    prev->next = NULL;
    free(temp);

    printf("Value %d deleted successfully from end!\n", value);
}

/* Delete Node After Given Node */
void deleteAfter()
{
    int after, value;
    struct Node *temp, *deleteNode;

    printf("Enter node value after which to delete: ");
    scanf("%d", &after);

    temp = head;

    while (temp != NULL && temp->data != after)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Node %d not found!\n", after);
        return;
    }

    if (temp->next == NULL)
    {
        printf("There is no node after %d to delete!\n", after);
        return;
    }

    deleteNode = temp->next;
    value = deleteNode->data;

    temp->next = deleteNode->next;
    free(deleteNode);

    printf("Value %d deleted successfully after %d!\n", value, after);
}

/* Display All Nodes */
void display()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    temp = head;

    printf("\nLinked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

/* Main Function */
int main()
{
    int choice;

    do
    {
        printf("\n========== SINGLY LINKED LIST ==========\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After Given Node\n");
        printf("4. Delete First Node\n");
        printf("5. Delete Last Node\n");
        printf("6. Delete Node After Given Node\n");
        printf("7. Display All Nodes\n");
        printf("8. Exit\n");
        printf("=========================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertBeginning();
            break;

        case 2:
            insertEnd();
            break;

        case 3:
            insertAfter();
            break;

        case 4:
            deleteFirst();
            break;

        case 5:
            deleteLast();
            break;

        case 6:
            deleteAfter();
            break;

        case 7:
            display();
            break;

        case 8:
            printf("Program ended successfully!\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 8);

    return 0;
}

