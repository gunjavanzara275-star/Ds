#include <iostream>
using namespace std;

int main()
{
    int arr[100], n = 0;
    int i, choice = 0;

    while(choice != 6)
    {
        cout << "\n\n===== MENU =====";
        cout << "\n1. Create Array";
        cout << "\n2. Traversal";
        cout << "\n3. Insertion";
        cout << "\n4. Deletion";
        cout << "\n5. Search";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if(choice == 1)
        {
            cout << "Enter number of elements: ";
            cin >> n;

            cout << "Enter array elements: ";
            for(i = 0; i < n; i++)
            {
                cin >> arr[i];
            }

            cout << "\nArray Created Successfully!";
            cout << "\nUpdated Array: ";
            for(i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
        }

        else if(choice == 2)
        {
            if(n == 0)
            {
                cout << "Array is empty. Please create the array first.";
            }
            else
            {
                cout << "\nArray Elements: ";
                for(i = 0; i < n; i++)
                {
                    cout << arr[i] << " ";
                }
            }
        }

        else if(choice == 3)
        {
            int value, pos;

            cout << "Enter value to insert: ";
            cin >> value;

            cout << "Enter position: ";
            cin >> pos;

            for(i = n; i > pos; i--)
            {
                arr[i] = arr[i - 1];
            }

            arr[pos] = value;
            n++;

            cout << "\nElement Inserted Successfully!";
            cout << "\nUpdated Array: ";
            for(i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
        }

        else if(choice == 4)
        {
            int pos;

            cout << "Enter position to delete: ";
            cin >> pos;

            for(i = pos; i < n - 1; i++)
            {
                arr[i] = arr[i + 1];
            }

            n--;

            cout << "\nElement Deleted Successfully!";
            cout << "\nUpdated Array: ";
            for(i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
        }

        else if(choice == 5)
        {
            int key, found = 0;

            cout << "Enter element to search: ";
            cin >> key;

            for(i = 0; i < n; i++)
            {
                if(arr[i] == key)
                {
                    cout << "\nElement Found at Position: " << i;
                    found = 1;
                    break;
                }
            }

            if(found == 0)
            {
                cout << "\nElement Not Found!";
            }

            cout << "\nCurrent Array: ";
            for(i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
        }

        else if(choice == 6)
        {
            cout << "\nProgram Ended Successfully!";
        }

        else
        {
            cout << "\nInvalid Choice!";
        }
    }

    return 0;
}