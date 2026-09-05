#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue()
{
    int value;

    if (rear == MAX - 1)
    {
        printf("\nQueue Overflow!");
    }
    else
    {
        printf("\nEnter value: ");
        scanf("%d", &value);

        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = value;

        printf("\n%d inserted successfully!", value);
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("\nQueue Underflow!");
    }
    else
    {
        printf("\n%d deleted successfully!", queue[front]);
        front++;

        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("\nQueue is empty!");
    }
    else
    {
        printf("\nQueue elements: ");

        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n\n===== QUEUE MENU =====");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nProgram Ended Successfully!");
                break;

            default:
                printf("\nInvalid Choice!");
        }

    } while (choice != 4);

    return 0;
}