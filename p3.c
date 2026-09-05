#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push()
{
    int value;

    if (top == MAX - 1)
    {
        printf("\nStack Overflow!");
    }
    else
    {
        printf("\nEnter value to push: ");
        scanf("%d", &value);

        top++;
        stack[top] = value;

        printf("%d pushed into stack.", value);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow!");
    }
    else
    {
        printf("\n%d popped from stack.", stack[top]);
        top--;
    }
}

void peek()
{
    if (top == -1)
    {
        printf("\nStack is empty!");
    }
    else
    {
        printf("\nTop element is: %d", stack[top]);
    }
}

void display()
{
    int i;

    if (top == -1)
    {
        printf("\nStack is empty!");
    }
    else
    {
        printf("\nStack elements are:\n");

        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n\n===== STACK MENU =====");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("\nProgram Ended Successfully!");
                break;

            default:
                printf("\nInvalid Choice!");
        }

    } while (choice != 5);

    return 0;
}