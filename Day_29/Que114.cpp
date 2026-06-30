// WAP to Create a Menu-Driven Array Operations System

#include <iostream>
using namespace std;

int arr[100];
int n = 0;

void menu()
{
    cout << "\nARRAY OPERATIONS SYSTEM\n";
    cout << "1. Create Array\n";
    cout << "2. Display Array\n";
    cout << "3. Insert Element\n";
    cout << "4. Delete Element\n";
    cout << "5. Search Element\n";
    cout << "6. Update Element\n";
    cout << "7. Sort Array\n";
    cout << "8. Find Largest Element\n";
    cout << "9. Find Smallest Element\n";
    cout << "10. Exit\n";
    cout << "Enter your choice: ";
}

void create_array()
{
    cout << "Enter number of elements: ";
    cin >> n;

    if (n < 1 || n > 100)
    {
        cout << "Invalid size.\n";
        n = 0;
        return;
    }

    cout << "Enter " << n << " elements:\n";

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Array created successfully.\n";
}

void display_array()
{
    if (n == 0)
    {
        cout << "Array is empty.\n";
        return;
    }

    cout << "Array Elements: ";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\n";
}

void insert_element()
{
    if (n == 100)
    {
        cout << "Array is full.\n";
        return;
    }

    int pos, value;

    cout << "Enter position (1-" << n + 1 << "): ";
    cin >> pos;

    if (pos < 1 || pos > n + 1)
    {
        cout << "Invalid position.\n";
        return;
    }

    cout << "Enter value: ";
    cin >> value;

    for (int i = n; i >= pos; i--)
        arr[i] = arr[i - 1];

    arr[pos - 1] = value;
    n++;

    cout << "Element inserted successfully.\n";
}

void delete_element()
{
    if (n == 0)
    {
        cout << "Array is empty.\n";
        return;
    }

    int pos;

    cout << "Enter position to delete (1-" << n << "): ";
    cin >> pos;

    if (pos < 1 || pos > n)
    {
        cout << "Invalid position.\n";
        return;
    }

    for (int i = pos - 1; i < n - 1; i++)
        arr[i] = arr[i + 1];

    n--;

    cout << "Element deleted successfully.\n";
}

void search_element()
{
    if (n == 0)
    {
        cout << "Array is empty.\n";
        return;
    }

    int value;
    bool found = false;

    cout << "Enter element to search: ";
    cin >> value;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == value)
        {
            cout << "Element found at position " << i + 1 << "\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Element not found.\n";
}

void update_element()
{
    if (n == 0)
    {
        cout << "Array is empty.\n";
        return;
    }

    int pos, value;

    cout << "Enter position to update (1-" << n << "): ";
    cin >> pos;

    if (pos < 1 || pos > n)
    {
        cout << "Invalid position.\n";
        return;
    }

    cout << "Enter new value: ";
    cin >> value;

    arr[pos - 1] = value;

    cout << "Element updated successfully.\n";
}

void sort_array()
{
    if (n == 0)
    {
        cout << "Array is empty.\n";
        return;
    }

    int ch;
    cout << "1. Sort array in acsending order\n";
    cout << "2. Sort array in descending order\n";
    cout << "Enter your choice: ";
    cin >> ch;

    if (ch == 1)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    else if (ch == 2)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] < arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
    else
    {
        cout << "Invalid choice!";
        return;
    }
    cout << "Array sorted successfully.\n";
}

void largest_element()
{
    if (n == 0)
    {
        cout << "Array is empty.\n";
        return;
    }

    int largest = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
            largest = arr[i];
    }

    cout << "Largest Element = " << largest << "\n";
}

void smallest_element()
{
    if (n == 0)
    {
        cout << "Array is empty.\n";
        return;
    }

    int smallest = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < smallest)
            smallest = arr[i];
    }

    cout << "Smallest Element = " << smallest << "\n";
}

int main()
{
    int choice;

    do
    {
        menu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            create_array();
            break;

        case 2:
            display_array();
            break;

        case 3:
            insert_element();
            break;

        case 4:
            delete_element();
            break;

        case 5:
            search_element();
            break;

        case 6:
            update_element();
            break;

        case 7:
            sort_array();
            break;

        case 8:
            largest_element();
            break;

        case 9:
            smallest_element();
            break;

        case 10:
            cout << "Exiting Program\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 10);

    return 0;
}