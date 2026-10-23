
#include <stdio.h>

void binarySearch(int a[], int n, int key)
{
    int low, high, mid;
    int found = 0;

    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (a[mid] == key)
        {
            printf("%d found at position %d\n", key, mid + 1);
            found = 1;
            break;
        }
        else if (key < a[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (found == 0)
    {
        printf("%d not found in the array\n", key);
    }
}

int main()
{
    int a[100];
    int n, i, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements in sorted order: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\nEnter value to search: ");
    scanf("%d", &key);

    binarySearch(a, n, key);

    return 0;
}
