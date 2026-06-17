// WAP to merge arrays

#include<iostream>
using namespace std;

int main()
{
    int arr1[100], arr2[100], merged[200], n1, n2;
    
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

    for(int i=0; i<n1; i++)
    {
        merged[i] = arr1[i];
    }
    for(int i=0; i<n2; i++)
    { 
        merged[i+n1] = arr2[i];
    }

    cout << "Merged array: ";
    for(int i=0; i<n1+n2; i++)
    {
        cout << merged[i] << " ";
    }   
    return 0;

}   