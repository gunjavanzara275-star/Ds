#include <stdio.h>

// Call by Value
void callByValue(int a, int b)
{
    int temp;
    
    temp = a;
    a = b;
    b = temp;
    
    printf("\nInside call by value:");
    printf("\na = %d, b = %d\n", a, b);
}

// Call by Reference
void callByReference(int *a, int *b)
{
    int temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
    
    printf("\nInside call by reference:");
    printf("\na = %d, b = %d\n", *a, *b);
}

int main()
{
    int x, y;
    
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);
    
    printf("\nBefore function call:");
    printf("\nx = %d, y = %d\n", x, y);
    
    callByValue(x, y);
    
    printf("\nAfter call by value:");
    printf("\nx = %d, y = %d\n", x, y);
    
    callByReference(&x, &y);
    
    printf("\nAfter call by reference:");
    printf("\nx = %d, y = %d\n", x, y);
    
    return 0;
}