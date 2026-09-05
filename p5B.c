#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue()
{
    int value;

    if ((rear + 1) % MAX == front)
    {
        printf("\nCircular Queue Overflow!");
    }
    else
    {
        printf("\nEnter value: ");
        scanf("%d", &value);

        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX;
        }

        queue[rear] = value;

        printf("\n%d inserted successfully!", value);
    }
}

void dequeue()
{
    if (front == -1)
    {
        printf("\nCircular Queue Underflow!");
    }
    else
    {
        printf("\n%d deleted successfully!", queue[front]);

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("\nCircular Queue is empty!");
    }
    else
    {
        printf("\nCircular Queue elements: ");

        i = front;

        while (1)
        {
            printf("%d ", queue[i]);

            if (i == rear)
                break;

            i = (i + 1) % MAX;
        }
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n\n===== CIRCULAR QUEUE MENU =====");
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