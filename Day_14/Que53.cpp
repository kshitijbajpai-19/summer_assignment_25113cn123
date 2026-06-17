// WAP to search an array element using linear search.

#include<iostream>
using namespace std;

int main()
{
    int arr[100], n, key;

    cout << "Enter number of array elements: ";
    cin >> n;
    
    if(n<=0)
    {
        cout << "Invalid array size";
        return 0;
    }
    cout << "Enter array elements: ";
    for(int i=0; i<n; i++)
    {
            cin >> arr[i];
    }
    
    cout << "Enter element to search: ";
    cin >> key;
    
    for(int i=0; i<n; i++)
    {
        if(key==arr[i])
        {
            cout << "Element found at " << i << " index position";
            return 0;
        }
    }

    cout << "Element not found";
    return 0;
}