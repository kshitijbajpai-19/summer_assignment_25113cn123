// WAP to search an element using binary search

#include<iostream>
using namespace std;

int main()
{

    int arr[100], n, key;

    //Input array
    cout << "Enter number of array elements: ";
    cin >> n;

    // Check valid array size input
    if(n <= 0)
    {
        cout << "Invalid array size";
        return 0;
    }
    if(n>100)
    {
        cout << "Array size exceeded";
        return 0;
    }

    cout << "Enter array elements: ";
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    // Sorting array using bubble sort
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j]; 
                arr[j] = arr[j+1];  // Swapping elements
                arr[j+1] = temp;
            }
        }
    }


    // Input element to be searched
    cout << "Enter element to search: ";
    cin >> key;


    // Searching element using binary search
    int low = 0, high = n-1, found = 0;
    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
        {
            cout << "Element found at position: " << mid + 1;
            found = 1;
            return 0;
        }
        else if(key < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << "Element not found";
    return 0;
}    