#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    stack[++top] = value;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char postfix[MAX];
    int values[26] = {0};
    int entered[26] = {0};
    int i;
    char ch;
    int a, b, result;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for (i = 0; i < strlen(postfix); i++)
    {
        ch = postfix[i];

        /* If operand */
        if (isalpha(ch))
        {
            int index = ch - 'A';

            if (entered[index] == 0)
            {
                printf("Enter value of %c: ", ch);
                scanf("%d", &values[index]);

                entered[index] = 1;
            }

            push(values[index]);
        }

        /* If operator */
        else
        {
            b = pop();
            a = pop();

            switch (ch)
            {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    result = a / b;
                    break;

                case '%':
                    result = a % b;
                    break;

                default:
                    printf("Invalid operator!");
                    return 0;
            }

            push(result);
        }
    }

    printf("\nResult = %d", pop());

    return 0;
}