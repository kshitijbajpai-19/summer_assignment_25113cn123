// WAP to intersection of arrays.

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
    int arr1[100], arr2[100], intersectionarr[100], n1, n2;
        
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

    int intersectionsize = 0; //Stores number of element in the intersection array

    // Add common element from both arrays only if it is not already present in intersection array
    for(int i=0; i<n1; i++)
    {
        if(ispresent(arr2, n2, arr1[i]) && !ispresent(intersectionarr, intersectionsize, arr1[i]))
        {
            intersectionarr[intersectionsize] = arr1[i];
            intersectionsize++;
        }
    }

        
    cout << "Intersection of arrays: ";
    for(int i=0; i<intersectionsize; i++)
    {
        cout << intersectionarr[i] << " ";
    }
    return 0;
}