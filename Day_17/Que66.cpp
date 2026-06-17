// WAP to union of arrays.

#include<iostream>
using namespace std;

// Function to check whether an element is already present in an array
int ispresent(int arr[], int size, int x)
{
    for(int i=0; i<size; i++)
    {
        if(arr[i] == x)
            return 1;
    }
    return 0;
}

int main()
{
    int arr1[100], arr2[100], unionarr[200], n1, n2;
        
    cout << "Enter number of elements in first array: ";
    cin >> n1;
    if(n1<=0)
    {
        cout << "Invalid array size";
        return 0;
    }

    cout << "Enter first array elements: ";
    for(int i=0; i<n1; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter number of elements in second array: ";
    cin >> n2;

    if(n2<=0)
    {
        cout << "Invalid array size";
        return 0;
    }

    cout << "Enter second array elements: ";
    for(int i=0; i<n2; i++)
    {
        cin >> arr2[i];
    }

    int unionsize = 0; // Stores number of element in the union array


    // Add unique elements from the first array to the union array
    for(int i=0; i<n1; i++)
    {
        if(!ispresent(unionarr, unionsize, arr1[i]))
        {
            unionarr[unionsize] = arr1[i];
            unionsize++;
        }
    }

    // Add unique elements from the second array to the union array
    for(int i=0; i<n2; i++)
    {
        if(!ispresent(unionarr, unionsize, arr2[i]))
        {
            unionarr[unionsize] = arr2[i];
            unionsize++;
        }
    } 

        
    cout << "Union of arrays: ";
    for(int i=0; i<unionsize; i++)
    {
        cout << unionarr[i] << " ";
    }
    return 0;
}