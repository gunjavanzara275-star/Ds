#include <stdio.h>

int main()
{
    int arr[100], n = 0;
    int i, choice = 0;

    while(choice != 6)
    {
        printf("\n\n===== MENU =====");
        printf("\n1. Create Array");
        printf("\n2. Traversal");
        printf("\n3. Insertion");
        printf("\n4. Deletion");
        printf("\n5. Search");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("Enter number of elements: ");
            scanf("%d", &n);

            printf("Enter array elements: ");
            for(i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }

            printf("\nArray Created Successfully!");
            printf("\nUpdated Array: ");

            for(i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }
        }

        else if(choice == 2)
        {
            if(n == 0)
            {
                printf("Array is empty. Please create the array first.");
            }
            else
            {
                printf("\nArray Elements: ");

                for(i = 0; i < n; i++)
                {
                    printf("%d ", arr[i]);
                }
            }
        }

        else if(choice == 3)
        {
            int value, pos;

            printf("Enter value to insert: ");
            scanf("%d", &value);

            printf("Enter position: ");
            scanf("%d", &pos);

            for(i = n; i > pos; i--)
            {
                arr[i] = arr[i - 1];
            }

            arr[pos] = value;
            n++;

            printf("\nElement Inserted Successfully!");
            printf("\nUpdated Array: ");

            for(i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }
        }

        else if(choice == 4)
        {
            int pos;

            printf("Enter position to delete: ");
            scanf("%d", &pos);

            for(i = pos; i < n - 1; i++)
            {
                arr[i] = arr[i + 1];
            }

            n--;

            printf("\nElement Deleted Successfully!");
            printf("\nUpdated Array: ");

            for(i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }
        }

        else if(choice == 5)
        {
            int key, found = 0;

            printf("Enter element to search: ");
            scanf("%d", &key);

            for(i = 0; i < n; i++)
            {
                if(arr[i] == key)
                {
                    printf("\nElement Found at Position: %d", i);
                    found = 1;
                    break;
                }
            }

            if(found == 0)
            {
                printf("\nElement Not Found!");
            }

            printf("\nCurrent Array: ");

            for(i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }
        }

        else if(choice == 6)
        {
            printf("\nProgram Ended Successfully!");
        }

        else
        {
            printf("\nInvalid Choice!");
        }
    }

    return 0;
}