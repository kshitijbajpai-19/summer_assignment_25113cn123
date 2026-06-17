// WAP to sort an array using bubble sort

#include<iostream>
using namespace std;

int main()
{

    int arr[100], n;

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

    // Display sorted array
    cout << "Sorted array: ";
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}